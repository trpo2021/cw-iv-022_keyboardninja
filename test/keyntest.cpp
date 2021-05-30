#include "../thirdparty/ctest.h"
#include "../src/keynlibs/mainlib.hpp"

// TEST #1
CTEST(status_arr, true_status)
{
    CTEST_LOG("COMPARE_CHECK");

    const int rez = 1;
    int add = 0;

    char str1[6] = "check";
    char str2[6] = "check";

    scompare(str1, str2, ENG, &add);

    ASSERT_EQUAL(rez, 1);
}