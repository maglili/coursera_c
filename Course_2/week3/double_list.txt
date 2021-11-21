#include <stdio.h>
#include <stdlib.h>

int NUM_RANGE = 50;
int LIST_SIZE = 200;

// User defined data type
typedef struct node
{
    int number;
    struct node *next;
    struct node *prev;
} node;

node *create_list(int d)
{
    node *head = malloc(sizeof(node));
    head->number = d;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

void print_list(node *head)
{
    while (head != NULL)
    {
        printf("%i\t", head->number);
        head = head->next;
    }
    printf("\n");
}

node *add_to_front(int d, node *old)
{
    node *new = create_list(d);
    new->next = old;
    old->prev = new;
    return new;
}

void swap_val(node *head1, node *head2)
{
    int temp = head2->number;
    head2->number = head1->number;
    head1->number = temp;
}

void bubble_sort(node *head)
{
    int swap_frag = 1;
    node *pos = head;

    while (swap_frag != 0)
    {
        swap_frag = 0;
        while (pos->next != NULL)
        {
            if (pos->number > pos->next->number)
            {
                swap_val(pos, pos->next);
                swap_frag = 1;
            }
            pos = pos->next;
        }
        pos = head;
    }
}

void rm_all_dupes(node *head)
{
    //For all node except last one
    while (head->next != NULL)
    {
        node *next = head->next;
        if (head->prev != NULL)
        {
            if (head->prev->number == head->number)
            {
                node *tmp = head;
                head->prev->next = head->next;
                head->next->prev = head->prev;
                free(tmp);
            }
        }
        head = next;
    }

    //For last node
    if (head->next == NULL)
    {
        if (head->prev != NULL)
        {
            if (head->prev->number == head->number)
            {
                head->prev->next = NULL;
                free(head);
            }
        }
    }
}

void free_memory(node *head)
{
    while (head != NULL)
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void)
{
    int rand_num = (rand() % NUM_RANGE);

    node *head = create_list(rand_num);
    
    // Add random number to linked list
    for (int i = 0; i < LIST_SIZE - 1; i++)
    {
        rand_num = (rand() % NUM_RANGE);
        head = add_to_front(rand_num, head);
    }

    // Bubble sort
    printf("Before sorted:\n");
    print_list(head);
    bubble_sort(head);
    printf("After sorted:\n");
    print_list(head);

    // Remove duplicate data
    printf("After rm dupes:\n");
    rm_all_dupes(head);
    print_list(head);

    // All heap blocks were freed -- no leaks are possible
    free_memory(head);

    return 0;
}