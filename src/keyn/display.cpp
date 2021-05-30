//Вывод на экран информации различных режимов
#include "../keynlibs/mainlib.hpp"

void display_sarr(char **cstrings, int x, int snumber)
{

    system("clear");

    if (snumber < x)
    {
        cout << "\x1b[5;33m"
             << "->"
             << "\x1b[0m";
        cout << "\x1b[1;34m" << cstrings[snumber] << "\x1b[0m\n";
    }

    if (snumber < x - 2)
    {
        cout << "  next -> ";
        cout << "\x1b[1;35m" << cstrings[snumber + 1] << "\x1b[0m\n";
        cout << "  next -> "
             << "\x1b[1;35m" << cstrings[snumber + 2] << "\x1b[0m\n";
    }
    else if (snumber < x - 1)
        cout << "  ->next : "
             << "\x1b[1;35m" << cstrings[snumber + 1] << "\x1b[0m\n";

    if (snumber != x)
    {
        cout << "\n\n\t\x1b[5;36m"
             << "Your Answer : "
             << "\x1b[0m\n\n";
        cout << "\x1b[5;33m"
             << "->"
             << "\x1b[0m";
    }
}

void display_results(time_t start, time_t stop, int sleeps, int fails, int sym, smode *user0)
{
    cout << "\x1b[1;36m"
         << "Time : "
         << "\x1b[0m" << difftime(stop, start) - sleeps << " seconds\n";
    cout << "\x1b[1;31m"
         << "Fails : "
         << "\x1b[0m" << fails << endl;

    int time = difftime(stop, start) - sleeps;

    cout << "sym  " << sym << endl;
    double persent_miss = count_percent_miss(fails, sym);
    cout << "\x1b[1;35m"
         << " persent of miss " << persent_miss << "%"
         << "\x1b[0m" << endl;
    double coefficient_miss = count_coefficient_miss((int)persent_miss);
    cout << "\x1b[1;35m"
         << "coefficient of miss " << coefficient_miss << "\x1b[0m" << endl;
    double speed_of_print = speed_print(sym, time);
    cout << "\x1b[1;35m"
         << "simv per sec : " << speed_of_print << "\x1b[0m" << endl;
    double score = count_score(user0, speed_of_print, coefficient_miss);
    cout << "\x1b[1;35m"
         << "Your score : " << score << "\x1b[0m" << endl;
}

double count_percent_miss(int fails, int sim)
{
    double result;
    result = ((double)fails / (double)sim) * 100;
    return result;
}

double count_coefficient_miss(double persent_miss)
{
    return (persent_miss / 100);
}

double speed_print(int sym, int time)
{
    return (sym / time);
}

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

    double score = (double)speed * r * (1 - coefficient_miss);
    return score;
}