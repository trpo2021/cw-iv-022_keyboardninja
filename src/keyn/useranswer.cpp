//Считывание ответов пользователя
#include "../keynlibs/mainlib.hpp"

int read_user_answer_code(char **cstrings, char **userstrings, int uscount) {

    int counter = 0, j, flag;

    char *temp  = (char*)malloc(MAXCODELENS*sizeof(char));
        if (temp == NULL) {
            return -1;
        }
    
    //Очистить последний символ буфера
    getchar();

    while (1) {

        code_display(cstrings, uscount, 1, counter, counter);

        j = 0;

        if (counter == uscount)
            break;
        
        userstrings[counter] = (char*)malloc(MAXCODELENS*sizeof(char));
        cin.getline(userstrings[counter], MAXCODELENS, '\n');

            flag = code_compare(cstrings[counter], userstrings[counter]);
            while (flag != 0) {
            if (flag != 0) {
                cout << "\x1b[5;31m\t" << "TRY AGAIN" << "\x1b[0m" << endl;
                cin.getline(userstrings[counter], MAXCODELENS, '\n');
                flag = code_compare(cstrings[counter], userstrings[counter]);
            }
            else {
                j++;
                flag = true;
            }
            }

        counter++;
    }

    free(temp);

    return 0;
}