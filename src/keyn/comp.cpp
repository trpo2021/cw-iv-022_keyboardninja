#include "../keynlibs/mainlib.hpp"

int scompare(char* cstring, char* userstring, uint8_t lang, int* fails, bool** cstatus)
{
    int j = 0;
    uint8_t flag = 1;

    while (cstring[j] != '\0') {
        if (cstring[j] != userstring[j]) {
            if (lang == ENG) {
                (*cstatus)[j] = 1;
                (*fails)++;
            } else if (lang == RU) {
                (*cstatus)[j] = 1;
                (*fails)++;
            }
            flag = 0;
        } else {
            if (lang == ENG) {
                if (cstring[j + 1] == '\0') {
                    if (userstring[j + 1] == '\0') {
                        break;
                    } else {
                        j += 1;
                        while (userstring[j] != '\0') {
                            (*fails)++;
                            (*cstatus)[j] = 1;
                            j++;
                        }
                        flag = 2;
                        break;
                    }
                } 
            } 
        }
        j++;
    }

    if (flag == 0)
        return 0;
    else if (flag == 2)
        return 2;
    else
        return 1;
}
