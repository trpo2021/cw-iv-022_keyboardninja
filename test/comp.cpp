#include "../src/keynlibs/mainlib.hpp"

int scompare(char* cstring, char* userstring, uint8_t lang, int* fails)
{
    int j = 0;
    bool flag = 1;

    while (cstring[j] != '\0') {
        if (cstring[j] != userstring[j]) {
            if (lang == ENG) {
                (*fails)++;
            } else if (lang == RU) {
                flag = 0;
                (*fails)++;
                break;
            }
            flag = 0;
        } else {
            if (lang == ENG) {
                if (cstring[j + 1] == '\0') {
                    if (userstring[j + 1] == '\0') {
                        break;
                    } else {
                        (*fails)++;
                        flag = 0;
                    }
                }
            } else if (
                    lang == RU && cstring[j + 1] == '\0'
                    && userstring[j + 1] == '\0') {
            }
        }
        j++;
    }

    if (flag == 0)
        return 0;

    return 1;
}
