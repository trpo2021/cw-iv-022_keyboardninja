//Вывод на экран информации различных режимов
#include "../keynlibs/mainlib.hpp"

void display_sarr(char **cstrings, int x, int snumber) {

    system("clear");

    if (snumber < x) {
        cout << "\x1b[5;33m" << "->" <<"\x1b[0m";
        cout << "\x1b[1;34m" << cstrings[snumber] <<"\x1b[0m\n"; 
    }

    if (snumber < x - 2) {
        cout << "  next -> ";
        cout << "\x1b[1;35m" << cstrings[snumber + 1] <<"\x1b[0m\n";
        cout << "  next -> " << "\x1b[1;35m" << cstrings[snumber + 2] <<"\x1b[0m\n";
    } 
    else if (snumber < x - 1)
        cout << "  ->next : " << "\x1b[1;35m" << cstrings[snumber + 1] <<"\x1b[0m\n";

    if (snumber != x) {
        cout << "\n\n\t\x1b[5;36m" << "Your Answer : " <<"\x1b[0m\n\n";
        cout << "\x1b[5;33m" << "->" <<"\x1b[0m";
    }

}

void display_results(time_t start, time_t stop, int sleeps, int fails) {
    cout << "\x1b[1;36m" << "Time : " <<"\x1b[0m" << difftime(stop, start) - sleeps << " seconds\n";
    cout << "\x1b[1;31m" <<  "Fails : " <<"\x1b[0m" << fails << endl;
}
