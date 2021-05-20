//Функции для чтения из файла текстов для различных режимов
#include "../keynlibs/mainlib.hpp"

int read_code(char **cstrings, int num, const char *md) {
    ifstream in;
    char mode;
    if (strcmp(md, "normal") == 0) {
        mode = 'n';
        in.open("../inputtxt/code/Code_Medium.txt");
    }
    else {
        mode = 'h';
        in.open("../inputtxt/code/Code_Hard.txt");
    }
    int i = 0, c = 0;

    char *temp = NULL;

    if (mode == 'n') {

        temp  = (char*)malloc(MAXCODELENS*sizeof(char));
        if (temp == NULL) {
            in.close();
            return -1;
        }

    }
    else if (mode == 'h') {
        
        temp  = (char*)malloc(MAXCODELENS*2*sizeof(char));
        if (temp == NULL) {
            in.close();
            return -1;
        }

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

int read_usermode(char **cstrings) {

    ifstream in;
    in.open("../inputtxt/usermode/usermode.txt");

    int i = 0;

    char *temp = NULL;

    temp  = (char*)malloc(MAXCODELENS*sizeof(char));
    if (temp == NULL) {
        in.close();
        return -1;
    }


    while (in) {

        cstrings[i] = (char*)malloc(MAXCODELENS*sizeof(char));

        if (in.eof())
            break;

        in.getline(cstrings[i], MAXCODELENS);
                i++;
    }

    in.close();

    //Возвращает количество строк (понадобится для сравнения)
    return i;
}