/*
 * custom_syscalls.c
 *
 *  Created on: May 13, 2025
 *      Author: marcv
 */


#include <sys/time.h> // For struct timeval
#include <sys/reent.h> // For struct _reent, if _gettimeofday_r is the one explicitly called

// Provide a weak stub for _gettimeofday_r.
// The __attribute__((weak)) allows a user-defined or library-defined
// version to override this one if available, but for bare-metal, this usually becomes the one.
__attribute__((weak)) int _gettimeofday_r(struct _reent *r, struct timeval *tv, void *tz) {
    (void)r;  // Mark as unused
    (void)tz; // Mark as unused (timezone is often not used in embedded)

    if (tv) {
        tv->tv_sec = 0;  // Default to 0 seconds since epoch
        tv->tv_usec = 0; // Default to 0 microseconds
        // If you have an RTC, you could potentially read it here and populate tv.
    }
    // Return 0 for success.
    // Alternatively, you could return -1 and set errno to ENOSYS if you want to signal that it's not truly implemented.
    // For now, returning 0 with zeroed time is common to silence warnings.
    return 0;
}

// It's also good to provide a stub for the non-reentrant version _gettimeofday,
// as some parts of the library might call this one directly.
__attribute__((weak)) int _gettimeofday(struct timeval *tv, void *tz) {
    (void)tz; // Mark as unused

    if (tv) {
        tv->tv_sec = 0;
        tv->tv_usec = 0;
    }
    return 0;
}
