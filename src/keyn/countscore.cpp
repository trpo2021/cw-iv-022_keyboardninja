#include "../keynlibs/mainlib.hpp"

double count_score(smode *user0, int speed, double coefficient_miss)
{
    double r;
    if (strcmp(user0->mode, "words") == 0)
    {
        if (strcmp(user0->diff, "hard") == 0)
        {
            r = 3.7;
        }

        if (strcmp(user0->diff, "normal") == 0)
        {
            r = 3.4;
        }
    }

    if (strcmp(user0->mode, "sentences") == 0)
    {
        if (strcmp(user0->diff, "hard") == 0)
        {
            r = 2.9;
        }

        if (strcmp(user0->diff, "normal") == 0)
        {
            r = 2.7;
        }
    }

    if (strcmp(user0->mode, "code") == 0)
    {
        if (strcmp(user0->diff, "hard") == 0)
        {
            r = 3.4;
        }

        if (strcmp(user0->diff, "normal") == 0)
        {
            r = 3;
        }
    }

    if (strcmp(user0->mode, "usermode") == 0)
    {
        r = 2.4;
    }

    double score = (double)(speed * r * (1 - coefficient_miss));
    return score;
}

double count_percent_miss(int fails, int sim)
{
    double result;
    result = ((double)fails / (double)sim) * 100;
    return (double)result;
}

double count_coefficient_miss(double persent_miss)
{
    return (double)(persent_miss / 100);
}

double speed_print(int sym, int time)
{
    return (double)(sym / time);
}