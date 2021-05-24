#include "../keynlibs/mainlib.hpp"

int umode(uint8_t lang) {

    writefile();

    int fsize = findsize();
    system("clear");

    char **rdstr = (char**)malloc(MAXCODESTRINGS*sizeof(char*));
    if (rdstr == NULL)
        return -1;

    char **ustr = (char**)malloc(sizeof(char*));
    if (ustr == NULL)
        return -1;

    read_usermode(rdstr);

    readusansw_uscode(rdstr, ustr, fsize, lang);

    free(rdstr);
    free(ustr);

    return 0;

}

int writefile() {

    system("clear");

    system("touch ../inputtxt/usermode/usermode.txt");
    system("./script.sh");

    cout << "\n\tInput your text\n";
    sleep(1);

    system("nano ../inputtxt/usermode/usermode.txt");

    return 0;
}