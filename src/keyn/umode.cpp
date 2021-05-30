#include "../keynlibs/mainlib.hpp"

int umode(uint8_t lang, smode *user0) {

    writefile();

    int fsize = findsize();
    system("clear");

    char **rdstr = (char**)malloc((fsize+1)*sizeof(char*));
    if (rdstr == NULL)
        return -1;

    char **ustr = (char**)malloc(sizeof(char*));
    if (ustr == NULL) {
        free(rdstr);
        return -1;
    }

    read_usermode(rdstr);

    readusansw_uscode(rdstr, ustr, fsize, lang, user0);

    free(rdstr);
    free(ustr);

    return 0;

}

int writefile() {

    system("clear");

    system("touch ../inputtxt/usermode/usermode.txt");

    cout << "\n\t\tInput your text\n" << "\tPress i to switch to edit mode\n" << "Press Esc and enter <:quit!> to exit text editor or <:w> to save changes\n";
    sleep(1);

    system("edit ../inputtxt/usermode/usermode.txt");

    return 0;
}