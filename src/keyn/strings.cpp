#include "../keynlibs/mainlib.hpp"

int slen(char* str)
{
    int len;

    for (int i = 0; str[i] != '\0'; i++)
        len = i + 1;

    return len;
}

int lencount(char** str, int count)
{
    int length = 0;

    for (int i = 0; i < count; i++) {
        length = length + slen(str[i]);
    }
    return length;
}