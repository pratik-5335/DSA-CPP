/*
 Input : Array of 8 integer with the following values.

         A[8] = {10, 20, 30 40, 50, 60, 70, 80}
         B[8] = {100, 200, 300 400, 500 600, 700, 800}

 Goal : Learn to use C-function to generlize a logic.

        I should be able to display array of integer having "ANY" name and 
        "ANY" size using a single code.
       
 Output : A[8] = {10, 20, 30 40, 50, 60, 70, 80}
          B[8] = {100, 200, 300 400, 500 600, 700, 800}
*/

#include <stdio.h>

void display (int Arr[], int size, const char* Msg);

int main (void)
{
    int A[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int B[8] = {100, 200, 300, 400, 500, 600, 700, 800};
    int C[5] = {1000, 2000, 3000, 4000, 5000};

    display (A, 8, "PRINTING ARRAY A : \n");
    
    display (B, 8, "PRINTING ARRAY B : \n");
   
    display (C, 5, "PRINTING ARRAY C : \n");

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