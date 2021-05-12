//Цикличный запуск выбранного режима
#include "../keynlibs/mainlib.hpp"

void modecycle (smode *user0) {

    bool flag = true;
    char answ[1] = {};

    input_username(user0);

    sleep(2);

    if (strcmp(user0->mode, "code") == 0 && strcmp(user0->diff, "normal") == 0) {
        while (flag)
        {
            code_normal();
            cout << "\n\t\x1b[5;36m" << "Do you want to continue ? (Y/N) : " <<"\x1b[0m";
            cin >> answ;

            if (strcmp(answ, "N") == 0 || strcmp(answ, "n") == 0) {
                flag = false;
            }
        }
    }
    else if (strcmp(user0->mode, "code") == 0 && strcmp(user0->diff, "hard") == 0) {
        while (flag)
        {
            code_hard();
            cout << "\n\t\x1b[5;36m" << "Do you want to continue ? (Y/N) : " <<"\x1b[0m";
            cin >> answ;

            if (strcmp(answ, "N") == 0 || strcmp(answ, "n") == 0) {
                flag = false;
            }
        }
    }

    menue(user0);

}