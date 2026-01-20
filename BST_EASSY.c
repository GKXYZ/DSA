#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
typedef struct node* NODE;

NODE newnode(int val) {
    NODE t = (NODE)malloc(sizeof(struct node));
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

NODE insert(NODE root, int val) {
    if (root == NULL) return newnode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

void inorder(NODE r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(NODE r) {
    if (r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(NODE r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

void search(NODE r, int key) {
    while (r) {
        if (r->data == key) {
            printf("Key %d FOUND in BST\n", key);
            return;
        }
        r = (key < r->data) ? r->left : r->right;
    }
    printf("Key %d NOT FOUND\n", key);
}

int main() {
    NODE root = NULL;
    int ch, n, val, key, i;

    while (1) {
        printf("\n1.Create 2.Traversals 3.Search 4.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter no. of elements: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                printf("Enter value:  ");
                scanf("%d", &val);
                root = insert(root, val);
            }
        } else if (ch == 2) {
            printf("\nInorder: ");
            inorder(root);
            printf("\nPreorder: ");
            preorder(root);
            printf("\nPostorder: ");
            postorder(root);
            printf("\n");
        } else if (ch == 3) {
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(root, key);
        } else {
            exit(0);
        }
    }
}
