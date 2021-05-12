//Code Mode
#include "../keynlibs/mainlib.hpp"

int code_normal() {

    system("clear");

    char **codestr = (char**)malloc(MAXCODESTRINGS*sizeof(char*));
    if (codestr == NULL)
        return -1;
    
    char **ustr = (char**)malloc(MAXCODESTRINGS*sizeof(char*));
    if (ustr == NULL)
        return -1;


    //Выбор одного из заготовленных заранее вариантов
    int n = rand() % 10 + 1;
    const char *md= "normal";

    int strnum = read_code(codestr, n, md);
    read_user_answer_code(codestr, ustr, strnum);

    free(codestr);
    free(ustr);

    return 0;

}

int code_hard() {

    system("clear");

    char **codestr = (char**)malloc(MAXCODESTRINGS*2*sizeof(char*));
    if (codestr == NULL)
        return -1;
    
    char **ustr = (char**)malloc(MAXCODESTRINGS*2*sizeof(char*));
    if (ustr == NULL)
        return -1;


    //Выбор одного из заготовленных заранее вариантов
    int n = rand() % 10 + 1;
    const char *md= "hard";

    int strnum = read_code(codestr, n, md);
    read_user_answer_code(codestr, ustr, strnum);

    free(codestr);
    free(ustr);

    return 0;
}