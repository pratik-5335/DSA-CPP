//  DYNAMIC MEMORY ALLOCATION TECHINQUE  (Malloc free and exit) ......

#include <stdio.h>      // For declaration of printf()
#include <stdlib.h>    //  For declae=rtion of malloc(), free() and exit()
#include <string.h>    // for declaration of memset

struct Date
{
    int Day;
    int Month;
    int Year;
};

struct array
{
    int* a;
    int N;
};

void dynamic_builtin();
void dynamic_defined_date();
void dynamic_user_defined_array();

int main (void)
{
    dynamic_builtin();
    dynamic_defined_date ();
    dynamic_user_defined_array ();

    return (0);
}

void dynamic_builtin(void)
{
    int* ptr = NULL;   // Step 1 : Declare a pointer and initilize it to NULL

    ptr = (int*) malloc(sizeof(int));   /* Step 2 : Allocte dynamic memory using malloc() and do 
                                                    validation check */ 

    if(NULL == ptr)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }

      memset (ptr, 0, sizeof(int));   //Step 3 : Initilize allocated instance to 0

        // Step 4,5 : Read/Write on dynamically allocated instance.
        *ptr = 100;     // Write operation
         //int n = *ptr;   // Read operation

        printf("*Ptr = %d\n", *ptr);    // Read operation

        free (ptr);  // Step 6 : When dynamic instance is no longer wanted
        ptr = NULL;    // Release it and make pointer NULL again
}
void dynamic_defined_date(void)
{
    struct Date* newdate = NULL;   // Step 1

    newdate = (struct Date*) malloc(sizeof(struct Date));   // Step 2

    if(newdate == NULL)
    {
        puts("Out of memory");
        exit (EXIT_FAILURE);
    }

    memset(newdate, 0, sizeof(struct Date));    // Step 3
    // Step 4, 5
    //newdate->Day = 8;
    (*newdate).Day = 8;
    //newdate->Month = 10;
    (*newdate).Month = 10;
    //newdate->Year = 2025;
    (*newdate).Year = 2025;

    printf("%d-%d-%d\n", newdate->Day, newdate->Month, newdate->Year);

    free (newdate);  // Step 6
    newdate = NULL;

}
void dynamic_user_defined_array (void)
{
    struct array *p_array = NULL;    // Step 1

    p_array = (struct array*) malloc(sizeof(struct array));    // Step 2

    if (NULL == p_array)
    {
        puts("Out of memory");
        exit (EXIT_FAILURE);
    }

    p_array->N = 8;     
    p_array-> a = (int*)malloc(sizeof(struct array));  

    if (NULL == p_array->a)
    {
        puts("Out of memory");
        exit (EXIT_FAILURE);
    }
       
    int i;

    for (i = 0; i < p_array->N; ++i)
    {
        p_array->a[i] = (i + 1) * 10;
    }
    
    printf("Showing Array : \n");
        
    for(i = 0; i < p_array->N; ++i)
    {
        printf("P_array -> a[%d] : %d\n", i, p_array->a[i]);
    }
            
    free (p_array->a);
    p_array->a = NULL;

    free(p_array);
    p_array = NULL;
}
