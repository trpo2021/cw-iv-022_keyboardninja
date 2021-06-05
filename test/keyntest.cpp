#include "../src/keynlibs/mainlib.hpp"
#include "../thirdparty/ctest.h"

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

    bool* status = (bool*)calloc(6, sizeof(bool));

    scompare(str1, str2, ENG, &add, &status);
    const int rez = scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(rez, 1);
    ASSERT_EQUAL(1, rez);

    free(status);
}
// TEST #2
CTEST(scompare_test, false_status1)
{
    CTEST_LOG("FALSE_STAT_CHECK(ANS_LONGER");

    int fails = 0;

    char req[6] = "check";
    char ans[7] = "checkk";

    bool* status = (bool*)calloc(7, sizeof(bool));

    const int rez = scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(2, rez);

    free(status);
}
// TEST #3
CTEST(scompare_test, false_status2)
{
    CTEST_LOG("FALSE_STAT_CHECK(ANS_LESS)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "chec";

    bool* status = (bool*)calloc(7, sizeof(bool));

    const int rez = scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(0, rez);

    free(status);
}
// TEST #4
CTEST(scompare_test, false_status3)
{
    CTEST_LOG("FALSE_STAT_CHECK(SYM_SPECIALS)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "\n";

    bool* status = (bool*)calloc(6, sizeof(bool));

    const int rez = scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(0, rez);

    free(status);
}
// TEST #5
CTEST(scompare_test, false_status4)
{
    CTEST_LOG("FALSE_STAT_CHECK(SYM_DIGIT)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "12345";

    bool* status = (bool*)calloc(6, sizeof(bool));

    const int rez = scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(0, rez);

    free(status);
}
// TEST #6
CTEST(scompare_test, false_status5)
{
    CTEST_LOG("FALSE_STAT_CHECK(EN-RU)");

    int fails = 0;

    char req[6] = "check";
    char ans[13] = "привет";

    bool* status = (bool*)calloc(13, sizeof(bool));

    const int rez = scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(0, rez);

    free(status);
}
// TEST #7
CTEST(scompare_test, trueru_status1)
{
    CTEST_LOG("TRUE_RU_STAT_CHECK");

    int fails = 0;

    char req[13] = "привет";
    char ans[13] = "привет";

    bool* status = (bool*)calloc(13, sizeof(bool));

    int rez = scompare(req, ans, RU, &fails, &status);

    ASSERT_EQUAL(1, rez);

    free(status);
}
// TEST #8
CTEST(scompare_test, trueru_status2)
{
    CTEST_LOG("FALSE_RU_STAT_CHECK");

    int fails = 0;

    char req[13] = "привет";
    char ans[13] = "привед";

    bool* status = (bool*)calloc(13, sizeof(bool));

    int rez = scompare(req, ans, RU, &fails, &status);

    ASSERT_EQUAL(0, rez);

    free(status);
}
// TEST #9
CTEST(scompare_test, caps_status1)
{
    CTEST_LOG("CAPS_STAT_CHECK");

    int fails = 0;

    char req[6] = "HELLO";
    char ans[6] = "HELLO";

    bool* status = (bool*)calloc(6, sizeof(bool));

    int rez = scompare(req, ans, RU, &fails, &status);

    ASSERT_EQUAL(1, rez);

    free(status);
}
// TEST #10
CTEST(scompare_test, caps_status2)
{
    CTEST_LOG("CAPS_RU_STAT_CHECK");

    int fails = 0;

    char req[13] = "ПРИВЕТ";
    char ans[13] = "ПРИВЕТ";

    bool* status = (bool*)calloc(13, sizeof(bool));

    int rez = scompare(req, ans, RU, &fails, &status);

    ASSERT_EQUAL(1, rez);

    free(status);
}
// TEST #11
CTEST(scompare_test, fails_count1)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(0)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "check";

    bool* status = (bool*)calloc(6, sizeof(bool));

    scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(0, fails);

    free(status);
}
// TEST #12
CTEST(scompare_test, fails_count2)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(1)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = "chect";

    bool* status = (bool*)calloc(6, sizeof(bool));

    scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(1, fails);

    free(status);
}
// TEST #13
CTEST(scompare_test, fails_count3)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(SEPCIALS)");

    int fails = 0;

    char req[6] = "check";
    char ans[6] = " ";

    bool* status = (bool*)calloc(6, sizeof(bool));

    scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(5, fails);

    free(status);
}
// TEST #14
CTEST(scompare_test, fails_count4)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(ANS_LONGER(1))");

    int fails = 0;

    char req[6] = "check";
    char ans[7] = "checke";

    bool* status = (bool*)calloc(7, sizeof(bool));

    scompare(req, ans, ENG, &fails, &status);

    ASSERT_EQUAL(1, fails);

    free(status);
}
// TEST #15
CTEST(scompare_test, fails_count5)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(RU-EN)");

    int fails = 0;

    char req[13] = "привет";
    char ans[13] = "check";

    bool* status = (bool*)calloc(13, sizeof(bool));

    scompare(req, ans, RU, &fails, &status);

    ASSERT_EQUAL(12, fails);

    free(status);
}
// TEST #15.1
CTEST(scompare_test, fails_count6)
{
    CTEST_LOG("FAILS_COUNTER_CHECK(EN-RU)");

    int fails = 0;

    char req[6] = "check";
    char ans[13] = "привет";

    bool* status = (bool*)calloc(13, sizeof(bool));

    scompare(req, ans, RU, &fails, &status);

    ASSERT_EQUAL(5, fails);

    free(status);
}
// TEST #16
CTEST(slen_test, symcounting_en)
{
    CTEST_LOG("SYMCOUNTING_EN");

    char str[6] = "check";

    int rez = slen(str);

    ASSERT_EQUAL(5, rez);
}
// TEST #17
CTEST(slen_test, symcounting_en2)
{
    CTEST_LOG("SYMCOUNTING_EN(Space)");

    char str[12] = "hello world";

    int rez = slen(str);

    ASSERT_EQUAL(11, rez);
}
// TEST #18
CTEST(slen_test, symcounting_en3)
{
    CTEST_LOG("SYMCOUNTING_EN(NewlineCharacter)");

    char str[12] = "\n";

    int rez = slen(str);

    ASSERT_EQUAL(1, rez);
}
// TEST #19
CTEST(slen_test, symcounting_en4)
{
    CTEST_LOG("SYMCOUNTING_EN(TabCharacter)");

    char str[12] = "\t";

    int rez = slen(str);

    ASSERT_EQUAL(1, rez);
}
// TEST #20
CTEST(slen_test, symcounting_ru1)
{
    CTEST_LOG("SYMCOUNTING_EN(TabCharacter)");

    char str[12] = "текст";

    int rez = slen(str);

    ASSERT_EQUAL(10, rez);
}
// TEST #21
CTEST(slen_test, symcounting_ru2)
{
    CTEST_LOG("SYMCOUNTING_EN(RuWithSpaces)");

    char str[33] = "текст с пробелами";

    int rez = slen(str);

    ASSERT_EQUAL(32, rez);
}
// TEST #22
CTEST(slen_test, symcounting_ru3)
{
    CTEST_LOG("SYMCOUNTING_EN(RuWithSpaces&Specials)");

    char str[86] = "текст с пробелами\tи специальными символами";

    int rez = slen(str);

    ASSERT_EQUAL(79, rez);
}
// TEST #23
CTEST(slen_test, symcounting_ruen)
{
    CTEST_LOG("SYMCOUNTING_EN(RuEn)");

    char str[35] = "текст with мороженка";

    int rez = slen(str);

    ASSERT_EQUAL(34, rez);
}
// TEST #24
CTEST(slen_test, symcounting_ruens)
{
    CTEST_LOG("SYMCOUNTING_EN(RuEnSpecials)");

    char str[36] = "текст\nwith \tмороженка";

    int rez = slen(str);

    ASSERT_EQUAL(35, rez);
}
// TEST #25
CTEST(lencount_test, characters_counting_en1)
{
    CTEST_LOG("CHARACTERS_COUNTING_EN");

    char* arr[5];
    arr[0] = (char*)"zero";
    arr[1] = (char*)"one";
    arr[2] = (char*)"two";
    arr[3] = (char*)"three";
    arr[4] = (char*)"four";

    int rez = lencount(arr, 5);

    ASSERT_EQUAL(19, rez);
}
// TEST #26
CTEST(lencount_test, characters_counting_en2)
{
    CTEST_LOG("CHARACTERS_COUNTING_EN(WithSpecs)");

    char* arr[5];

    arr[0] = (char*)"zero \t with specs";
    arr[1] = (char*)"one uiiii";
    arr[2] = (char*)"two nice";
    arr[3] = (char*)"three perfecto";
    arr[4] = (char*)"four perfavore";

    int rez = lencount(arr, 5);

    ASSERT_EQUAL(62, rez);
}
// TEST #27
CTEST(lencount_test, characters_counting_ru1)
{
    CTEST_LOG("CHARACTERS_COUNTING_RU");

    char* arr[5];

    arr[0] = (char*)"ноль";
    arr[1] = (char*)"один уиии";
    arr[2] = (char*)"два\n";
    arr[3] = (char*)"три перфекто";
    arr[4] = (char*)"четыре перфаворе";

    int rez = lencount(arr, 5);

    ASSERT_EQUAL(86, rez);
}

CTEST(counting, persent_test_1)
{
    double rez = 0;

    int sim = 100;
    int fails = 1;

    rez = count_percent_miss(fails, sim);

    ASSERT_EQUAL(1, rez);
}

CTEST(counting, persent_test_2)
{
    double rez = 0;

    int sim = 100;
    int fails = 50;

    rez = count_percent_miss(fails, sim);

    ASSERT_EQUAL(50, rez);
}

CTEST(counting, persent_test_3)
{
    double rez = 0;

    int sim = 100;
    int fails = 100;

    rez = count_percent_miss(fails, sim);

    ASSERT_EQUAL(100, rez);
}

CTEST(counting, persent_test_4)
{
    double rez = 0;

    int sim = 100;
    int fails = 200;

    rez = count_percent_miss(fails, sim);

    ASSERT_EQUAL(-1, rez);
}

CTEST(counting, count_coefficient_miss_1)
{
    double rez = 0;

    double persent = 50;

    rez = count_coefficient_miss(persent);

    ASSERT_EQUAL(0.5, rez);
}

CTEST(counting, count_coefficient_miss_2)
{
    double rez = 0;

    double persent = 30;

    rez = count_coefficient_miss(persent);

    ASSERT_EQUAL(0.3, rez);
}

CTEST(counting, count_coefficient_miss_3)
{
    double rez = 0;

    double persent = 110;

    rez = count_coefficient_miss(persent);

    ASSERT_EQUAL(-1, rez);
}

CTEST(counting, count_coefficient_miss_4)
{
    double rez = 0;

    double persent = 1;

    rez = count_coefficient_miss(persent);

    ASSERT_EQUAL(0.01, rez);
}

CTEST(counting, speed_print_0)
{
    double rez = 0;

    int time = 10;

    int sym = 100;

    rez = speed_print(sym, time);

    ASSERT_EQUAL(10, rez);
}

CTEST(counting, speed_print_1)
{
    double rez = 0;

    int time = 50;

    int sym = 100;

    rez = speed_print(sym, time);

    ASSERT_EQUAL(2, rez);
}

CTEST(counting, speed_print_2)
{
    double rez = 0;

    int time = 100;

    int sym = 100;

    rez = speed_print(sym, time);

    ASSERT_EQUAL(1, rez);
}

CTEST(counting, count_score_3_0)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "words";
    user0->diff = "normal";

    int speed = 9;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 9 * 3.4, rez);
}

CTEST(counting, count_score_3_1)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "words";
    user0->diff = "hard";

    int speed = 9;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 9 * 3.7, rez);
}

CTEST(counting, count_score_3)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "sentences";
    user0->diff = "hard";

    int speed = 9;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 9 * 2.9, rez);
}

CTEST(counting, count_score_4)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "sentences";
    user0->diff = "normal";

    int speed = 9;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 9 * 2.7, rez);
}

CTEST(counting, count_score_5)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "code";
    user0->diff = "normal";

    int speed = 9;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 9 * 3, rez);
}

CTEST(counting, count_score_6)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "code";
    user0->diff = "hard";

    int speed = 9;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 9 * 3.4, rez);
}

CTEST(counting, count_score_6_2)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "words";
    user0->diff = "normal";

    int speed = 2;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 2 * 3.4, rez);
}

CTEST(counting, count_score_6_3)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "words";
    user0->diff = "hard";

    int speed = 2;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 2 * 3.7, rez);
}

CTEST(counting, count_score_6_4)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "sentences";
    user0->diff = "hard";

    int speed = 2;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 2 * 2.9, rez);
}

CTEST(counting, count_score_6_5)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "sentences";
    user0->diff = "normal";

    int speed = 2;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 2 * 2.7, rez);
}

CTEST(counting, count_score_6_6)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "code";
    user0->diff = "normal";

    int speed = 2;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 2 * 3, rez);
}

CTEST(counting, count_score_6_7)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "code";
    user0->diff = "normal";

    int speed = 2;

    double coefficient_miss = 0.3;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.7 * 2 * 3.4, rez);
}

///////////////////

CTEST(counting, count_score_7)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "words";
    user0->diff = "normal";

    int speed = 2;

    double coefficient_miss = 0.1;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.9 * 2 * 3.4, rez);
}

CTEST(counting, count_score_8)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "words";
    user0->diff = "hard";

    int speed = 2;

    double coefficient_miss = 0.2;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.8 * 2 * 3.7, rez);
}

CTEST(counting, count_score_9)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "sentences";
    user0->diff = "hard";

    int speed = 2;

    double coefficient_miss = 0.7;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.3 * 2 * 2.9, rez);
}

CTEST(counting, count_score_10)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "sentences";
    user0->diff = "normal";

    int speed = 2;

    double coefficient_miss = 0.5;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.5 * 2 * 2.7, rez);
}

CTEST(counting, count_score_11)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "code";
    user0->diff = "normal";

    int speed = 9;

    double coefficient_miss = 0.6;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.4 * 9 * 3, rez);
}

CTEST(counting, count_score_12)
{
    double rez = 0;

    smode* user0 = (smode*)malloc(sizeof(smode));

    user0->mode = "code";
    user0->diff = "normal";

    int speed = 2;

    double coefficient_miss = 0.8;

    rez = count_score(user0, speed, coefficient_miss);

    free(user0);

    ASSERT_EQUAL(0.2 * 2 * 3.4, rez);
}

CTEST(counting, rang_system_1)
{
    double rez = 0;

    double score = 2;

    rez = rangs(score);

    ASSERT_EQUAL(1, rez);
}

CTEST(counting, rang_system_2)
{
    double rez = 0;

    double score = 7;

    rez = rangs(score);

    ASSERT_EQUAL(2, rez);
}

CTEST(counting, rang_system_3)
{
    double rez = 0;

    double score = 13;

    rez = rangs(score);

    ASSERT_EQUAL(3, rez);
}

CTEST(counting, rang_system_4)
{
    double rez = 0;

    double score = 20;

    rez = rangs(score);

    ASSERT_EQUAL(4, rez);
}

CTEST(counting, rang_system_5)
{
    double rez = 0;

    double score = 27;

    rez = rangs(score);

    ASSERT_EQUAL(5, rez);
}

CTEST(counting, rang_system_6)
{
    double rez = 0;

    double score = 33;

    rez = rangs(score);

    ASSERT_EQUAL(6, rez);
}

CTEST(counting, rang_system_7)
{
    double rez = 0;

    double score = 311;

    rez = rangs(score);

    ASSERT_EQUAL(6, rez);
}