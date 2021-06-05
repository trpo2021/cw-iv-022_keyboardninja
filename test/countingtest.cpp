#include "../src/keynlibs/mainlib.hpp"
#include "../thirdparty/ctest.h"

double count_percent_miss(int fails, int sim)
{
    double result;
    result = ((double)fails / (double)sim) * 100;
    if (result > 100) {
        return -1;
    }
    return result;
}

double count_coefficient_miss(double persent_miss)
{
    if (persent_miss > 100) {
        return -1;
    }
    return (persent_miss / 100);
}

double speed_print(int sym, int time)
{
    return ((double)sym / (double)time);
}

double count_score(smode* user0, int speed, double coefficient_miss)
{
    double r;
    if (strcmp(user0->mode, "words") == 0) {
        if (strcmp(user0->diff, "hard") == 0) {
            r = 3.7;
        }

        if (strcmp(user0->diff, "normal") == 0) {
            r = 3.4;
        }
    }

    if (strcmp(user0->mode, "sentences") == 0) {
        if (strcmp(user0->diff, "hard") == 0) {
            r = 2.9;
        }

        if (strcmp(user0->diff, "normal") == 0) {
            r = 2.7;
        }
    }

    if (strcmp(user0->mode, "code") == 0) {
        if (strcmp(user0->diff, "hard") == 0) {
            r = 3.4;
        }

        if (strcmp(user0->diff, "normal") == 0) {
            r = 3;
        }
    }

    if (strcmp(user0->mode, "usermode") == 0) {
        r = 2.4;
    }

    double score = (double)speed * r * (1 - coefficient_miss);
    return score;
}

int rangs(double score)
{
    if (score < 5) {
        return 1;
    }

    if ((score >= 5) && (score < 10)) {
        return 2;
    }

    if ((score >= 10) && (score < 15)) {
        return 3;
    }

    if ((score >= 15) && (score < 25)) {
        return 4;
    }

    if ((score >= 25) && (score < 30)) {
        return 5;
    }

    if (score >= 30) {
        return 6;
    }
    return -1;
}