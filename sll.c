#include<stdio.h>
#include<stdlib.h>

struct node
{
    char USN[10], name[20], mobile[10];
    struct node *link;
};

typedef struct node* NODE;

NODE getnode()
{
    return (NODE)malloc(sizeof(struct node));
}


NODE insert_front(NODE first)
{
    NODE temp = getnode();

    printf("\nEnter USN, Name, Mobile:\n");
    scanf("%s%s%s", temp->USN, temp->name, temp->mobile);

    temp->link = first;
    return temp;
}


NODE delete_front(NODE first)
{
    NODE temp;

    if (first == NULL)
    {
        printf("\nSLL is Empty\n");
        return NULL;
    }

    temp = first;
    first = first->link;

    printf("Deleted USN: %s\n", temp->USN);
    free(temp);

    return first;
}


NODE insert_rear(NODE first)
{
    NODE temp = getnode(), cur;

    printf("\nEnter USN, Name, Mobile:\n");
    scanf("%s%s%s", temp->USN, temp->name, temp->mobile);

    temp->link = NULL;

    if (first == NULL)
        return temp;

    cur = first;
    while (cur->link != NULL)
        cur = cur->link;

    cur->link = temp;
    return first;
}


NODE delete_rear(NODE first)
{
    NODE cur, prev;

    if (first == NULL)
    {
        printf("\nSLL is Empty\n");
        return NULL;
    }

    if (first->link == NULL)
    {
        printf("Deleted USN: %s\n", first->USN);
        free(first);
        return NULL;
    }

    prev = NULL;
    cur = first;

    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    prev->link = NULL;
    printf("Deleted USN: %s\n", cur->USN);
    free(cur);

    return first;
}


void display(NODE first)
{
    NODE cur = first;
    int count = 0;

    if (cur == NULL)
    {
        printf("\nSLL is Empty\n");
        return;
    }

    printf("\nSLL Information:\n");
    while (cur != NULL)
    {
        printf("USN:%s  Name:%s  Mobile:%s\n",
               cur->USN, cur->name, cur->mobile);
        cur = cur->link;
        count++;
    }
    printf("Number of nodes = %d\n", count);
}


int main()
{
    NODE first = NULL;
    int ch;

    while (1)
    {
        printf("\n***** SLL MENU *****");
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
            case 1: first = insert_front(first); break;
            case 2: first = delete_front(first); break;
            case 3: first = insert_rear(first);  break;
            case 4: first = delete_rear(first);  break;
            case 5: display(first);              break;
            case 6: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
