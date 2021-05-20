#include "../keynlibs/mainlib.hpp"

int findsize() {

    ifstream input;
    input.open("../inputtxt/usermode/usermode.txt");

    int fsize = 0;

    char *temp = (char *)malloc(MAXCODELENS*sizeof(char));

    while (input) {
        input.getline(temp, MAXCODELENS);

        if (input.eof())
            break;

        fsize++;
    }
    input.close();
    free(temp);
    return fsize;
}