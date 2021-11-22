#include <stdio.h>
#include <stdio.h>
#define MAX_SIZE 50

void read_data(FILE *ptr, int d[], int size)
{
    for (int i=0; i<size; i++)
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

void average_and_max(int arr[], int size, double *avg, int *max)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (arr[i] > (*max))
        {
            (*max) = arr[i];
        }
    }
    (*avg) = sum / size;
}

int main()
{
    // Open files
    FILE *ifp = fopen("text.txt", "r");
    FILE *ofp = fopen("answer-hw3.txt", "w");
    if (ifp == NULL || ofp == NULL)
    {
        return 1;
    }

    int size = 0;
    int data[MAX_SIZE] = {0};

    // Read first number
    if (fscanf(ifp, "%d", &size) != 1)
    {
        return 1;
    }

    // Read remaining numbers
    read_data(ifp, data, size);

    // Compute averate and max value
    double avg = 0;
    int max = 0;
    average_and_max(data, size, &avg, &max);

    // wirte output
    fprintf(ofp, "avg %lf, max %d\n", avg, max);

    // close file
    fclose(ifp);
    fclose(ofp);
    
    return 0;
}