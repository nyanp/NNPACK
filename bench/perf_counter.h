#pragma once

#include <stddef.h>
#include <stdbool.h>

#if defined(__linux__)
	#include <time.h>
	#include <unistd.h>
	#include <sys/ioctl.h>
	#include <linux/perf_event.h>
#elif defined(__native_client__)
	#include <sys/time.h>
#else
	#if defined(__MACH__)
		#include <mach/mach.h>
		#include <mach/mach_time.h>
	#endif
	#if defined(__x86_64__)
		#include <x86intrin.h>
	#endif
#endif

struct performance_counter {
	const char* name;
	int file_descriptor;
};

inline bool enable_perf_counter(int file_descriptor) {
#if defined(__linux__)
	return ioctl(file_descriptor, PERF_EVENT_IOC_ENABLE, 0) == 0;
#else
	return true;
#endif
}

inline bool disable_perf_counter(int file_descriptor) {
#if defined(__linux__)
	return ioctl(file_descriptor, PERF_EVENT_IOC_DISABLE, 0) == 0;
#else
	return true;
#endif
}

inline bool read_perf_counter(int file_descriptor, unsigned long long output[restrict static 1]) {
#if defined(__linux__)
	return read(file_descriptor, output, sizeof(*output)) == sizeof(*output);
#elif defined(__native_client__) && !defined(__x86_64__)
	return false;
#elif defined(__native_client__)
	unsigned int lo, hi;
	asm volatile(
		"XORL %%eax, %%eax;"
		"CPUID;"
		"RDTSC;"
		: "=a" (lo), "=d" (hi)
		:
		: "%rbx", "%rcx"
	);
	*output = (((unsigned long long) hi) << 32) | ((unsigned long long) lo);
	return true;
#else
	unsigned int aux;
	*output = __rdtscp(&aux);
	return true;
#endif
}

inline static bool read_timer(unsigned long long output[restrict static 1]) {
#if defined(__linux__)
	struct timespec ts;
	if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
		return false;
	} else {
		*output = ts.tv_sec * 1000000000ull + ts.tv_nsec;
		return true;
	}
#elif defined(__MACH__)
	static mach_timebase_info_data_t timebase_info;
	if (timebase_info.denom == 0) {
		mach_timebase_info(&timebase_info);
	}

	*output = mach_absolute_time() * timebase_info.numer / timebase_info.denom;
	return true;
#elif defined(__native_client__)
	struct timeval walltime;
	if (gettimeofday(&walltime, NULL) == 0) {
		*output = walltime.tv_sec * 1000000000ull + walltime.tv_usec * 1000ull;
		return true;
	} else {
		return false;
	}
#else
	#error No implementation available
#endif
}

#if defined(__linux__)
const struct performance_counter* init_performance_counters(size_t* count_ptr);
#else
static inline const struct performance_counter* init_performance_counters(size_t* count_ptr) {
	static const struct performance_counter performance_counter = {
		.name = "Cycles"
	};
	*count_ptr = 1;
	return &performance_counter;
}
#endif
