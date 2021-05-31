#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

enum {
    MAXCODELENS = 72,
    MAXCODESTRINGS = 30,
    MAXUSERLEN = 128,
    ENG = 1,
    RU = 2,
    CODENUM = 10,
    MAXWORD = 128,
    COUNTSENT = 20,
    MAXSENT = 200,
    COUNTWORDS = 15
};

typedef struct smode {
    const char* mode;
    const char* diff;
    const char* lang;
    char* username;

} SelectedMode;

void displaymenue(int pos, const char*** meparts, int part, smode* user0);
int menue(smode* user0);
void input_username(smode* user0);
void display_sarr(char** cstrings, int x, int snumber);
void display_results(
        time_t start,
        time_t stop,
        int sleeps,
        int fails,
        int sym,
        smode* user0);

void wmode_eng(std::ifstream* in, uint8_t lang, smode* user0);
void wmode_ru(smode* user0);
void open_file_eng(smode* user, std::ifstream* in);
void bubble_sort(int* array, int n);
int rand_num_15(int* arr);
int write_words(char** all_str, int* num_str, const char* mode);

void smode_eng(std::ifstream* in, smode* user0);

int umode(uint8_t lang, smode* user0);
int findsize();
int writefile();
int read_usermode(char** cstrings);

int cmode(uint8_t lang, smode* user0);
int read_code(char** cstrings, int num, const char* md);

int scompare(char* cstring, char* userstring, uint8_t lang, int* fails);
int readusansw_uscode(
        char** cstrings,
        char** userstrings,
        int uscount,
        uint8_t lang,
        smode* user0);
void modecycle(smode* user0);

double count_percent_miss(int fails, int sim);
double count_coefficient_miss(double persent_miss);
double speed_print(int sym, int time);
double count_score(smode* user0, int speed, double coefficient_miss);
int rangs(double score);

int slen(char* str);
int lencount(char** str, int count);