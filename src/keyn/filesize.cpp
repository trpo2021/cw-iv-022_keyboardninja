#include "../keynlibs/mainlib.hpp"

int findsize()
{
    std::ifstream input;
    input.open("../inputtxt/usermode/usermode.txt");

    int fsize = 0;

    char* temp = (char*)malloc(MAXUSERLEN * sizeof(char));

    while (!input.eof()) {
        input.getline(temp, MAXUSERLEN);

        if (input.eof())
            break;

        input.clear();

        fsize++;
    }
    input.close();
    free(temp);
    return fsize;
}