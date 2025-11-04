#include <stdio.h>

void right_rotate (int Arr[], int size);
void display (int Arr[], int size, const char* Msg);

int main (void)
{
    int A[8] = {10, 20, 30, 40, 50, 60, 70, 0};
    int B[6] = {100, 200, 300, 400, 500, 0};
    int C[4] = {1000, 2000, 3000, 0};

    display (A, 8, "Showing array \'A\' before right shift and rotate : \n");
    right_rotate (A, 8);
    display (A, 8, "Showing array \'A\' after right shift and rotate : \n");

    display (B, 6, "Showing array \'B\' before right shift and rotate : \n");
    right_rotate (B, 6);
    display (B, 6, "Showing array \'B\' after right shift and rotate : \n");

    display (C, 4, "Showing array \'C\' before right shift and rotate : \n");
    right_rotate (C, 4);
    display (C, 4, "Showing array \'C\' after right shift and rotate : \n");

    return (0);
}
void right_rotate (int Arr[], int size)
{
    int tmp = Arr[size - 1];

    int i = size - 2;
    while (i >= 0)
    {
        Arr[i + 1] = Arr[i];
        i = i - 1;
    }
    Arr[i + 1] = tmp;
}

void display (int Arr[], int size, const char* Msg)
{
    if(Msg != NULL)
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