#include "student.h"

void printnode(SLL *ptr)
{
    printf("\n------------------------------------------------------------\n");
    printf("%-10s %-20s %-15s\n",
           "Roll No.", "Name", "Percentage");

    printf("------------------------------------------------------------\n");

    if(ptr == NULL)
    {
        printf("No student records available\n");
        printf("------------------------------------------------------------\n");
        return;
    }

    while(ptr != NULL)
    {
        printf("%-10d %-20s %-15.2f\n",
               ptr->rollno,
               ptr->name,
               ptr->percentage);

        ptr = ptr->next;
    }

    printf("------------------------------------------------------------\n");
}


int countnode(SLL *ptr)
{
    int count = 0;

    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}
