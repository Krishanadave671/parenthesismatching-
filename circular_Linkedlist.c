#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*head = NULL;

void Display(){
    struct Node *temp = head;
    while (temp->next!= head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}
void Insert(int val){
    struct Node *ptr,*temp;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = NULL;
    if(head==NULL)

    {
        head=ptr;
        ptr->next=head;

    }
    temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp ->next = ptr;
    ptr->next = head;
    head = ptr;
}
void Delete(){
    // deleting first node ;
    struct Node *temp,*ptr;
    ptr = temp = head;

    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
    free(ptr);



}
int main(){
 

   Insert(10);
   Insert(20);
   Insert(30);
   Display();
    
    return 0;
}