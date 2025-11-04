
/*
 Input : Array of integer with the following values.

         int A[10] = {-10, -20, -25, 40, 50, 60, 70, 80, 90, 30};
         int B[6] = {-100, -200, 400, 500, 600, 300};
         int C[5] = {1000, 2000, 3000, 4000, 5000};

 Goal : You will be given a non-empty array of integer,
        The array i filled in such a way that all negative .
        Numbers are stracked on the left side of the array.
        And all non-negtive numbers are stracked on the right side of the array.

        Your job is to right shift and rotate all non-negative elements.

 @boundary case - there may not be any negtive element.In that case the entire 
                         array will be right shifted and rotate. 

 Output : int A[10] = {-10, -20, -25, 30, 40, 50, 60, 70, 80, 90};
          int B[6] = {-100, -200, 300, 400, 500, 600};
          int C[5] = {5000, 1000, 2000, 3000, 4000};
    
*/

#include <stdio.h>

void rotate_right (int Arr[], int size);
void display (int Arr[], int size, const char* Msg);

int main (void)
{
    int A[10] = {-10, -20, -25, 40, 50, 60, 70, 80, 90, 30};
    int B[6] = {-100, -200, 400, 500, 600, 300};
    int C[5] = {1000, 2000, 3000, 4000, 5000};

    display (A, 10, "SHOWING ARRAY \'A\' BEFORE SHIFTING POSITIVE NUMBERS TO THE RIGHT : ");
    rotate_right (A, 10);
    display (A, 10, "SHOWING ARRAY \'A\' AFTER SHIFTING POSITIVE NUMBERS TO THE RIGHT : ");

    printf("\n");

    display (B, 6, "SHOWING ARRAY \'B\' BEFORE SHIFTING POSITIVE NUMBERS TO THE RIGHT : ");
    rotate_right (B, 6);
    display (B, 6, "SHOWING ARRAY \'B\' AFTER SHIFTING POSITIVE NUMBERS TO THE RIGHT : ");

    printf("\n");

    display (C, 5, "SHOWING ARRAY \'C\' BEFORE SHIFTING POSITIVE NUMBERS TO THE RIGHT : ");
    rotate_right (C, 5);
    display (C, 5, "SHOWING ARRAY \'C\' AFTER SHIFTING POSITIVE NUMBERS TO THE RIGHT : ");

    return (0);
}

void rotate_right (int Arr[], int size)
{
    int tmp = Arr[size - 1];

    int i = size - 2;
    while (Arr[i] >= 0 && i >= 0)
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
    while(i < size)
    {
        printf("Arr[%d] : %d\n", i, Arr[i]);
        i = i + 1;
    }
}