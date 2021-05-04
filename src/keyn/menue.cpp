#include "../keynlibs/mainlib.hpp"

int menue(smode *user0) {

    bool run = true;
    int select = 0;
    char key;
    int pt = 0;

    const char ***mparts = (const char***)malloc(4*sizeof(char**));
    for (int i = 0; i < 4; i++) {
        mparts[i] = (const char**)calloc(4,sizeof(char*));
        for (int j = 0; j < 4; j++) {
            (*mparts)[i] = (char*)malloc(15*sizeof(char));
        }
    }

    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            if (a == 0) {
                if (b == 0)
                    mparts[a][b] = "1. Play";
                if (b == 1)
                    mparts[a][b] = "2. About";
                if (b == 2)
                    mparts[a][b] = "3. Exit";
            }
            if (a == 1) {
                if (b == 0)
                    mparts[a][b] = "1. Words";
                if (b == 1)
                    mparts[a][b] = "2. Sentences";
                if (b == 2)
                    mparts[a][b] = "3. Code";
                if (b == 3)
                    mparts[a][b] = "4. Usermode";
            }
            if (a == 2) {
                if (b == 0)
                    mparts[a][b] = "1. Easy";
                if (b == 1)
                    mparts[a][b] = "2. Normal";
                if (b == 2)
                    mparts[a][b] = "3. Hard";
            }
        }
    }

    while (run) {
        
        displaymenue(select, mparts, pt, user0);

        key = getchar();

        switch (key)
        {
        case 'q':
            run = false;
            break;

        case '3':
            if (pt == 0) {
                system("clear");
                exit(0);
            }
            else if (pt == 1) {
                user0->mode = (char*) "code";
                pt++;
            }
            else if (pt == 2) {
                user0->diff = (char*) "hard";
                input_username(user0);
                run = false;
            }
            break;

        case '2':
            if (pt == 0) {
                system("clear");
                cout << "\n\t\x1b[5;36m" << "Check our repository for more info : " <<"\x1b[0m\n\n";
                cout << "https://github.com/trpo2021/cw-iv-022_keyboardninja";
                cout << "\n\n\t\x1b[5;32m" << "Follow the link (Сtrl + Сlick)" <<"\x1b[0m\n";
                sleep(10);
            }
            else if (pt == 1) {
                user0->mode = (char*) "sentences";
                pt++;
            }
            else if (pt == 2) {
                user0->diff = (char*) "normal";
                input_username(user0);
                pt++;
                run = false;
            }
            break;
        
        case '4' :
            if (pt == 1) {
                user0->mode = (char*) "usermode";
                pt++;
            }
            break;

        case '1':
            if (pt == 0) {
                pt++;
            }
            else if (pt == 1) {
                user0->mode = (char*) "words";
                pt++;
            }
            else if (pt == 2) {
                user0->diff = (char*) "easy";
                input_username(user0);
                run = false;
            }
            break;

        default:
            break;
        }

    }

    free(mparts);

    return 0;
}

void displaymenue(int pos, const char ***meparts, int part, smode *user0) {

    system("clear");

    cout << "\x1b[4;35m\t" << "KEYBOARD NINJA" << "\x1b[0m" << endl;
    if (part == 0) {
        cout << "\t" << meparts[part][pos] << endl;
        cout << "\t" << meparts[part][1] << endl;
        cout << "\t" << meparts[part][2] << endl;
    }
    else if (part == 1) {
        cout << "\t" << meparts[part][pos] << endl;
        cout << "\t" << meparts[part][1] << endl;
        cout << "\t" << meparts[part][2] << endl;
        cout << "\t" << meparts[part][3] << endl;
    }
    else if (part == 2) {
        if (strcmp(user0->mode, "words") == 0) {
            cout << "\t" << meparts[part][pos] << endl;
            cout << "\t" << meparts[part][1] << endl;
            cout << "\t" << meparts[part][2] << endl;
        }
        else if (strcmp(user0->mode, "sentences") == 0 || strcmp(user0->mode, "code") == 0) {
            cout << "\x1b[8;35m" << "\t" << meparts[part][pos] << "\x1b[0m" << endl;
            cout << "\t" << meparts[part][1] << endl;
            cout << "\t" << meparts[part][2] << endl;
        }
    }
        
}

void input_username(smode *user0) {

    system("clear");

    cout << "\x1b[5;35m" << "      Enter you username" << "\x1b[0m" << endl;
    cout << "  ";
    cout << "\x1b[4;31m\t" << "max 15 symbols" << "\x1b[0m" << endl;

    cin >> user0->username;

}
