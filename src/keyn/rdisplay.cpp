//Чтение и вывод на экран информации
#include "../keynlibs/mainlib.hpp"

void code_display(char **cstrings, int x, int y, int ncolor, int snumber) {

    system("clear");

    // for (int i = 0; i < x && i ; i++) {
    //     if (i < ncolor) {
    //         cout << "\x1b[5;32m" << cstrings[i] <<"\x1b[0m";
    //     }
    //     else 
    //         cout << cstrings[i];
    //     cout << "\n";
    // }

    if (snumber < x) {
        cout << "\x1b[5;37m" << "->" <<"\x1b[0m";
        cout << "\x1b[1;34m" << cstrings[snumber] <<"\x1b[0m\n"; 
    }

    if (snumber < x - 2) {
        cout << "  next -> ";
        cout << "\x1b[1;35m" << cstrings[snumber + 1] <<"\x1b[0m\n";
        cout << "  next -> " << "\x1b[1;35m" << cstrings[snumber + 2] <<"\x1b[0m\n";
    } 
    else if (snumber < x - 1)
        cout << "  ->next : " << "\x1b[1;35m" << cstrings[snumber + 1] <<"\x1b[0m\n";

    if (snumber != x)
        cout << "\n\n\t\x1b[5;36m" << "Your Answer : " <<"\x1b[0m\n\n";

}