#include<stdio.h>
#include<stdlib.h>

struct Node {
    int num;
    struct Node *next;
}*head,*tail;

void push(struct Node** a, int b) { //push head
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node)); 
    temp->num  = b; 
    temp->next = (*a); 
    (*a) = temp; 
}

void printList(struct Node *node) { 
  while (node != NULL) { 
     printf("%d -> ", node->num); 
     node = node->next; 
  } 
  puts("NULL");
} 

struct Node* SortedMerge2(struct Node *a, struct Node *b) { 
    if (a==NULL && b==NULL) return NULL;  
    struct Node *res = NULL; 
    while (a != NULL && b != NULL) 
    { 
        if (a->num <= b->num) 
        { 
            struct Node *temp = a->next; 
            a->next = res; 
            res = a; 
            a = temp; 
        } 
        else
        { 
            struct Node *temp = b->next; 
            b->next = res; 
            res = b; 
            b = temp; 
        } 
    } 
    while (a != NULL) 
    { 
        struct Node *temp = a->next; 
        a->next = res; 
        res = a; 
        a = temp; 
    } 
    while (b != NULL) 
    { 
        struct Node *temp = b->next; 
        b->next = res; 
        res = b; 
        b = temp; 
    } 
    return res; 
}

int main (){
    //list 1
    printf("Jumlah element list pertama: ");
    int n;
    scanf("%d",&n);
    struct Node *list1=NULL;
    printf("Masukkan dari besar ke kecil\n");
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        push(&list1,a);
    }
    //list 2
    printf("Jumlah element list kedua: ");
    int m;
    scanf("%d",&m);
    struct Node *list2=NULL;
    printf("Masukkan dari besar ke kecil\n");
    for(int i=0;i<m;i++){
        int b;
        scanf("%d",&b);
        push(&list2,b);
    }
    struct Node *res=SortedMerge2(list1,list2);
    printList(res);
   return 0;
}