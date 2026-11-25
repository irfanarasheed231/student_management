#include"student.h"
void deletenode(SLL **ptr)
{
    SLL *del, *prev;
    char ch;
    char name[50];
    int roll;
    int count = 0;

    if(*ptr == NULL)
    {
        printf("No student records available\n");
        return;
    }

    printf("R/r : Enter roll number to delete\n");
    printf("N/n : Enter name to delete\n");
    printf("Enter choice: ");

    scanf(" %c", &ch);

    if(ch == 'R' || ch == 'r')
    {
        printf("Enter roll number: ");
        scanf("%d", &roll);

        del = *ptr;
        prev = NULL;

        while(del != NULL)
        {
            if(del->rollno == roll)
            {
                if(prev == NULL)
                    *ptr = del->next;
                else
                    prev->next = del->next;

                free(del);

                printf("Record deleted successfully\n");
                return;
            }

            prev = del;
            del = del->next;
        }

        printf("Roll number not found\n");
    }

    else if(ch == 'N' || ch == 'n')
    {
        printf("Enter name: ");
        scanf("%49s", name);

        del = *ptr;

        while(del != NULL)
        {
            if(strcmp(del->name, name) == 0)
            {
                printf("%d %s %.2f\n",
                       del->rollno,
                       del->name,
                       del->percentage);

                count++;
            }

            del = del->next;
        }

        if(count == 0)
        {
            printf("Name not found\n");
            return;
        }

        printf("Enter roll number to delete: ");
        scanf("%d", &roll);

        del = *ptr;
        prev = NULL;

        while(del != NULL)
        {
            if(del->rollno == roll &&
               strcmp(del->name, name) == 0)
            {
                if(prev == NULL)
                    *ptr = del->next;
                else
                    prev->next = del->next;

                free(del);

                printf("Record deleted successfully\n");
                return;
            }

            prev = del;
            del = del->next;
        }

        printf("Matching record not found\n");
    }

    else
    {
        printf("Invalid choice\n");
    }
}

void deleteall(SLL **ptr)
{
    SLL *del;

    if(*ptr == NULL)
    {
        printf("No student records available\n");
        return;
    }

    while(*ptr != NULL)
    {
        del = *ptr;
        *ptr = del->next;

        free(del);
    }

    *ptr = NULL;

    printf("All records deleted successfully\n");
}
