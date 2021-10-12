#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int front ;
    int rear;
    int size;
    int *arr;
}*q;
void create(){
     q = (struct Queue *)malloc(sizeof(struct Queue));
    printf("Enter the value of size of Q\n");
    scanf("%d", &q->size);
    q->arr = (int *)malloc(q->size*sizeof(int));
    q->front = q->rear = 0;

}
int isfull(){
 if((q->rear + 1)%q->size == q->front){
     return 1;
 }
 return 0; 
}
int isEmpty(){
 if(q->front == q->rear){
     return 1;
 }
 return 0; 
}

void Enqueue(int x){
    if(isfull()){
        printf("Queue is full\n");
    }
    else{
        q->rear = (q->rear + 1)% q->size;
        q->arr[q->rear] = x;
    }
}
int dequeue(){
    int x = -1;
    if(isEmpty()){
        printf("Queue is Empty");
    }
    else{
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}
void Display(){
   int i = q->front + 1;
   do{
       printf("%d ", q->arr[i]);
       i = (i + 1)%q->size;
   }while(i!= (q->rear + 1) % q->size);
   printf("\n");
}
int main(){
    int x,r;
    create();
   printf("Enter the Number according to operations in Circular queue\n");
    
    do{
        int n;
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the element to enqueue in a queue\n");
            scanf("%d", &x);
            Enqueue(x);
            break;
        case 2:
           printf("%d element is deleted\n", dequeue());
            break;
        case 3:
            Display();
            break;
        case 4:
           r = 0;
           break;
        default:
           printf("Invalid input\n");
        }
      

    }while(r);
    


    
    return 0;
}