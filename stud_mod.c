#include"student.h"
void modify(SLL *ptr)
{
    SLL *p, *temp = NULL;

    int roll, count = 0;
    char ch;
    char name[50];
    float percentage;

    if(ptr == NULL)
    {
        printf("No student records available\n");
        return;
    }

    printf("\nEnter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");

    printf("Enter choice: ");
    scanf(" %c", &ch);

    switch(ch)
    {
        /* Search by roll number */

        case 'R':
        case 'r':

            printf("Enter roll number: ");
            scanf("%d", &roll);

            if(roll <= 0)
            {
                printf("Invalid roll number\n");
                return;
            }

            for(p = ptr; p != NULL; p = p->next)
            {
                if(p->rollno == roll)
                {
                    temp = p;
                    break;
                }
            }

            break;


        /* Search by name */

        case 'N':
        case 'n':

            printf("Enter name: ");
            scanf("%49s", name);

            for(p = ptr; p != NULL; p = p->next)
            {
                if(strcmp(p->name, name) == 0)
                {
                    count++;
                    temp = p;
                }
            }

            if(count > 1)
            {
                printf("\nMatching records:\n");

                for(p = ptr; p != NULL; p = p->next)
                {
                    if(strcmp(p->name, name) == 0)
                    {
                        printf("%d %s %.2f\n",
                               p->rollno,
                               p->name,
                               p->percentage);
                    }
                }

                printf("Enter roll number to modify: ");
                scanf("%d", &roll);

                temp = NULL;

                for(p = ptr; p != NULL; p = p->next)
                {
                    if(p->rollno == roll &&
                       strcmp(p->name, name) == 0)
                    {
                        temp = p;
                        break;
                    }
                }
            }

            break;


        /* Search by percentage */

        case 'P':
        case 'p':

            printf("Enter percentage: ");
            scanf("%f", &percentage);

            if(percentage < 0.0 || percentage > 100.0)
            {
                printf("Invalid percentage\n");
                return;
            }

            for(p = ptr; p != NULL; p = p->next)
            {
                if(p->percentage == percentage)
                {
                    count++;
                    temp = p;
                }
            }

            if(count > 1)
            {
                printf("\nMatching records:\n");

                for(p = ptr; p != NULL; p = p->next)
                {
                    if(p->percentage == percentage)
                    {
                        printf("%d %s %.2f\n",
                               p->rollno,
                               p->name,
                               p->percentage);
                    }
                }

                printf("Enter roll number to modify: ");
                scanf("%d", &roll);

                temp = NULL;

                for(p = ptr; p != NULL; p = p->next)
                {
                    if(p->rollno == roll &&
                       p->percentage == percentage)
                    {
                        temp = p;
                        break;
                    }
                }
            }

            break;


        default:

            printf("Invalid choice\n");
            return;
    }


    if(temp == NULL)
    {
        printf("Record not found\n");
        return;
    }


    /* Display current record */

    printf("\nCurrent record:\n");

    printf("%d %s %.2f\n",
           temp->rollno,
           temp->name,
           temp->percentage);


    /* Enter updated details */

    printf("Enter updated name: ");
    scanf("%49s", name);

    printf("Enter updated percentage: ");
    scanf("%f", &percentage);


    if(strlen(name) == 0)
    {
        printf("Name cannot be empty\n");
        return;
    }

    if(percentage < 0.0 || percentage > 100.0)
    {
        printf("Percentage must be between 0 and 100\n");
        return;
    }


    /* Roll number remains unchanged */

    strcpy(temp->name, name);
    temp->percentage = percentage;

    printf("Record modified successfully\n");

}
