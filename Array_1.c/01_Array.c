// Create and initilize the array, then display it using a for loop.
#include <stdio.h>

int Arr[8];

int main ()
{
    int i;
    i = 0;
    while (i < 8)
    {
        Arr[i] = (i + 1) * 10;
        i = i + 1;
    }
    printf("CRAEATE AND INITILIZE THE ARRAY, THEN DISPLAY IT USING FOR LOOP : \n");
    
    i = 0;
    while (i < 8)
    {
        printf("Arr[%d] : %d\n", i, Arr[i]);
        i = i + 1;
    }
    
    return (0);
}