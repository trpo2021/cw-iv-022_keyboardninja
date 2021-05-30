#include "../thirdparty/ctest.h"
#include "../src/keynlibs/mainlib.hpp"

// TEST #1
CTEST(scompare_test, true_status)
{
    CTEST_LOG("COMPARE_CHECK");
    CTEST_LOG("TRUE_STAT_CHECK");

    int add = 0;
    int fails = 0;

    char str1[6] = "check";
    char str2[6] = "check";
    char req[6] = "check";
    char ans[6] = "check";

    scompare(str1, str2, ENG, &add);
    const int rez = scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(rez, 1);
    ASSERT_EQUAL(1, rez);
}
// TEST #2
CTEST(scompare_test, false_status1)
{
    CTEST_LOG("FALSE_STAT_CHECK(ANS_LONGER");

    int fails = 0;

    char req[6] = "check";
    char ans[7] = "checkk";

    const int rez = scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(0, rez);
}
// TEST #3
CTEST(scompare_test, false_status2)
{
    CTEST_LOG("FALSE_STAT_CHECK(ANS_LESS)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "chec";

    const int rez = scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(0, rez);
}
// TEST #4
CTEST(scompare_test, false_status3)
{
    CTEST_LOG("FALSE_STAT_CHECK(SYM_SPECIALS)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "\n";

    const int rez = scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(0, rez);
}
// TEST #5
CTEST(scompare_test, false_status4)
{
    CTEST_LOG("FALSE_STAT_CHECK(SYM_DIGIT)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "12345";

    const int rez = scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(0, rez);
}
// TEST #6
CTEST(scompare_test, false_status5)
{
    CTEST_LOG("FALSE_STAT_CHECK(EN-RU)");

    int fails = 0;

    char req[6] = "check";
    char ans[13] = "привет";

    const int rez = scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(0, rez);
}
// TEST #7
CTEST(scompare_test, trueru_status1)
{
    CTEST_LOG("TRUE_RU_STAT_CHECK");

    int fails = 0;

    char req[13] = "привет";
    char ans[13] = "привет";

    int rez = scompare(req, ans, RU, &fails);

    ASSERT_EQUAL(1, rez);
}
// TEST #8
CTEST(scompare_test, trueru_status2)
{
    CTEST_LOG("FALSE_RU_STAT_CHECK");

    int fails = 0;

    char req[13] = "привет";
    char ans[13] = "привед";

    int rez = scompare(req, ans, RU, &fails);

    ASSERT_EQUAL(0, rez);
}
// TEST #9
CTEST(scompare_test, caps_status1)
{
    CTEST_LOG("CAPS_STAT_CHECK");

    int fails = 0;

    char req[6] = "HELLO";
    char ans[6] = "HELLO";

    int rez = scompare(req, ans, RU, &fails);

    ASSERT_EQUAL(1, rez);
}
// TEST #10
CTEST(scompare_test, caps_status2)
{
    CTEST_LOG("CAPS_RU_STAT_CHECK");

    int fails = 0;

    char req[13] = "ПРИВЕТ";
    char ans[13] = "ПРИВЕТ";

    int rez = scompare(req, ans, RU, &fails);

    ASSERT_EQUAL(1, rez);
}
// TEST #11
CTEST(scompare_test, fails_count1)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(0)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "check";

    scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(0, fails);
}
// TEST #12
CTEST(scompare_test, fails_count2)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(1)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "chect";

    scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(1, fails);
}
// TEST #13
CTEST(scompare_test, fails_count3)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(SEPCIALS)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = " ";

    scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(5, fails);
}
// TEST #14
CTEST(scompare_test, fails_count4)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(ANS_LONGER(1))");

    int fails = 0;

    char req[6] = "check";
    char ans[8] = "checke";

    scompare(req, ans, ENG, &fails);

    ASSERT_EQUAL(1, fails);
}
// TEST #15
CTEST(scompare_test, fails_count5)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(RU-EN)");

    int fails = 0;

    char req[13] = "привет";
    char ans[6] = "check";

    scompare(req, ans, RU, &fails);

    ASSERT_EQUAL(1, fails);
}