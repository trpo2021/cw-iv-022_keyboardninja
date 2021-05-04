#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <cstring>

using namespace std;

typedef struct smode {

    const char *mode;
    const char *diff;
    char *username;

} SelectedMode;

void displaymenue(int pos, const char ***meparts, int part, smode *user0);
int menue(smode *user0);

void words_easy();
void words_normal();

void sentences_easy();
void sentensec_normal();
void sentences_hard();

void code_normal();
void code_hard();