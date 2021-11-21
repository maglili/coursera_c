#include <stdio.h>

// user defined data type
typedef enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date
{
    month m;
    int d;
} date;

// function prototypes
int days_in_month(month);
date nextday(date);
void printdate(date);

int main(void)
{
    date day = {jan, 1};
    day = nextday(day);
    printf("---------------\n");

    day = nextday(day);
    printf("---------------\n");

    day.m = feb; day.d = 28;
    day = nextday(day);
    printf("---------------\n");

    day.m = mar; day.d = 14;
    day = nextday(day);
    printf("---------------\n");

    day.m = oct; day.d = 31;
    day = nextday(day);
    printf("---------------\n");

    day.m = dec; day.d = 31;
    day = nextday(day);
    printf("---------------\n");

    return 0;
}

int days_in_month(month m)
{
    switch (m)
    {
    case jan:
        return 31;
    case feb:
        return 28;
    case mar:
        return 31;
    case apr:
        return 30;
    case may:
        return 31;
    case jun:
        return 30;
    case jul:
        return 31;
    case aug:
        return 31;
    case sep:
        return 30;
    case oct:
        return 31;
    case nov:
        return 30;
    case dec:
        return 31;
    default:
        printf("Invalid value.\n");
        return 0;
    }
}

date nextday(date day)
{
    printf("Input date: ");
    printdate(day);
    int month_days = days_in_month(day.m);
    day.d += 1;
    if (day.d > month_days)
    {
        day.m = (day.m +1) % 12;
        day.d = 1;
    }
    printf("Next day: ");
    printdate(day);
    return day;
}

void printdate(date day)
{
    switch (day.m)
    {
    case jan:
        printf("January %i\n", day.d);
        break;
    case feb:
        printf("February %i\n", day.d);
        break;
    case mar:
        printf("March %i\n", day.d);
        break;
    case apr:
        printf("April %i\n", day.d);
        break;
    case may:
        printf("May %i\n", day.d);
        break;
    case jun:
        printf("June %i\n", day.d);
        break;
    case jul:
        printf("July %i\n", day.d);
        break;
    case aug:
        printf("August %i\n", day.d);
        break;
    case sep:
        printf("September %i\n", day.d);
        break;
    case oct:
        printf("October %i\n", day.d);
        break;
    case nov:
        printf("November %i\n", day.d);
        break;
    case dec:
        printf("December %i\n", day.d);
        break;
    default:
        printf("Invalid value.\n");
    }
}