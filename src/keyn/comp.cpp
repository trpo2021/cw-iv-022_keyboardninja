//Сравнение полученных от пользователя данных с исходником
#include "../keynlibs/mainlib.hpp"

int scompare(char *cstring, char * userstring, uint8_t lang, int *fails) {

    int j = 0;
    bool flag = 1;

    cout << "\x1b[5;33m" << "->" << "\x1b[0m";

    while (cstring[j] != '\0') {
        if (cstring[j] != userstring[j]) {
            if (lang == ENG) {
                cout << "\x1b[5;31m" << cstring[j] << "\x1b[0m";
                (*fails)++;
            }
            else if (lang == RU ) {
                cout << "\x1b[5;31m" << cstring << "\x1b[0m";
                flag = 0;
                (*fails)++;
                break;
            }
            flag = 0;
        }
        else {
            if (lang == ENG) {
                if (cstring[j + 1] == '\0') {
                    if (userstring[j + 1] == '\0') {
                        cout << "\x1b[5;32m" << cstring[j] << "\x1b[0m";
                        break;
                    }
                    else {
                        cout << "\x1b[5;31m" << userstring[j + 1] << "\x1b[0m";
                        flag = 0;
                    }
                } 
                else
                    cout << "\x1b[5;32m" << cstring[j] << "\x1b[0m";
            }
            else if (lang == RU && cstring[j + 1] == '\0' && userstring[j + 1] == '\0') {
                cout << "\x1b[5;32m" << cstring << "\x1b[0m";
            }
        }
        j++;
    }
    cout << "\x1b[5;33m" << "<-" << "\x1b[0m" << endl;

    sleep(1);

    if (flag == 0)
        return 0;

    return 1;
}
