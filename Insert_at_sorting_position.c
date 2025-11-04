
/*      
          ***** Insert at sorting position *****
 Input : Array of integer with the following values.

        int A[8] = {10, 20, 30, 40, 50, 60, 70, 15};
        int B[6] = {10, 20, 30, 40, 50, 35};
        int C[5] = {100, 200, 300, 400, 5};

 Output : int A[8] = {10, 15, 20, 30, 40, 50, 60, 70};
          int B[6] = {10, 20, 30, 35, 40, 50};
          int C[5] = {5, 100, 200, 300, 400};
    
*/

#include <stdio.h>

void insert_at_sorting_position (int Arr[], int size);
void display (int Arr[], int size, const char* Msg);

int main (void)
{
    int A[8] = {10, 20, 30, 40, 50, 60, 70, 15};
    int B[6] = {10, 20, 30, 40, 50, 35};
    int C[5] = {100, 200, 300, 400, 5};

    display (A, 8, "Displaying \'A\' before insert at sorting position : ");
    insert_at_sorting_position (A, 8);
    display (A, 8, "Displaying \'A\' after insert at sorting position : ");

    printf("\n");

    display (B, 6, "Displaying \'B\' before insert at sorting position : ");
    insert_at_sorting_position (B, 6);
    display (B, 6, "Displaying \'B\' after insert at sorting position : ");

    printf("\n");

    display (C, 5, "Displaying \'C\' before insert at sorting position : ");
    insert_at_sorting_position (C, 5);
    display (C, 5, "Displaying \'C\' after insert at sorting position : ");


    return (0);
}
void insert_at_sorting_position (int Arr[], int size)
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