#include <stdio.h>
#include <stdlib.h>

struct node
{
    char ssn[20], name[20], dept[20];
    struct node *llink;
    struct node *rlink;
};

typedef struct node* NODE;

NODE first = NULL;
int count = 0;

/* Create Node */
NODE create()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }

    printf("Enter SSN Name Department:\n");
    scanf("%s %s %s", temp->ssn, temp->name, temp->dept);

    temp->llink = NULL;
    temp->rlink = NULL;
    count++;
    return temp;
}

/* Insert at End */
NODE insertend()
{
    NODE cur, temp = create();

    if (first == NULL)
        return temp;

    cur = first;
    while (cur->rlink != NULL)
        cur = cur->rlink;

    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

/* Insert at Front */
NODE insertfront()
{
    NODE temp = create();

    if (first == NULL)
        return temp;

    temp->rlink = first;
    first->llink = temp;
    return temp;
}

/* Delete at End */
NODE deleteend()
{
    NODE cur, prev = NULL;

    if (first == NULL)
    {
        printf("DLL is empty\n");
        return NULL;
    }

    if (first->rlink == NULL)
    {
        printf("Deleted SSN: %s\n", first->ssn);
        free(first);
        count--;
        return NULL;
    }

    cur = first;
    while (cur->rlink != NULL)
    {
        prev = cur;
        cur = cur->rlink;
    }

    prev->rlink = NULL;
    printf("Deleted SSN: %s\n", cur->ssn);
    free(cur);
    count--;
    return first;
}

/* Delete at Front */
NODE deletefront()
{
    NODE temp;

    if (first == NULL)
    {
        printf("DLL is empty\n");
        return NULL;
    }

    if (first->rlink == NULL)
    {
        printf("Deleted SSN: %s\n", first->ssn);
        free(first);
        count--;
        return NULL;
    }

    temp = first;
    first = first->rlink;
    first->llink = NULL;

    printf("Deleted SSN: %s\n", temp->ssn);
    free(temp);
    count--;
    return first;
}

/* Display and Count */
void display()
{
    NODE cur = first;

    if (cur == NULL)
    {
        printf("DLL is empty\n");
        return;
    }

    printf("\nEmployee Details:\n");
    while (cur != NULL)
    {
        printf("SSN:%s  Name:%s  Dept:%s\n",
               cur->ssn, cur->name, cur->dept);
        cur = cur->rlink;
    }
    printf("Number of nodes = %d\n", count);
}

/* Main */
int main()
{
    int ch, n, i;

    while (1)
    {
        printf("\n\n--- DLL MENU ---");
        printf("\n1.Create DLL (End Insertion)");
        printf("\n2.Display & Count");
        printf("\n3.Insert at End");
        printf("\n4.Delete at End");
        printf("\n5.Insert at Front");
        printf("\n6.Delete at Front");
        printf("\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter number of employees: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    first = insertend();
                break;

            case 2: display(); break;
            case 3: first = insertend(); break;
            case 4: first = deleteend(); break;
            case 5: first = insertfront(); break;
            case 6: first = deletefront(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}