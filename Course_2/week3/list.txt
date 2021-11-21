#include <stdio.h>
#include <stdlib.h>

// User defined data type
typedef struct node
{
    int number;
    struct node *next;
}
node;

// Function prototypes
node *create_list(int);
node *add_to_front(int, node *);
void print_list(node *);
void head_n_val(node *, int);
void swap_val(node *, node *);
void bubble_sort(node *);

// Global variables
int LIST_SIZE = 100;
int NUM_RANGE = 10000;

int main(void)
{
    int rand_num = (rand() % NUM_RANGE) + 1;

    node *head = create_list(rand_num);

    // Add random number to linked list
    for (int i = 0; i < LIST_SIZE - 1; i++)
    {
        rand_num = (rand() % LIST_SIZE) + 1;
        head = add_to_front(rand_num, head);
    }

    // Bubble sort
    printf("Before sorted:\n");
    print_list(head);

    bubble_sort(head);

    printf("After sorted:\n");
    print_list(head);

    // TOP 5 value
    printf("TOP 5 vals:\n");
    head_n_val(head, 5);

    return 0;
}

node *create_list(int d)
{
    node *head = malloc(sizeof(node));
    head->number = d;
    head->next = NULL;
    return head;
}

node *add_to_front(int d, node *head)
{
    node *new = create_list(d);
    new->next = head;
    return new;
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

void head_n_val(node *head, int n)
{
    int counter = 0;
    while (head != NULL && counter < n)
    {
        printf("%i\n", head->number);
        head = head->next;
        counter++;
    }
    printf("\n");
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