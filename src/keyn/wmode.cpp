//Word Mode
#include "../keynlibs/mainlib.hpp"

void wmode_eng(ifstream *in, uint8_t lang, smode *user0)
{
    //system("clear");
    //выделение памяти под массив слов и строку для ответов, и для массива чисел.
    char **arr_words = (char **)malloc(15 * sizeof(char *));
    if (arr_words == NULL)
        return;

    for (int i = 0; i < 15; i++)
    {
        arr_words[i] = (char *)malloc(MAXWORD * sizeof(char));
        if (arr_words[i] == NULL)
        {
            for (int p = 0; p < i; p++)
            {
                free(arr_words[p]);
            }
            free(arr_words);
            return;
        }
    }

    char *ans_word = (char *)malloc(MAXWORD * sizeof(char));
    if (ans_word == NULL)
    {
        for (int p = 0; p < 15; p++)
        {
            free(arr_words[p]);
        }
        free(arr_words);
        return;
    }

    int *str_num = (int *)malloc(15 * sizeof(int));
    if (str_num == NULL)
    {
        for (int p = 0; p < 15; p++)
        {
            free(arr_words[p]);
        }
        free(arr_words);
        free(ans_word);
        return;
    }

    char *temp = (char *)malloc(MAXWORD * sizeof(char));
    if (temp == NULL)
    {
        for (int p = 0; p < 15; p++)
        {
            free(arr_words[p]);
        }
        free(arr_words);
        free(ans_word);
        return;
    }
    //рандомное заполнение массива чисел. причем числа = номер строки в файле
    rand_num_15(str_num);

    //запись в двумерный массив
    int i = 0, count = 0;
    while (i < 15)
    {
        if (str_num[i] != count)
        {
            in->getline(temp, MAXWORD, '\n');
        }
        else
        {
            in->getline(arr_words[i], MAXWORD, '\n');
            i++;
        }
        count++;
    }

    readusansw_uscode(arr_words, &ans_word, 15, ENG, user0);
}

int rand_num_15(int *arr)
{
    srand(time(NULL));

    for (int i = 0; i < 15; i++)
    {
        arr[i] = rand() % 100;

        for (int p = 0; p < i; p++)
        {
            if (arr[i] == arr[p])
            {
                i--;
            }
        }
    }
    bubble_sort(arr, 15);
    return 1;
}

void bubble_sort(int *array, int n)
{
    int t;
    int i = 1;
    while (i == 1)
    {
        i = 0;
        for (int j = 1; j < n; j++)
        {
            if (array[j - 1] > array[j])
            {
                t = array[j - 1];
                array[j - 1] = array[j];
                array[j] = t;
                i = 1;
            }
        }
    }
}

void read_ans(char *ans)
{
    cout << "->";
    fgets(ans, MAXWORD + 1, stdin);
}

void wmode_ru(smode *user0)
{
    //system("clear");
    //выделение памяти под массив слов и строку для ответов, и для массива чисел.
    char **arr_words = (char **)malloc(15 * sizeof(char *));
    if (arr_words == NULL)
        return;

    // for (int i = 0; i < 15; i++)
    // {
    //     arr_words[i] = (char *)malloc(MAXWORD * sizeof(char));
    //     if (arr_words[i] == NULL)
    //     {
    //         for (int p = 0; p < i; p++)
    //         {
    //             free(arr_words[p]);
    //         }
    //         free(arr_words);
    //         return;
    //     }
    // }

    char *ans_word = (char *)malloc(MAXWORD * sizeof(char));
    if (ans_word == NULL)
    {
        for (int p = 0; p < 15; p++)
        {
            free(arr_words[p]);
        }
        free(arr_words);
        return;
    }

    int *str_num = (int *)malloc(15 * sizeof(int));
    if (str_num == NULL)
    {
        for (int p = 0; p < 15; p++)
        {
            free(arr_words[p]);
        }
        free(arr_words);
        free(ans_word);
        return;
    }
    //рандомное заполнение массива чисел. причем числа = номер строки в файле
    rand_num_15(str_num);

    //запись в двумерный массив
    write_words(arr_words, str_num, user0->mode);
    // readusansw_uscode(arr_words, &ans_word, 15, RU);
    //write_user_words(arr_words, ans_word);
    sleep(20);
}

int write_words(char **all_str, int *num_str, const char *mode)
{
    ifstream in;
    if (strcmp(mode, "normal") == 0)
    {
        in.open("../inputtxt/Words/Words_Medium_Ru.txt");
    }
    else
    {
        in.open("../inputtxt/Words/Words_Hard_Ru.txt");
    }

    if (!in)
    {
        return -1;
    }

    char *temp = (char *)malloc(MAXWORD * sizeof(char));
    if (temp == NULL)
    {
        in.close();
        return -1;
    }

    int count = 0;
    int i = 0;

    while (!in.eof())
    {

        if (num_str[i] == count)
        {
            all_str[i] = (char *)malloc(MAXWORD * sizeof(char));

            in.get(all_str[i], MAXWORD);
            i++;
            if (in.eof())
            {
                break;
            }
        }
        else
        {
            in.getline(temp, MAXWORD, '\n');
        }
        if (i == 15)
        {
            break;
        }
        count++;
    }

    in.close();
    free(temp);
    return 1;
}

void write_user_words(char **all_str, char *ans)
{
    system("clear");
    int i = 0;
    while (i < 15)
    {
        cout << all_str[i] << "\n";
        while (1)
        {
            cin.getline(ans, MAXWORD, '\n');
            // if ((scompare(all_str[i], ans, RU)) == 0)
            // {
            //     cout << "TRY AGAIN\n";
            // }
            // else
            // {
            //     break;
            // }

            if (strcmp(all_str[i], ans) != 0)
            {
                cout << "TRY AGAIN\n";
            }
            else
            {
                break;
            }
        }
        i++;
        system("clear");
        cin.clear();
    }
}