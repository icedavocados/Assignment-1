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

void append(struct Node** a, int b) { //push tail
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = *a;
    temp->num  = b; 
    temp->next = NULL; 
    if (*a == NULL) { 
       *a = temp;
       return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    last->next = temp; 
    return; 
} 

void printList(struct Node *node) { 
  while (node != NULL) { 
     printf("%d -> ", node->num); 
     node = node->next; 
  } 
  puts("NULL");
} 

struct Node* SortedMerge(struct Node* a, struct Node* b)  { 
    struct Node* result = NULL; 
    if (a == NULL)  
        return(b); 
    else if (b==NULL)  
        return(a); 
    if (a->num <= b->num) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return(result); 
} 

void printMiddle(struct Node *head)  {  
    struct Node *slow_ptr = head;  //ketika fast null maka slow mid karena
    struct Node *fast_ptr = head;  // fast 2x lebih cpt dari slow
    if (head!=NULL)  {  
        while (fast_ptr != NULL && fast_ptr->next != NULL) {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("The middle element is [%d]\n", slow_ptr->num);  
    }  
}

void printDiff(struct Node *res){
    int max=INT32_MIN;//set max ke -2^32 - 1
    int min=INT32_MAX;//set min ke 2^32 - `
    if(res!=NULL){
        while(res!=NULL){
            if(max<res->num){
                max=res->num;
            }
            if(min>res->num){
                min=res->num;
            }
            res=res->next;
        }
    }
    printf("Difference of Largest and Smallest Value is [%d]\n",max-min);
}

void removeduplicates(struct Node *res){
    struct Node *temp=res;
    struct Node *connector;
    if(temp==NULL){
        return;
    }
    while(temp->next!=NULL){
        if(temp->num==temp->next->num){//jika sekarang sama dengan dpn
            connector=temp->next->next; // simpan 2 kedepan
            free(temp->next); //bebaskan yang depan
            temp->next=connector; //sambungkan dengan 2 kedepan
        }
        else{
            temp=temp->next;
        }
    }
}

void printfromlast(struct Node *head, int n) {
    struct Node *p, *q;
    int i;
    q = p = head;
    for (i = 0; i < n && q != NULL; i++){
        q = q->next;
    }
    if (i < n){
        printf("Entered n = %d is larger than the number of elements = %d in list. Please try again.\n", n, i);
    }
    else{
        while (q->next != NULL){
            q = q->next;
            p = p->next;
        }
        printf("%d is %d nodes from the last node.\n", p->num, n);
    }
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
    struct Node *res=SortedMerge(list1,list2);
    printf("Sorted Merge Linked List\n");
    printList(res); //print list
    printDiff(res); //print diff
    printMiddle(res); //print median
    removeduplicates(res); //remove duplicates
    printList(res); //print list after remove duplicates
    printf("Index yang diminta adalah: ");
    int index;
    scanf("%d",&index);
    printfromlast(res,index);
    return 0;
}