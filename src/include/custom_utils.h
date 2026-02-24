#ifndef __INCLUDE_CUSTOM_UTILS_H
#define __INCLUDE_CUSTOM_UTILS_H

#include <ctime>
#include <cstdint>
#include <system_error>
#include <string>


namespace custom_utils
{

/* Returns the current monotnic time in nanoseconds */
inline int64_t get_time()
{
	struct timespec ts;
	if (clock_gettime(CLOCK_MONOTONIC, &ts) < 0)
		throw std::system_error(errno, std::generic_category(), "clock_gettime");

	return ts.tv_nsec + ts.tv_sec * 1000000000ULL;
}

inline std::string format_time(int64_t t)
{
	char buf[64];
	snprintf(buf, sizeof(buf), "%es", t * 1e-9);
	buf[sizeof(buf) - 1] = '\0';
	return std::string(buf);
}

}

#endif /* __INCLUDE_CUSTOM_UTILS_H */
