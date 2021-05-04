//Считывание ответов пользователя
#include "../keynlibs/mainlib.hpp"

int read_user_answer(char **userstrings, int uscount) {

    // bool rwhile = true;
    int counter = 0;

    char *temp  = (char*)malloc(MAXCODELENS*sizeof(char));
        if (temp == NULL) {
            return -1;
        }

    while (1) {
        if (counter == uscount)
            break;
        
        userstrings[counter] = (char*)malloc(MAXCODELENS*sizeof(char));

        fscanf(stdin, "%s", userstrings[counter]);
        counter++;
    }

    return 0;
}