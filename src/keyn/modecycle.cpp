//Цикличный запуск выбранного режима
#include "../keynlibs/mainlib.hpp"

void modecycle(smode *user0)
{

    bool flag = true;
    char answ[2] = {};

    input_username(user0);

    if (strcmp(user0->mode, "code") == 0 && strcmp(user0->diff, "normal") == 0)
    {
        while (flag)
        {
            code_normal(ENG, user0);

            while (1)
            {
                system("clear");
                cout << "\n\t\x1b[5;36m"
                 << "Do you want to continue ? (Y/N) : "
                 << "\x1b[0m";
                cin.getline(answ, 2);
                cin.clear();
                if (*answ == 'N' || *answ == 'n')
                {
                    flag = false;
                    break;
                }
                else if (*answ == 'Y' || *answ == 'y')
                {
                    break;
                }
            }
        }
    }
    else if (strcmp(user0->mode, "code") == 0 && strcmp(user0->diff, "hard") == 0)
    {
        while (flag)
        {
            code_hard(ENG, user0);
            
            while (1)
            {
                system("clear");
                cout << "\n\t\x1b[5;36m"
                 << "Do you want to continue ? (Y/N) : "
                 << "\x1b[0m";
                cin.getline(answ, 2);
                cin.clear();
                if (*answ == 'N' || *answ == 'n')
                {
                    flag = false;
                    break;
                }
                else if (*answ == 'Y' || *answ == 'y')
                {
                    break;
                }
            }
        }
    }
    else if (strcmp(user0->mode, "usermode") == 0)
    {
        while (flag)
        {
            umode(RU, user0);

            while (1)
            {
                system("clear");
                cout << "\n\t\x1b[5;36m"
                 << "Do you want to continue ? (Y/N) : "
                 << "\x1b[0m";
                cin.getline(answ, 2);
                cin.clear();
                if (*answ == 'N' || *answ == 'n')
                {
                    flag = false;
                    break;
                }
                else if (*answ == 'Y' || *answ == 'y')
                {
                    break;
                }
            }
        }
    }
    else if ((strcmp(user0->mode, "words") == 0) && (strcmp(user0->lang, "eng") == 0))
    {
        ifstream in;
        open_file_eng(user0, &in);
        while (flag)
        {
            wmode_eng(&in, ENG, user0);

            while (1)
            {
                system("clear");
                cout << "\n\t\x1b[5;36m"
                 << "Do you want to continue ? (Y/N) : "
                 << "\x1b[0m";
                cin.getline(answ, 2);
                cin.clear();
                if (*answ == 'N' || *answ == 'n')
                {
                    flag = false;
                    break;
                }
                else if (*answ == 'Y' || *answ == 'y')
                {
                    break;
                }
            }
        }
    }
    else if ((strcmp(user0->mode, "words") == 0) && (strcmp(user0->lang, "ru") == 0))
    {
        while (flag)
        {
            wmode_ru(user0);

            while (1)
            {
                system("clear");
                cout << "\n\t\x1b[5;36m"
                 << "Do you want to continue ? (Y/N) : "
                 << "\x1b[0m";
                cin.getline(answ, 2);
                cin.clear();
                if (*answ == 'N' || *answ == 'n')
                {
                    flag = false;
                    break;
                }
                else if (*answ == 'Y' || *answ == 'y')
                {
                    break;
                }
            }
        }
    }
    else if ((strcmp(user0->mode, "sentences") == 0) && (strcmp(user0->lang, "eng") == 0))
    {
        ifstream in;
        open_file_eng(user0, &in);

        while (flag)
        {
            smode_eng(&in, user0);

            while (1)
            {
                system("clear");
                cout << "\n\t\x1b[5;36m"
                 << "Do you want to continue ? (Y/N) : "
                 << "\x1b[0m";
                cin.getline(answ, 2);
                cin.clear();
                if (*answ == 'N' || *answ == 'n')
                {
                    flag = false;
                    break;
                }
                else if (*answ == 'Y' || *answ == 'y')
                {
                    break;
                }
            }
        }
    }

    menue(user0);
}