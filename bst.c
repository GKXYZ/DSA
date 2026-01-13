#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node* NODE;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    return x;
}

NODE insert(NODE root) {
    NODE temp, cur, prev;
    temp = getnode();

    printf("Enter node value: ");
    scanf("%d", &temp->info);

    temp->llink = NULL;
    temp->rlink = NULL;

    if (root == NULL) {
        return temp;
    }

    prev = NULL;
    cur = root;

    while (cur != NULL) {
        prev = cur;
        if (temp->info == cur->info) {
            printf("Duplicate node value %d not allowed.\n", temp->info);
            free(temp);
            return root;
        }
        if (temp->info < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }

    if (temp->info < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;

    return root;
}

void preorder(NODE root) {
    if (root == NULL) return;
    printf("%d ", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void inorder(NODE root) {
    if (root == NULL) return;
    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);
}

void postorder(NODE root) {
    if (root == NULL) return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->info);
}

NODE search(int item, NODE root) {
    NODE cur = root;
    while (cur != NULL) {
        if (item == cur->info) return cur;
        if (item < cur->info) cur = cur->llink;
        else cur = cur->rlink;
    }
    return NULL;
}

int main() {
    NODE root = NULL, found = NULL;
    int choice, N, key, i;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Create BST\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &N);
                for (i = 0; i < N; i++)
                    root = insert(root);
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter element to search: ");
                scanf("%d", &key);
                found = search(key, root);
                if (found != NULL)
                    printf("%d found in BST\n", key);
                else
                    printf("%d not found in BST\n", key);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
