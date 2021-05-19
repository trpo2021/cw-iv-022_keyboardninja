//Сравнение полученных от пользователя данных с исходником
#include "../keynlibs/mainlib.hpp"

int code_compare(char *cstring, char * userstring) {

    int j = 0;
    bool flag = 0;

    while (cstring[j] != '\0') {
        if (cstring[j] != userstring[j]) {
            cout << "\x1b[5;31m" << cstring[j] << "\x1b[0m";
            flag = 1;
        }
        else
            cout << "\x1b[5;32m" << cstring[j] << "\x1b[0m";
        j++;
    }

    cout << endl;

    sleep(1);

    if (flag == 1)
        return -1;

    return 0;
}