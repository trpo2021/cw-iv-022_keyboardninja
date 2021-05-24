//Считывание ответов пользователя
#include "../keynlibs/mainlib.hpp"

int readusansw_uscode(char **cstrings, char **userstrings, int uscount, uint8_t lang) {

    int counter = 0, j, flag, rsize;

    if (lang == RU)
        rsize = MAXUSERLEN;
    else if (lang == ENG)
        rsize = MAXCODELENS;

    char *temp  = (char*)malloc(rsize*sizeof(char));
        if (temp == NULL) {
            return -1;
        }
    //Очистить последний символ буфера
    getchar();

    *userstrings = (char*)malloc(rsize*sizeof(char));
    if (*userstrings == NULL) {
        return -1;
    }

    while (1) {

        display_sarr(cstrings, uscount, counter);
        j = 0;

        if (counter == uscount)
            break;
        
        cin.getline(*userstrings, rsize, '\n');
        flag = scompare(cstrings[counter], *userstrings, lang);

        while (flag == 0) {
            if (flag == 0) {
                // cout << "\x1b[5;31m\t" << "TRY AGAIN" << "\x1b[0m" << endl;
                display_sarr(cstrings, uscount, counter);
                cin.getline(*userstrings, rsize, '\n');
                //Очистка потока (В случае, если введённая строка больше ожидаемой)
                cin.clear();
                flag = scompare(cstrings[counter], *userstrings, lang);
            }
            else {
                j++;
                flag = true;
            }
        }
        counter++;
    }
    free(*userstrings);
    free(temp);

    return 0;
}
