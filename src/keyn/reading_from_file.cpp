//Функции для чтения из файла текстов для различных режимов
#include "../keynlibs/mainlib.hpp"

int read_code(char **cstrings, int num, const char *md)
{
    ifstream in;
    char mode;
    if (strcmp(md, "normal") == 0)
    {
        mode = 'n';
        in.open("../inputtxt/code/Code_Medium.txt");
    }
    else
    {
        mode = 'h';
        in.open("../inputtxt/code/Code_Hard.txt");
    }
    int i = 0, c = 0;

    char *temp = NULL;

    if (mode == 'n')
    {
        temp = (char *)malloc(MAXCODELENS * sizeof(char));
        if (temp == NULL)
        {
            in.close();
            return -1;
        }
    }
    else if (mode == 'h')
    {
        temp = (char *)malloc(MAXCODELENS * 2 * sizeof(char));
        if (temp == NULL)
        {
            in.close();
            return -1;
        }
    }

    while (in)
    {
        in.getline(temp, MAXCODELENS);
        if (strcmp(temp, "###") == 0)
            c++;

        if (c == num)
        {
            do
            {
                cstrings[i] = (char *)malloc(MAXCODELENS * sizeof(char));

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

int read_usermode(char **cstrings)
{

    ifstream in;
    in.open("../inputtxt/usermode/usermode.txt");

    if (!in)
    {
        cout << "File can't be opened\n";
        return -1;
    }

    int i = 0;

    while (!in.eof())
    {

        cstrings[i] = (char *)malloc(MAXUSERLEN * sizeof(char));
        in.getline(cstrings[i], MAXUSERLEN);

        if (in.eof())
            break;

        in.clear();
        i++;
    }

    in.close();
    return i;
}

void open_file_eng(smode *user, ifstream *in)
{

    if (strcmp(user->mode, "words") == 0)
    {
        if (strcmp(user->diff, "normal") == 0)
        {

            in->open("../inputtxt/Words/Words_Medium_Eng.txt");
        }

        if (strcmp(user->diff, "hard") == 0)
        {

            in->open("../inputtxt/Words/Words_Hard_Eng.txt");
        }
    }

    if (strcmp(user->mode, "sentences") == 0)
    {
        if (strcmp(user->diff, "normal") == 0)
        {

            in->open("../inputtxt/Sentences/Sentences_Medium_Eng.txt");
        }

        if (strcmp(user->diff, "hard") == 0)
        {

            in->open("../inputtxt/Sentences/Sentences_Hard_Eng.txt");
        }
    }
}
