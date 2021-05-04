#include "../keynlibs/mainlib.hpp"

int main () {

    system("clear");
    cout << "\x1b[36;26m" << "\tWelcome to the Keyboard Ninja" << "\x1b[0m\n";
    cout << "\x1b[32;26m" << "   Use 1, 2, 3 or 4 to navigate the menue" << "\x1b[0m\n";
    sleep(3);

    smode *user0 = (smode*)malloc(sizeof(smode));
    user0->mode = (const char*)malloc(10*sizeof(char));
    user0->diff = (const char*)malloc(10*sizeof(char));
    user0->username = (char*)malloc(15*sizeof(char));

    menue(user0);

    cout << user0->mode << "\n" << user0->diff << "\n";
    
    return 0;
}