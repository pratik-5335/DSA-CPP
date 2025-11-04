/*
 Input : Array of  integer with the following values.

         int A[10] = {-5, -15, -20, 40, 50, 60, 70, 80, 90, 30}

 Goal : Keep shifting array elements to their last index, untill negative element to their 
        right index.
Assumptions : there is at least one negative number
        
       
 Output : int A[10] = {-5, -15, -20, 30, 40, 50, 60, 70, 80, 90}     
*/

#include <stdio.h>

void display (int Arr[], int size, const char* Msg);

int main (void)
{
    int A[10] = {-5, -15, -20, 40, 50, 60, 70, 80, 90, 30};

    display (A, 10, "SHOWING ARRAY \'A\' BEFORE SHIFTING POSITIVE NUMBERS TO THE RIGHT : ");
    
    int tmp = A[9];

    int i = 8;

    while(A[i] >= 0)
    {
        A[i + 1] = A[i];
        i = i - 1;
    }
    A[i + 1] = tmp;

    display (A, 10, "SHOWING ARRAY \'A\' AFTER SHIFTING POSITIVE NUMBERS TO THE RIGHT : ");

    return (0);
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