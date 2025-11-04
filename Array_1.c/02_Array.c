/*
 Input : Array of 8 integer with the following values.

         Arr[8] = {10, 20, 0 40, 50, 60, 70, 0}

 Goal : shift all array element to the one place right and at the end the element
       at last index must be written at index 0.
       
 Output : Arr[8] = {0, 10, 20 30, 4, 50, 60, 70}      
*/
#include <stdio.h>

int main(void)
{
    int Arr[8] = {10, 20, 30, 40, 50, 60, 70, 0};

    int i;

    printf("SHOWING ARRAY BEFORE SHIFTTNG ELEMENTS TO RIGHT : \n");

    i = 0;
    while (i < 8)
    {
        printf("Arr[%d] : %d\n", i, Arr[i]);
        i = i + 1;
    }

    // declare tmp variable to store the value of last index
    int tmp = Arr[7];

    i = 6;
    while (i >= 0)
    {
        Arr[i + 1] = Arr[i];
        i = i - 1;
    }

    printf("JUST AFTER GETTING OUT OF WHILE LOOP : i = %d\n", i);

    Arr[i + 1] = tmp;
    
    printf("SHOWING ARRAY AFTER SHIFTTNG ELEMENTS TO RIGHT : \n");

    i = 0;
    while (i < 8)
    {
        printf("Arr[%d] : %d\n", i, Arr[i]);
        i = i + 1;
    }
    return (0);
}