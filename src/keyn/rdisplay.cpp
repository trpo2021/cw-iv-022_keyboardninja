//Чтение и вывод на экран информации
#include "../keynlibs/mainlib.hpp"

void code_display(char **cstrings, int x, int y) {

    for (int i = 0; i < x; i++) {
            cout << cstrings[i];
        cout << "\n";
    }

    cout << "\n\n\t\x1b[5;36m" << "Your Answer : " <<"\x1b[0m\n\n";

}