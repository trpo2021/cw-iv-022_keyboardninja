#include "../keynlibs/mainlib.hpp"

int menue(smode* user0)
{
    bool run = true;
    int select = 0;
    char key = '3';
    int pt = 0;

    const char*** mparts = (const char***)malloc(4 * sizeof(char**));
    if (mparts == NULL) {
        std::cout << "Memory allocation error\n";
        return -1;
    }
    for (int i = 0; i < 4; i++) {
        mparts[i] = (const char**)calloc(4, sizeof(char*));
        if (*mparts == NULL) {
            std::cout << "Memory allocation error\n";
            return -1;
        }
        for (int j = 0; j < 4; j++) {
            (*mparts)[i] = (char*)malloc(15 * sizeof(char));

            if (**mparts == NULL) {
                std::cout << "Memory allocation error\n";
                return -1;
            }
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
            if (a == 3) {
                if (b == 0)
                    mparts[a][b] = "1. Ru";
                if (b == 1)
                    mparts[a][b] = "2. Eng";
            }
        }
    }

    while (run) {
        displaymenue(select, mparts, pt, user0);

        key = getchar();

        switch (key) {
        case 'q':
            run = false;
            break;

        case '3':
            if (pt == 0) {
                system("clear");
                exit(0);
            } else if (pt == 1) {
                user0->mode = (char*)"code";
                pt++;
            } else if (pt == 2) {
                user0->diff = (char*)"hard";
                pt++;
                if (strcmp(user0->mode, "code") == 0)
                    run = false;
            }
            break;

        case '2':
            if (pt == 0) {
                system("clear");
                std::cout << "\n\t\x1b[5;36m"
                          << "Check our repository for more info : "
                          << "\x1b[0m\n\n";
                std::cout << "https://github.com/trpo2021/"
                             "cw-iv-022_keyboardninja";
                std::cout << "\n\n\t\x1b[5;32m"
                          << "Follow the link (Сtrl + Сlick)"
                          << "\x1b[0m\n";
                sleep(5);
            } else if (pt == 1) {
                user0->mode = (char*)"sentences";
                pt++;
            } else if (pt == 2) {
                user0->diff = (char*)"normal";
                pt++;
                if (strcmp(user0->mode, "code") == 0)
                    run = false;
            } else if (pt == 3 && strcmp(user0->mode, "code") != 0) {
                user0->lang = (char*)"eng";
                run = false;
            }
            break;

        case '4':
            if (pt == 1) {
                user0->mode = (char*)"usermode";
                run = false;
            }
            break;

        case '1':
            if (pt == 0) {
                pt++;
            } else if (pt == 1) {
                user0->mode = (char*)"words";
                pt++;
            } else if (pt == 2) {
                system("clear");
                std::cout << "\x1b[5;31m\n\n\t"
                          << "Wrong difficulty level"
                          << "\x1b[0m" << std::endl;
                sleep(1);
            }
            break;

        default:
            break;
        }
    }

    for (int i = 0; i < 4; i++) {
        free((mparts)[i]);
    }
    free(mparts);

    modecycle(user0);

    return 0;
}

void displaymenue(int pos, const char*** meparts, int part, smode* user0)
{
    system("clear");

    std::cout << "\x1b[4;35m\t"
              << "KEYBOARD NINJA"
              << "\x1b[0m" << std::endl;
    if (part == 0) {
        std::cout << "\t" << meparts[part][pos] << std::endl;
        std::cout << "\t" << meparts[part][1] << std::endl;
        std::cout << "\t" << meparts[part][2] << std::endl;
    } else if (part == 1) {
        std::cout << "\t" << meparts[part][pos] << std::endl;
        std::cout << "\t" << meparts[part][1] << std::endl;
        std::cout << "\t" << meparts[part][2] << std::endl;
        std::cout << "\t" << meparts[part][3] << std::endl;
    } else if (part == 2) {
        std::cout << "\x1b[8;35m"
                  << "\t" << meparts[part][pos] << "\x1b[0m" << std::endl;
        std::cout << "\t" << meparts[part][1] << std::endl;
        std::cout << "\t" << meparts[part][2] << std::endl;
    } else if (part == 3) {
        std::cout << "\t"
                  << "\x1b[8;35m" << meparts[part][pos] << "\x1b[0m"
                  << std::endl;
        std::cout << "\t" << meparts[part][1] << std::endl;
    }
}

void input_username(smode* user0)
{
    system("clear");

    std::cout << "\x1b[5;35m"
              << "      Enter you username"
              << "\x1b[0m" << std::endl;
    std::cout << "  ";
    std::cout << "\x1b[4;31m\t"
              << "max 15 symbols"
              << "\x1b[0m" << std::endl;

    getchar();
    std::cin.getline(user0->username, 15);
    std::cin.clear();
}