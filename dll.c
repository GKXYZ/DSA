#include<stdio.h>
#include<stdlib.h>

struct node{
  char EMPNO[10], Name[20], Dept[10];
  struct node *llink;
  struct node *rlink;
};

typedef struct node *NODE;

NODE getnode(){
  return ((struct node*) malloc(sizeof(struct node)));
}

NODE insert_front(NODE first){
   NODE temp;
   temp = getnode();
   printf("\nEnter Employee Details (EMPNO Name Dept): ");
   scanf("%s%s%s", temp->EMPNO, temp->Name, temp->Dept);  // Fixed: removed & for arrays
   
   if(first == NULL){
      temp->llink = NULL;
      temp->rlink = NULL;
      return temp;
   }
   else{
      first->llink = temp;
      temp->rlink = first;
      temp->llink = NULL;
      return temp;
   }
}

NODE insert_rear(NODE first){
   NODE temp, cur;
   temp = getnode();
   printf("\nEnter Employee Details (EMPNO Name Dept): ");
   scanf("%s%s%s", temp->EMPNO, temp->Name, temp->Dept);  // Fixed: removed & for arrays
   
   if(first == NULL){
      temp->llink = NULL;
      temp->rlink = NULL;
      return temp;
   }
   else{
      cur = first;
      while(cur->rlink != NULL){
         cur = cur->rlink;
      }
      cur->rlink = temp;
      temp->llink = cur;
      temp->rlink = NULL;
      return first;
   }
}

NODE delete_front(NODE first){
   NODE cur;
   if(first == NULL){
      printf("\nThe DLL is Empty\n");
      return NULL;
   }
   if(first->rlink == NULL){
      printf("\nThe %s Employee Node is Deleted\n", first->EMPNO);
      free(first);
      return NULL;
   }
   cur = first;
   first = cur->rlink;
   first->llink = NULL;  // Fixed: set new first's llink to NULL
   printf("\nThe %s Employee Node is Deleted\n", cur->EMPNO);
   free(cur);
   return first;
}

NODE delete_rear(NODE first){
   NODE cur, prev;
   if(first == NULL){
      printf("\nThe DLL is Empty\n");
      return NULL;
   }
   if(first->rlink == NULL){
      printf("\nThe %s Employee Node is Deleted\n", first->EMPNO);
      free(first);
      return NULL;
   }
   cur = first;
   prev = NULL;
   while(cur->rlink != NULL){
      prev = cur;
      cur = cur->rlink;
   }
   prev->rlink = NULL;
   printf("\nThe %s Employee Node is Deleted\n", cur->EMPNO);
   free(cur);
   return first;
}

void display(NODE first){
   NODE cur;
   int count = 0;
   if(first == NULL){
      printf("\nThe DLL is Empty\n");
      return;
   }
   cur = first;
   printf("\n===== Employee Details =====\n");
   while(cur != NULL){
      printf("EMPNO:  %s | Name: %s | Dept:  %s\n", cur->EMPNO, cur->Name, cur->Dept);
      count++;
      cur = cur->rlink;
   }
   printf("\nTotal number of nodes in DLL: %d\n", count);
}

int main(){
   NODE first = NULL;
   int ch;
   
   while(1){
      printf("\n************** DLL **************\n");
      printf("1. Insert Front\n");
      printf("2. Insert Rear\n");
      printf("3. Delete Front\n");
      printf("4. Delete Rear\n");
      printf("5. Display\n");
      printf("6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &ch);
      
      switch(ch){
         case 1: first = insert_front(first);
                 break;
         case 2: first = insert_rear(first);
                 break;
         case 3: first = delete_front(first);
                 break;
         case 4: first = delete_rear(first);
                 break;
         case 5: display(first);
                 break;
         case 6: exit(0);
         default: printf("\nWrong Choice!!\n");
      }
   }
   return 0;
}
