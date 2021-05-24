#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <cstring>

using namespace std;

enum {

    MAXCODELENS = 72,
    MAXCODESTRINGS = 30,
    MAXUSERLEN = 128,
    ENG = 1,
    RU = 2,
    CODENUM = 10
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

int umode(uint8_t lang);
int findsize();
int writefile();
int read_usermode(char **cstrings);

int code_normal(uint8_t lang);
int code_hard(uint8_t lang);
//Массив строк, в который происходит чтение, номер рандомного кода, уровень сложности
int read_code(char **cstrings, int num, const char *md);

int scompare(char *cstring, char * userstring, uint8_t lang);
void display_sarr(char **cstrings, int x, int snumber);
int readusansw_uscode(char **cstrings, char **userstrings, int uscount, uint8_t lang);
void modecycle(smode *user0);