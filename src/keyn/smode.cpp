#include "../keynlibs/mainlib.hpp"

void smode_eng(std::ifstream* in, smode* user0)
{
    int rand_num = rand() % COUNTSENT;

    char* str = (char*)malloc(MAXSENT * sizeof(char));
    if (str == NULL) {
        return;
    }

    char* ans = (char*)malloc(MAXSENT * sizeof(char));
    if (ans == NULL) {
        free(str);
        return;
    }

    int i = 0;
    while (i < rand_num) {
        in->getline(str, MAXSENT, '\n');
        i++;
    }

    readusansw_uscode(&str, &ans, 1, ENG, user0);

    free(str);
    free(ans);
}