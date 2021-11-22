#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

int add_counter = 0;

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

node *create_tree(int root)
{
    node *head = malloc(sizeof(node));
    head->number = root;
    head->left = NULL;
    head->right = NULL;
    return head;
}

void add_item(node *head, int num, int *add_counter)
{
    if (head->left == NULL)
    {
        node *new = create_tree(num);
        head->left = new;
    }
    else if (head->right == NULL)
    {
        node *new = create_tree(num);
        head->right = new;
    }
    else
    {
        if (*add_counter % 2 == 0)
        {
            add_item(head->left, num, add_counter);
            (*add_counter)++;
        }
        else
        {
            add_item(head->right, num, add_counter);
            (*add_counter)++;
        }
    }
    
}

node *array_to_tree(int arr[], int size, int *add_counter)
{
    node *head = create_tree(arr[0]);
    for (int i=1; i<size; i++)
    {
        add_item(head, arr[i], add_counter);
    }
    return head;
}

void print_tree(node *head)
{
    if (head == NULL)
    {
        return;
    }

    if (head->left != NULL)
    {
        print_tree(head->left);
    }

    printf("%i\n", head->number);

    if (head->right != NULL)
    {
        print_tree(head->right);
    }
}

void read_data(FILE *ptr, int d[], int size)
{
    for (int i = 0; i < size; i++)
    {
        fscanf(ptr, "%d", &d[i]);
    }
}

void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    // Open files
    FILE *file = fopen("text2.txt", "r");
    if (file == NULL)
    {
        return 1;
    }

    int size = 0;
    int data[MAX_SIZE] = {0};

    // Read first number
    if (fscanf(file, "%d", &size) != 1)
    {
        return 1;
    }

    // Read remaining numbers
    read_data(file, data, size);

    // print_array(data, size);

    // Convert array to tree
    node *head = array_to_tree(data, size, &add_counter);
    printf("Inorder traversal:\n");
    print_tree(head);
}