//Сравнение полученных от пользователя данных с исходником
#include "../keynlibs/mainlib.hpp"

int scompare(char *cstring, char * userstring, uint8_t lang) {

    int j = 0;
    bool flag = 1;

    while (cstring[j] != '\0') {
        if (cstring[j] != userstring[j]) {
            if (lang == ENG) {
                if (j == 0)
                    cout << "  ";
                cout << "\x1b[5;31m" << cstring[j] << "\x1b[0m";
            }
            else if (lang == RU ) {
                cout << "  \x1b[5;31m" << cstring << "\x1b[0m";
                flag = 0;
                break;
            }
            flag = 0;
        }
        else {
            if (lang == ENG) {
                if (j == 0)
                    cout << "  ";
                cout << "\x1b[5;32m" << cstring[j] << "\x1b[0m";
            }
            else if (lang == RU && cstring[j + 1] == '\0') {
                cout << "  \x1b[5;32m" << cstring << "\x1b[0m";
            }
        }
        j++;
    }

    cout << endl;

    sleep(1);

    if (flag == 0)
        return 0;

    return 1;
}
