#include "../keynlibs/mainlib.hpp"

int scompare(char* cstring, char* userstring, uint8_t lang, int* fails, bool** cstatus)
{
    int j = 0;
    uint8_t flag = 1;

    while (cstring[j] != '\0') {
        if (cstring[j] != userstring[j]) {
            if (lang == ENG) {
                // std::cout << "\x1b[5;31m" << cstring[j] << "\x1b[0m";
                (*cstatus)[j] = 1;
                (*fails)++;
            } else if (lang == RU) {
                // std::cout << "\x1b[5;31m" << cstring << "\x1b[0m";
                (*cstatus)[j] = 1;
                (*fails)++;
            }
            flag = 0;
        } else {
            if (lang == ENG) {
                if (cstring[j + 1] == '\0') {
                    if (userstring[j + 1] == '\0') {
                        // std::cout << "\x1b[5;32m" << cstring[j] << "\x1b[0m";
                        break;
                    } else {
                        // std::cout << "\x1b[5;31m" << userstring[j + 1]
                        //           << "\x1b[0m";
                        while (userstring[j] != '\0') {
                            (*fails)++;
                            (*cstatus)[j] = 1;
                            j++;
                        }
                        flag = 2;
                        break;
                    }
                } 
                // else
                    // std::cout << "\x1b[5;32m" << cstring[j] << "\x1b[0m";
            } 
            // else if (
            //         lang == RU && cstring[j + 1] == '\0'
            //         && userstring[j + 1] == '\0') {
            //     std::cout << "\x1b[5;32m" << cstring << "\x1b[0m";
            // }
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
