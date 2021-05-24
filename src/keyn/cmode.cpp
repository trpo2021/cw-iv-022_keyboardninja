//Code Mode
#include "../keynlibs/mainlib.hpp"

int code_normal(uint8_t lang) {

    system("clear");

    char **codestr = (char**)malloc(MAXCODESTRINGS*sizeof(char*));
    if (codestr == NULL)
        return -1;
    
    char **ustr = (char**)malloc(sizeof(char*));
    if (ustr == NULL)
        return -1;

    //Выбор одного из заготовленных заранее вариантов
    int n = rand() % CODENUM + 1;
    const char *md= "normal";

    int strnum = read_code(codestr, n, md);
    readusansw_uscode(codestr, ustr, strnum, lang);

    free(codestr);
    free(ustr);

    return 0;

}

int code_hard(uint8_t lang) {

    system("clear");

    char **codestr = (char**)malloc(MAXCODESTRINGS*2*sizeof(char*));
    if (codestr == NULL)
        return -1;
    
    char **ustr = (char**)malloc(sizeof(char*));
    if (ustr == NULL)
        return -1;

    //Выбор одного из заготовленных заранее вариантов
    int n = rand() % CODENUM + 1;
    const char *md= "hard";

    int strnum = read_code(codestr, n, md);
    readusansw_uscode(codestr, ustr, strnum, lang);

    free(codestr);
    free(ustr);

    return 0;
}