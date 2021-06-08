#include "../keynlibs/mainlib.hpp"

void wmode_eng(std::ifstream* in, uint8_t lang, smode* user0)
{
    char** arr_words = (char**)malloc(COUNTWORDS * sizeof(char*));
    if (arr_words == NULL)
        return;

    for (int i = 0; i < COUNTWORDS; i++) {
        arr_words[i] = (char*)malloc(MAXWORD * sizeof(char));
        if (arr_words[i] == NULL) {
            for (int p = 0; p < i; p++) {
                free(arr_words[p]);
            }
            free(arr_words);
            return;
        }
    }

    char* ans_word = (char*)malloc(MAXWORD * sizeof(char));
    if (ans_word == NULL) {
        for (int p = 0; p < COUNTWORDS; p++) {
            free(arr_words[p]);
        }
        free(arr_words);
        return;
    }

    int* str_num = (int*)malloc(COUNTWORDS * sizeof(int));
    if (str_num == NULL) {
        for (int p = 0; p < COUNTWORDS; p++) {
            free(arr_words[p]);
        }
        free(arr_words);
        free(ans_word);
        return;
    }

    char* temp = (char*)malloc(MAXWORD * sizeof(char));
    if (temp == NULL) {
        for (int p = 0; p < COUNTWORDS; p++) {
            free(arr_words[p]);
        }
        free(arr_words);
        free(ans_word);
        return;
    }
    rand_num_15(str_num);

    int i = 0, count = 0;
    while (i < COUNTWORDS) {
        if (str_num[i] != count) {
            in->getline(temp, MAXWORD, '\n');
        } else {
            in->getline(arr_words[i], MAXWORD, '\n');
            i++;
        }
        count++;
    }

    readusansw_uscode(arr_words, &ans_word, COUNTWORDS, ENG, user0);

    for (int p = 0; p < COUNTWORDS; p++) {
        free(arr_words[p]);
    }
    free(arr_words);
    free(str_num);
    free(temp);
}

int rand_num_15(int* arr)
{
    srand(time(NULL));

    for (int i = 0; i < COUNTWORDS; i++) {
        arr[i] = rand() % 2000;

        for (int p = 0; p < i; p++) {
            if (arr[i] == arr[p]) {
                i--;
            }
        }
    }
    bubble_sort(arr, COUNTWORDS);
    return 1;
}

void bubble_sort(int* array, int n)
{
    int t;
    int i = 1;
    while (i == 1) {
        i = 0;
        for (int j = 1; j < n; j++) {
            if (array[j - 1] > array[j]) {
                t = array[j - 1];
                array[j - 1] = array[j];
                array[j] = t;
                i = 1;
            }
        }
    }
}

void wmode_ru(smode* user0)
{
    char** arr_words = (char**)malloc(15 * sizeof(char*));
    if (arr_words == NULL)
        return;

    char* ans_word = (char*)malloc(MAXWORD * sizeof(char));
    if (ans_word == NULL) {
        for (int p = 0; p < COUNTWORDS; p++) {
            free(arr_words[p]);
        }
        free(arr_words);
        return;
    }

    int* str_num = (int*)malloc(COUNTWORDS * sizeof(int));
    if (str_num == NULL) {
        for (int p = 0; p < COUNTWORDS; p++) {
            free(arr_words[p]);
        }
        free(arr_words);
        free(ans_word);
        return;
    }

    rand_num_15(str_num);

    write_words(arr_words, str_num, user0->mode);
    // readusansw_uscode(arr_words, &ans_word, COUNTWORDS, RU);
    sleep(20);
}

int write_words(char** all_str, int* num_str, const char* mode)
{
    std::ifstream in;
    if (strcmp(mode, "normal") == 0) {
        in.open("../inputtxt/Words/Words_Medium_Ru.txt");
    } else {
        in.open("../inputtxt/Words/Words_Hard_Ru.txt");
    }

    if (!in) {
        return -1;
    }

    char* temp = (char*)malloc(MAXWORD * sizeof(char));
    if (temp == NULL) {
        in.close();
        return -1;
    }

    int count = 0;
    int i = 0;

    while (!in.eof()) {
        if (num_str[i] == count) {
            all_str[i] = (char*)malloc(MAXWORD * sizeof(char));

            in.get(all_str[i], MAXWORD);
            i++;
            if (in.eof()) {
                break;
            }
        } else {
            in.getline(temp, MAXWORD, '\n');
        }
        if (i == COUNTWORDS) {
            break;
        }
        count++;
    }

    in.close();
    free(temp);
    return 1;
}
