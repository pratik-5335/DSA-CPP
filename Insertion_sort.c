/*      
          ***** Insertion sort *****
 Input : Array of integer with the following values.

        int A[8] = {30, 52, 22, 57, 12, 43, 60, 10};
        int B[6] = {700, 243, 1000, 100, 191, 500};
        int C[5] = {10000, 300, 2000, 500, 9999};

 Output : int A[8] = {10, 12, 22, 30, 43, 52, 57, 60};
          int B[6] = {100, 191, 243, 500, 700, 1000};
          int C[5] = {300, 500, 2000, 9999, 10000};
    
*/
#include <stdio.h>

void Insert_at_sorting_position (int Arr[], int size);
void Insertion_sort (int Arr[], int size);
void display (int Arr[], int size, const char* Msg);

int main (void)
{
    int A[8] = {30, 52, 22, 57, 12, 43, 60, 10};
    int B[6] = {700, 243, 1000, 100, 191, 500};
    int C[5] = {10000, 300, 2000, 500, 9999};

    display (A, 8, "Displaying \'A\' before insertion sort : ");
    Insertion_sort (A, 8);
    display (A, 8, "Displaying \'A\' after insertion sort : ");

    printf("\n");

    display (B, 6, "Displaying \'B\' before insertion sort : ");
    Insertion_sort (B, 6);
    display (B, 6, "Displaying \'B\' after insertion sort : ");

    printf("\n");

    display (C, 5, "Displaying \'C\' before insertion sort : ");
    Insertion_sort (C, 5);
    display (C, 5, "Displaying \'C\' after insertion sort : ");

    return (0); 
}

void Insert_at_sorting_position (int Arr[], int size)
{
    int tmp = Arr[size - 1];

    int i = size - 2;
    while (i >= 0 && Arr[i] >= tmp)
    {
        Arr[i + 1] = Arr[i];
        i = i - 1;
    }
    Arr[i + 1] = tmp;
    
}

void Insertion_sort (int Arr[], int size)
{
    int sub_array;
    sub_array = 2;

    while (sub_array <= size)
    {
        Insert_at_sorting_position (Arr, sub_array);
        sub_array = sub_array + 1;
    }
    
}

void display (int Arr[], int size, const char* Msg)
{
    if (Msg != NULL)
    {
        puts(Msg);
    }

    int i;

    i = 0;
    while (i < size)
    {
        printf("Arr[%d] : %d\n", i, Arr[i]);
        i = i + 1;
    }
    
}