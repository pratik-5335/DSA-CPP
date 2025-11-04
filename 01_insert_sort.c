#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void input (int* p_array, int size);
void output (int* p_array, int size, const char* Msg);
void sort (int* p_array, int size);

int main (void)
{
    int* a = NULL;
    int N = 0;

    printf("Enter size of array : ");
    scanf("%d", &N);

    if(N <= 0)
    {
        puts("Bad size for array : ");
        exit(EXIT_FAILURE);
    }

    a = (int*) malloc(N * sizeof(int));

    if(NULL == a)
    {
        puts("Out of memory");
        exit (EXIT_FAILURE);
    }

    input (a, N);
    output (a, N, "Displaying before insertion sort : ");
    sort (a, N);
    output (a, N, "Displaying after insertion sort : ");

    free (a);
    a = NULL;

    exit (EXIT_SUCCESS);
}

void input (int* p_array, int size)
{
    int cap = size * 10;
    int i;

    srand(time(0));

    i = 0;
    while (i < size)
    {
        p_array[i] = rand() % cap;
        i = i + 1; 
    }
    
}
void output (int* p_array, int size, const char* Msg)
{
    if(Msg != NULL)
    {
        puts(Msg);
    }

    int i;

    i = 0;
    while (i < size)
    {
    printf("a[%d] : %d\n", i, p_array[i]);
    i = i + 1;
    }
}
void sort (int* p_array, int size)
{
    int i, j;
    int key;

    j = 1;
    while(j < size)
    {
        key = p_array[j];
        i = j - 1;

        while (i > -1 && p_array[i] > key)
        {
            p_array[i + 1] = p_array[i];
            i = i - 1;
        }
        p_array[i + 1] = key;

        j = j + 1;
        
    }
}