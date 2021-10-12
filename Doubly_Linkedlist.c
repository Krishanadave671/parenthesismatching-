#include<stdio.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*head = NULL;
void Insertatbegin(int val){
    struct Node *newNode ;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = newNode->next = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

int main(){
   
    return 0;
}