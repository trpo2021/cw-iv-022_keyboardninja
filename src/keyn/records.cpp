//Функции для работы с таблицей рекордов
#include "../keynlibs/mainlib.hpp"

int read_code(char **cstrings, int num, const char *md) {
    ifstream in;
    if (strcmp(md, "normal") == 0)
        in.open("Code_Medium.txt");
    else
        in.open("Code_Hard.txt");

    int i = 0, c = 0;

    char *temp  = (char*)malloc(MAXCODELENS*sizeof(char));
    if (temp == NULL) {
        in.close();
        return -1;
    }

    while (in) {

        in.getline(temp, MAXCODELENS);
        if (strcmp(temp, "###") == 0)
            c++;

        if (c == num) {
            do {
                cstrings[i] = (char*)malloc(MAXCODELENS*sizeof(char));

                if (i >= 1 && strcmp(cstrings[i - 1], "###") == 0)
                    break;

                if (in.eof())
                    break;

                in.getline(cstrings[i], MAXCODELENS);
                i++;
            } while (!(strcmp(cstrings[i - 1], "###") == 0));
        }
    }

    in.close();

    //Возвращает количество строк (понадобится для сравнения)
    return i - 1;

}