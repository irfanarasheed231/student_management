#include "student.h"

void addbegin(SLL **ptr)
{
    SLL *new, *temp;
    int roll = 1;
    int found;
    float percentage;

    new = malloc(sizeof(SLL));

    if(new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    /* Find smallest unused roll number */

    while(1)
    {
        found = 0;
        temp = *ptr;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }

        if(found == 0)
            break;

        roll++;
    }

    new->rollno = roll;

    printf("Enter student name: ");
    scanf("%49s", new->name);

    printf("Enter percentage: ");
    scanf("%f", &new->percentage);

    if(new->percentage < 0 ||
       new->percentage > 100)
    {
        printf("Invalid percentage\n");
        free(new);
        return;
    }

    new->next = *ptr;
    *ptr = new;

    printf("Record added successfully\n");
    printf("Assigned Roll Number: %d\n", roll);
}
