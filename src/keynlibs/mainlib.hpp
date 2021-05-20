#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <cstring>

using namespace std;

enum {

    MAXCODELENS = 72,
    MAXCODESTRINGS = 30

};

typedef struct smode {

    const char *mode;
    const char *diff;
    const char *lang;
    char *username;

} SelectedMode;

void displaymenue(int pos, const char ***meparts, int part, smode *user0);
int menue(smode *user0);
void input_username(smode *user0);

void words_easy();
void words_normal();
void read_words();
void words_compare();
void words_display();

void sentences_easy();
void sentensec_normal();
void sentences_hard();
void read_sentences();
void sentences_compare();
void sentences_display();

int umode();
int findsize();
int writefile();
int read_usermode(char **cstrings);

int code_normal();
int code_hard();
//Массив строк, в который происходит чтение, номер рандомного кода, уровень сложности
int read_code(char **cstrings, int num, const char *md);

int code_compare(char *cstring, char * userstring);
//x - номер строки, y - номер символа
void code_display(char **cstrings, int x, int y, int ncolor, int snumber);

int read_user_answer_code(char **cstrings, char **userstrings, int uscount);
void modecycle(smode *user0);