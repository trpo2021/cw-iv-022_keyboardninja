//Сравнение полученных от пользователя данных с исходником
#include "../keynlibs/mainlib.hpp"

int code_compare(char **cstrings, char ** userstrings, int i) {

    int j = 0;
    bool flag = 0;

    while (cstrings[i][j] != '\0') {
        if (cstrings[i][j] != userstrings[i][j]) {
            cout << "\x1b[5;31m" << cstrings[i][j] << "\x1b[0m";
            flag = 1;
        }
        else
            cout << "\x1b[5;32m" << cstrings[i][j] << "\x1b[0m";
        j++;
    }

    cout << endl;

    if (flag == 1)
        return -1;

    return 0;
}