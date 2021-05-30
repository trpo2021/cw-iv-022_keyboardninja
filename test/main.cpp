#include <stdio.h>

#define CTEST_MAIN

#define CTEST_SEGFAULT
//#define CTEST_NO_COLORS
#define CTEST_COLOR_OK

#include "../thirdparty/ctest.h"
#include "../src/keynlibs/mainlib.hpp"

int main(int argc, const char *argv[])
{
    return ctest_main(argc, argv);
}