#include "millis.h"

#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <assert.h>

uint64_t millis() {
    struct timeval tv;
    assert(0 == gettimeofday(&tv, NULL));
    return ((tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}