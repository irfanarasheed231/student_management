#include "student.h"
int main()
{
    SLL *headptr = NULL;
    char op;

    /* Load records when program starts */
    readfile(&headptr);

    while(1)
    {
        printf("\033[32m");
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");
        printf("e/E : Exit\n");
        printf("\033[0m");

        printf("Enter your choice: ");
        scanf(" %c", &op);

        switch(op)
        {
            case 'a':
            case 'A':
                addbegin(&headptr);
                break;

            case 'd':
            case 'D':
                deletenode(&headptr);
                break;

            case 's':
            case 'S':
                printnode(headptr);
                break;

            case 'm':
            case 'M':
                modify(headptr);
                break;

            case 'v':
            case 'V':
                savefile(headptr);
                break;

            case 't':
            case 'T':
                sortdata(headptr);
                break;

            case 'l':
            case 'L':
                deleteall(&headptr);
                break;

            case 'r':
            case 'R':
                reverseList(&headptr);
                break;

            case 'e':
            case 'E':
                exitprogram(&headptr);
                break;

            default:
                printf("\033[31m");
                printf("Invalid choice\n");
                printf("\033[0m");
        }
    }

    return 0;
}


/* Reverse actual linked list */

void reverseList(SLL **ptr)
{
    SLL *prev = NULL;
    SLL *cur = *ptr;
    SLL *next;

    if(*ptr == NULL)
    {
        printf("No student records available\n");
        return;
    }

    while(cur != NULL)
    {
        next = cur->next;

        cur->next = prev;

        prev = cur;
        cur = next;
    }

    *ptr = prev;

    printf("List reversed successfully\n");
}


/* Sort records */

void sortdata(SLL *ptr)
{
    SLL *p1, *p2;
    SLL temp;
    int i, j, c;
    char ch;

    if(ptr == NULL)
    {
        printf("No student records available\n");
        return;
    }

    printf("N/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");

    printf("Enter choice: ");
    scanf(" %c", &ch);

    c = countnode(ptr);

    for(i = 0; i < c - 1; i++)
    {
        p1 = ptr;

        for(j = 0; j < c - 1 - i; j++)
        {
            p2 = p1->next;

            if((ch == 'N' || ch == 'n') &&
               strcmp(p1->name, p2->name) > 0)
            {
                temp = *p1;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = temp.rollno;
                strcpy(p2->name, temp.name);
                p2->percentage = temp.percentage;
            }

            else if((ch == 'P' || ch == 'p') &&
                    p1->percentage < p2->percentage)
            {
                temp = *p1;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = temp.rollno;
                strcpy(p2->name, temp.name);
                p2->percentage = temp.percentage;
            }

            p1 = p1->next;
        }
    }

    if(ch == 'N' || ch == 'n' ||
       ch == 'P' || ch == 'p')
    {
        printf("Sorting completed\n");
    }
    else
    {
        printf("Invalid choice\n");
    }
}


/* Exit program */

void exitprogram(SLL **ptr)
{
    char ch;

    printf("\nS/s : Save and exit\n");
    printf("E/e : Exit without saving\n");

    printf("Enter choice: ");
    scanf(" %c", &ch);

    switch(ch)
    {
        case 'S':
        case 's':

            savefile(*ptr);
            deleteall(ptr);

            exit(0);

        case 'E':
        case 'e':

            deleteall(ptr);

            exit(0);

        default:

            printf("Invalid choice\n");
    }
}
