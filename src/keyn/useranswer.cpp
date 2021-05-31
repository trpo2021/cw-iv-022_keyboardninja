#include "../keynlibs/mainlib.hpp"

int readusansw_uscode(
        char** cstrings,
        char** userstrings,
        int uscount,
        uint8_t lang,
        smode* user0)
{
    int counter = 0, j, flag, rsize, sleepcount = 0, fails = 0, len;
    time_t start, stop;

    if (lang == RU)
        rsize = MAXUSERLEN;
    else if (lang == ENG)
        rsize = MAXCODELENS;
    if (strcmp(user0->mode, "sentences") == 0) {
        rsize = 2 * MAXSENT;
    }

    *userstrings = (char*)malloc(rsize * sizeof(char));
    if (*userstrings == NULL) {
        return -1;
    }

    start = time(NULL);
    while (1) {
        display_sarr(cstrings, uscount, counter);
        j = 0;

        if (counter == uscount)
            break;

        std::cin.getline(*userstrings, rsize, '\n');

        if (strcmp(*userstrings, ":q!") == 0) {
            system("clear");
            menue(user0);
        }

        flag = scompare(cstrings[counter], *userstrings, lang, &fails);
        sleepcount++;

        while (flag == 0) {
            if (flag == 0) {
                display_sarr(cstrings, uscount, counter);
                std::cin.getline(*userstrings, rsize, '\n');
                if (strcmp(*userstrings, ":q!") == 0) {
                    system("clear");
                    menue(user0);
                }
                std::cin.clear();
                flag = scompare(cstrings[counter], *userstrings, lang, &fails);
                sleepcount++;
            } else {
                j++;
                flag = true;
            }
        }
        counter++;
    }
    stop = time(NULL);
    len = lencount(cstrings, uscount);
    display_results(start, stop, sleepcount, fails, len, user0);

    free(*userstrings);

    return 0;
}