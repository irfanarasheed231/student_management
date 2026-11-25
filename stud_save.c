#include "student.h"

void savefile(SLL *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "w");

    if(fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }

    while(ptr != NULL)
    {
        fprintf(fp, "%d %s %.2f\n",
                ptr->rollno,
                ptr->name,
                ptr->percentage);

        ptr = ptr->next;
    }

    fclose(fp);

    printf("Records saved successfully\n");
}


void readfile(SLL **ptr)
{
    FILE *fp;
    SLL *new, *temp;

    fp = fopen("student.dat", "r");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        new = malloc(sizeof(SLL));

        if(new == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }

        if(fscanf(fp, "%d %49s %f",
                  &new->rollno,
                  new->name,
                  &new->percentage) != 3)
        {
            free(new);
            break;
        }

        new->next = NULL;

        if(*ptr == NULL)
        {
            *ptr = new;
        }
        else
        {
            temp = *ptr;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = new;
        }
    }

    fclose(fp);

    printf("Records loaded from student.dat\n");
}
