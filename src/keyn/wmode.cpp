//Word Mode
#include "../keynlibs/mainlib.hpp"

void wmode(ifstream *in, uint8_t lang)
{
    int *numbers = NULL;
    numbers = (int *)malloc(15 * sizeof(int));
    rand_num_15(numbers); // на этом моменте есть отсотритованный массив из 15 элементов.

    char *str = NULL;
    str = (char *)malloc(MAXWORD * sizeof(char));

    char *ans = NULL;
    ans = (char *)malloc(MAXWORD * sizeof(char));

    bool to_cycle = 1;
    int count = 0, i = 0;
    while (to_cycle)
    {
        while (i != numbers[count])
        {
            i++;
            in->getline(str, MAXWORD, '\n');
        }

        do
        {
            system("clear");
            cout << str << endl;
            // read_ans(ans);
            cin.getline(ans, MAXWORD, '\n');
            cout << "\n";
            if (scompare(str, ans, 1) == 1)
                break;
        } while (1);

        count++;
        if (count == 15)
        {
            to_cycle = 0;
        }
    }
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

// int compare_str(char *str, char *ans)
// {
//     int check = 0;
//     int k = 0;
//     while (str[k] != '\0')
//     {
//         if ((str[k] != ans[k]))
//         {
//             check = 1;
//         }
//         k++;
//     }

//     if (check == 0)
//     {
//         cout << "\x1b[5;36m" << ans << "\x1b[0m" << endl;
//         sleep(2);
//         return 0;
//     }
//     else
//     {
//         for (int i = 0; i < MAXWORD; i++)
//         {
//             if (str[i] == ans[i])
//             {
//                 cout << "\x1b[5;32m" << ans[i] << "\x1b[0m";
//             }
//             else
//             {
//                 cout << "\x1b[5;31m" << ans[i] << "\x1b[0m";
//             }
//         }
//         cout << "\n";
//         return 1;
//     }
// }

// int compare_ru(char *str, char *ans)
// {
//     if (strcmp(str, ans) == 0)
//     {
//         cout << "\x1b[5;36m" << ans << "\x1b[0m" << endl;
//         return 0;
//     }
//     else
//     {
//         cout << "\x1b[5;31m" << ans << "\x1b[0m";
//         return 1;
//     }
// }