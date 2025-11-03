/* Header files */
#include <stdio.h>    
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Symbolic constants */
#define SUCESS                1
#define TRUE                  1
#define FALSE                 0
#define LIST_DATA_NOT_FOUND   2
#define LIST_EMPTY            3

/* Node layout definition */
struct node
{
    int data;
    struct node* next;
};

/* Interface functions declarations */
/* List creation function */
struct node* create_list (void);

/* Data addition functions */
int insert_start (struct node* p_list, int new_data);
int insert_end (struct node* p_list, int new_data);
int insert_after (struct node* p_list, int existing_data, int new_data);
int insert_before (struct node* p_list, int existing_data, int new_data);

/* Get functions */
int get_start (struct node* p_list, int* p_start_data);
int get_end (struct node* p_list, int* p_end_data);

/* Pop functions */
int pop_start (struct node* p_list, int* p_start_data);
int pop_end (struct node* p_list, int* p_end_data);

/* Remove functions */
int remove_start (struct node* p_list);
int remove_end (struct node* p_list);
int remove_data (struct node* p_list, int r_data);

/* Miscallaneous functions */
int find (struct node* p_list, int f_data);
int get_list_length (struct node* p_list);
int is_list_empty (struct node* p_list);
void show_list (struct node* p_list, const char* Msg);

/* List destruction function */
int destroy_list (struct node* p_list);

/* Client of linked list */
int main (void)
{
    struct node* p_list = NULL;

        int status;
        int data;
        int start_data, end_data;
        int length;

    static const char* line = "-----------------------------------------------------------------";

    p_list = create_list();
    assert(p_list != NULL);
    printf("List create sucessfully \n");
    puts(line);

    printf("Testing assertions on the empty list \n");

    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);
    assert(get_start(p_list, &start_data) == LIST_EMPTY);
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY);
    assert(pop_end(p_list, &end_data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);

    printf("All assertions on the empty list are sucessfully \n");
    puts(line);

    show_list(p_list, "Showing empty list immediaterly_afer creation :");
    puts(line);

    for(data = 0; data < 5; ++data)
    {
        status = insert_start(p_list, data * 10);
        assert(status == SUCESS);
        printf("Inserted sucessfully at the start of the list %d \n", data * 10);

    }

    show_list(p_list, "showing list afte inserting 5 data elements at the start :");
    puts(line);

    for(data = 1; data <= 5; ++data)
    {
        status = insert_end(p_list, data * 5);
        assert(status == SUCESS); 
        printf("Inserted sucessfully at the start of the list %d \n", data * 5);

    }

    show_list(p_list, "showing list afte inserting 5 data elements at the end :");
    puts(line);

    status = insert_after(p_list, -5, 100);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 100 after non-existent data -5 \n");
    puts(line);

    status = insert_after(p_list, 0, 100);
    assert(status == SUCESS);
    show_list(p_list, "Showing list after sucessfully inserting 100 after 0");

    status = insert_before(p_list, 43, 200);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Excepted failure to insert data 200 afer non-eistent data 43\n");
    puts(line);

    status = insert_before(p_list, 0, 200);
    assert(status == SUCESS);
    show_list(p_list, "Showing list after sucessfuly insertng 200 before 0 : ");
    puts(line);

    status = get_start(p_list, &start_data);
    assert(status == SUCESS);
    printf("Data at the start = %d\n", start_data);
    show_list(p_list, "Showing list ti demostrate that get_start() returns the start data withou removing :");
    puts(line);

    status = get_end(p_list, &end_data);
    assert(status == SUCESS);
    printf("Data at the start = %d\n", end_data);
    show_list(p_list, "Showing list ti demostrate that get_end() returns the start data withou removing :");
    puts(line);

    status = pop_start(p_list, &start_data);
    assert(status == SUCESS);
    printf("Data at the start = %d\n", start_data);
    show_list(p_list, "Showing list ti demostrate that pop_start() removes and returns the start data :");
    puts(line);

    status = pop_end(p_list, &end_data);
    assert(status == SUCESS);
    printf("Data at the end = %d\n", end_data);
    show_list(p_list, "Showing list to demostrate that pop_end() removes and returns the end data :");
    puts(line);

    status = remove_start(p_list);
    assert(status == SUCESS);
    show_list(p_list, "Showing list after remove_start() :");
    puts(line);

    status = remove_end(p_list);
    assert(status == SUCESS);
    show_list(p_list, "Showing list after remove_end() :");
    puts(line);

    status = remove_data(p_list, 78);
    assert(status == LIST_DATA_NOT_FOUND);
    show_list(p_list, "Excepted error in removing non-existent data 78\n");
    puts(line);

    status = remove_data(p_list, 0);
    assert(status == SUCESS);
    show_list(p_list, "Showing list after removeing existing data 0:\n");
    puts(line);

    status = find(p_list, 91);
    assert(status == FALSE);
    printf("excepted return value FALSE from find() for non-existent data 91\n");
    puts(line);

    status = find(p_list, 100);
    assert(status == TRUE);
    printf("excepted return value TRUE from find() for existing  data 100\n");
    puts(line);

    status = is_list_empty(p_list);
    assert(status == FALSE);
    printf("Excepted return value FALSE from is_list_empty() \n");
    puts(line);

    length = get_list_length(p_list);
    printf("Length of the list = %d\n", length);
    puts(line);

    status = destroy_list(p_list);
    assert(status == SUCESS);
    p_list = NULL;
    printf("List is destroyed sucessfully \n");
    puts(line);

    return (0);

}

/* Server of linked list */

/* List creation function */
struct node* create_list (void)
{
    struct node* head_node = NULL;

    head_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == head_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data = 0;
    head_node -> next = NULL;

    return (head_node);
}

/* Data addition functions */
int insert_start (struct node* p_list, int new_data)
{
    struct node* new_node = NULL;

    new_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = p_list -> next;
    p_list -> next = new_node;

    return (SUCESS);
}

int insert_end (struct node* p_list, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;

    // step-1 : Allocate and initilize new node.
    new_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = NULL;

    //step-2 : Locate the last node.
    run = p_list;
    while(run -> next != NULL)
    {
        run = run -> next;
    }

    //step-3 : Append the new node at the last position.
    run -> next = new_node;
    
    return (SUCESS);

}

int insert_after (struct node* p_list, int existing_data, int new_data)
{
    struct node* existing_node = NULL;
    struct node* new_node = NULL;
    struct node* run = NULL;

    //step-1 : Search for the node contaning the first occurrence of the existing data.
    run = p_list -> next;
    while (run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }
        run = run -> next;
    }

    // If existing data is not found then return error as such.
    if(NULL == run)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    //step-2 : Allocate and initilize new node 
    existing_node = run;
    
    new_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }
    new_node -> data = new_data;

    //step-3 : Insert the new node at its appropriate position.
    new_node -> next = existing_node -> next;
    existing_node -> next = new_node;
    
    return (SUCESS);
}

int insert_before (struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;
    struct node* new_node = NULL;

    //step-1 : Search for the first occurrence of the existin data.
    //         maintaing the bck pointer.
    run_previous = p_list;
    run = p_list -> next;
    while (run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }

        run_previous = run;
        run = run -> next;
    }

    // If the existing data is not found throughout the list then return an error
    // saying as such.

    if(run == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    //step-2 : Allocate and initilze the new node.
    new_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;

    //step-3 : Insert the new node at the appropriate position.
    new_node -> next = run;
    run_previous -> next = new_node;

    return (SUCESS);

}

/* Get functions */
int get_start (struct node* p_list, int* p_start_data)
{
    if (p_list -> next == NULL)
    {
        return(LIST_EMPTY);
    }

    *p_start_data = p_list -> next -> data;

    return (SUCESS);

}

int get_end (struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;

    if(p_list -> next == NULL)
    {
        return (LIST_EMPTY);
    }

    run = p_list -> next;

    while (run -> next != NULL)
    {
        run = run -> next;
    }

    *p_end_data = run -> data;

    return (SUCESS);

}

/* Pop functions */
int pop_start (struct node* p_list, int* p_start_data)
{
    struct node* delete_previous = NULL;
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;

    if(p_list -> next == NULL)
    {
        return (LIST_EMPTY);
    }

    *p_start_data = p_list -> next -> data;

    delete_previous = p_list;
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;

    delete_previous -> next = delete_next;

    free (delete_node);
    delete_node = NULL;

    return (SUCESS);

}

int pop_end (struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(p_list -> next == NULL)
    {
        return(LIST_EMPTY);
    }

    run_previous = p_list;
    run = p_list -> next;

    while (run -> next != NULL)
    {
        run_previous = run;
        run = run -> next;
    }

    *p_end_data = run -> data;

    free(run);
    run = NULL;
    run_previous -> next = NULL;

    return (SUCESS);
}

/* Remove functions */
int remove_start (struct node* p_list)
{
    struct node* delete_previous = NULL;
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;

    if(p_list -> next == NULL)
    {
        return (LIST_EMPTY);
    }

    delete_previous = p_list;
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;

    delete_previous -> next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return(SUCESS);

}

int remove_end (struct node* p_list)
{
    
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(p_list -> next == NULL)
    {
        return(LIST_EMPTY);
    }

    run_previous = p_list;
    run = p_list -> next;

    while (run -> next != NULL)
    {
        run_previous = run;
        run = run -> next;
    }

    free(run);
    run = NULL;
    run_previous -> next = NULL;

    return (SUCESS);
}

int remove_data (struct node* p_list, int r_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    run_previous = p_list;
    run = p_list -> next;

    while (run != NULL)
    {
        if(run -> data == r_data)
        {
            break;
        }

        run_previous = run;
        run = run -> next;
    }

    if(run == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    run_previous -> next = run -> next;
    free(run);
    run = NULL;

    return (SUCESS);
}

/* Miscallaneous functions */
int find (struct node* p_list, int f_data)
{
    struct node* run = NULL;

    run = p_list -> next;

    while (run != NULL)
    {
        if (run -> data == f_data)
        {
            return (TRUE);
        }
        run = run -> next;
    }
    return (FALSE);
    
}

int get_list_length (struct node* p_list)
{
    int len = 0;
    struct node* run = NULL;

    run = p_list -> next;
    while (run != NULL)
    {
        len = len + 1;
        run = run -> next;
    }

    return (len);
    
}

int is_list_empty (struct node* p_list)
{
    return (p_list -> next == NULL);
}

void show_list (struct node* p_list, const char* Msg)
{
    struct node* run = NULL;

    if(Msg != NULL)
    {
        puts(Msg);
    }
    printf("[START] -> ");
    run = p_list -> next;

    while (run != NULL)
    {
        printf("[%d] -> ", run -> data);
        run = run -> next;
    }

    printf("[END] \n");
}

/* List destruction function */
int destroy_list (struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_next = NULL;

    run = p_list;

    while (run != NULL)
    {
        run_next = run -> next;
        free(run);
        run = run_next;
    }

    return (SUCESS);
}

 


