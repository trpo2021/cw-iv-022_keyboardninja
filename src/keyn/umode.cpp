#include "../keynlibs/mainlib.hpp"

int umode() {

    writefile();

    int fsize = findsize();

    cout << "FILESIZE : " << fsize << "\n";

    sleep(1);

    system("clear");

    char **rdstr = (char**)malloc(MAXCODESTRINGS*sizeof(char*));
    if (rdstr == NULL)
        return -1;

    char **ustr = (char**)malloc(fsize*sizeof(char*));
    if (ustr == NULL)
        return -1;

    read_usermode(rdstr);

    read_user_answer_code(rdstr, ustr, fsize);


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