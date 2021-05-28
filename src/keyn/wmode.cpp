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
