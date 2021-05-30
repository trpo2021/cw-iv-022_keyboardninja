//Code Mode
#include "../keynlibs/mainlib.hpp"

int cmode(uint8_t lang, smode *user0) {

    system("clear");

    int size = 0;

    if(strcmp(user0->diff, "normal") == 0) {
        size = MAXCODESTRINGS;
    }
    else {
        size = 2*MAXCODESTRINGS;
    }

    char **codestr = (char**)malloc(size*sizeof(char*));
    if (codestr == NULL)
        return -1;

    char **ustr = (char**)malloc(sizeof(char*));
    if (ustr == NULL) {
        free(codestr);
        return -1;
    }
    //Выбор одного из заготовленных заранее вариантов
    int n = rand() % CODENUM + 1;

    int strnum = read_code(codestr, n, user0->diff);
    readusansw_uscode(codestr, ustr, strnum, lang, user0);

    free(codestr);
    free(ustr);

    return 0;

}
