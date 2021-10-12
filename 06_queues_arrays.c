#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int front ;
    int rear ;
    int *s;
    int size;
} *q;
int isEmpty(){
    if(q->front == q->rear){
       return 1;
    }
    return 0;
}
int isfull(){
    if(q->rear == q->size - 1){
        return 1;
    }
    return 0;
}
void createQueue(){
    q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->s = (int *)malloc(q->size*sizeof(int));
}
void enqueue(int x){
    if(isfull()){
        printf("Queue is full\n");
    }
    else{
        q->rear ++;
        q->s[q->rear] = x;
    }

}
int dequeue(){
    int x = -1;
    if(isEmpty()){
        printf("Queue is Empty\n");
    }
    else{
        q->front ++;
        x = q->s[q->front];
    }
    return x;
}
void Display(){
    int temp;
   temp = q->front + 1;
    
   while(temp != q->rear + 1){
       printf("%d ", q->s[temp]);
       temp++;
   }
    printf("\n");
}

int main(){
    int x,r = 1;
    createQueue();
    printf("Enter the Number according to operations\n");
    
    do{
        int n;
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the element to enqueue in a queue\n");
            scanf("%d", &x);
            enqueue(x);
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