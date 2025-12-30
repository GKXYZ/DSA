#include <stdio.h>
#include <stdlib.h>

struct node
{
    char SSN[10], name[20], dept[20];
    struct node *link;
};

typedef struct node* NODE;

/* Create a new node */
NODE getnode()
{
    return (NODE)malloc(sizeof(struct node));
}

/* Insert at Front */
NODE insert_front(NODE last)
{
    NODE temp = getnode();

    printf("\nEnter SSN, Name, Department:\n");
    scanf("%s %s %s", temp->SSN, temp->name, temp->dept);

    if (last == NULL)
    {
        temp->link = temp;   // first node points to itself
        return temp;
    }

    temp->link = last->link;
    last->link = temp;

    return last;
}

/* Delete from Front */
NODE delete_front(NODE last)
{
    NODE first;

    if (last == NULL)
    {
        printf("\nCSLL is Empty\n");
        return NULL;
    }

    first = last->link;

    if (first == last)
    {
        printf("Deleted SSN: %s\n", first->SSN);
        free(first);
        return NULL;
    }

    last->link = first->link;
    printf("Deleted SSN: %s\n", first->SSN);
    free(first);

    return last;
}

/* Insert at Rear */
NODE insert_rear(NODE last)
{
    NODE temp = getnode();

    printf("\nEnter SSN, Name, Department:\n");
    scanf("%s %s %s", temp->SSN, temp->name, temp->dept);

    if (last == NULL)
    {
        temp->link = temp;
        return temp;
    }

    temp->link = last->link;
    last->link = temp;
    last = temp;

    return last;
}

/* Delete from Rear */
NODE delete_rear(NODE last)
{
    NODE cur, prev;

    if (last == NULL)
    {
        printf("\nCSLL is Empty\n");
        return NULL;
    }

    if (last->link == last)
    {
        printf("Deleted SSN: %s\n", last->SSN);
        free(last);
        return NULL;
    }

    prev = NULL;
    cur = last->link;

    while (cur->link != last->link)
    {
        prev = cur;
        cur = cur->link;
    }

    prev->link = last->link;
    printf("Deleted SSN: %s\n", cur->SSN);
    free(cur);

    return prev;
}

/* Display */
void display(NODE last)
{
    NODE cur;
    int count = 0;

    if (last == NULL)
    {
        printf("\nCSLL is Empty\n");
        return;
    }

    cur = last->link;
    printf("\nCSLL Information:\n");

    do
    {
        printf("SSN:%s  Name:%s  Department:%s\n",
               cur->SSN, cur->name, cur->dept);
        cur = cur->link;
        count++;
    } while (cur != last->link);

    printf("Number of nodes = %d\n", count);
}

/* Main Function */
int main()
{
    NODE last = NULL;
    int ch;

    while (1)
    {
        printf("\n***** CSLL MENU *****");
        printf("\n1.Insert Front");
        printf("\n2.Delete Front");
        printf("\n3.Insert Rear");
        printf("\n4.Delete Rear");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: last = insert_front(last); break;
            case 2: last = delete_front(last); break;
            case 3: last = insert_rear(last);  break;
            case 4: last = delete_rear(last);  break;
            case 5: display(last);             break;
            case 6: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
