#include<stdio.h>
#include<stdlib.h>

 struct stack
{
    int size;
    int *arr;
    int top;
};
int isEmpty(struct stack* ptr){
    if(ptr->top==-1)
    return 1;
    else
    return 0;

}
int isFull(struct stack* ptr){
    if(ptr->top==ptr->size-1)
    return 1;
    else
    return 0;

}
void push(struct stack* ptr, int val)
{
    if(isFull(ptr))
    printf("Stack Overflow\n");
    else{
    ptr->top++;
    ptr->arr[ptr->top]=val;
    }
}
void pop(struct stack* ptr)
{
    if(isEmpty(ptr))
    printf("Stack Underflow\n");
    else{
        int val=ptr->arr[ptr->top];
    ptr->top--;
    printf("The poped element is %d\n",val);
    }
}
void Display(struct stack *s)
{
    for(int i =0;i<=s->top;i++)
    printf("%d\n",s->arr[i]);
}
int peek(struct stack *s){
if(s->top == -1){
        return -1;
    }
    return s->arr[s->top];
}
int main()
{
    int exit = 1;
    int n;
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    do{
        
        int x;
    printf("which operation you would like to perform\n 1. Push\n 2. pop \n 3. peek\n 4. Display \n");
    scanf("%d", &n);

    
    
  
    switch (n)
    {
    case 1:
        
        printf("Enter the element you want to push in stack\n");
        scanf("%d", &x);
        push(s,x);
        break;
    case 2:
     pop(s);
    break;
    case 3:
   printf("The top element is %d", peek(s));
    break;
    case 4:
    Display(s);
    break;
    default:
    printf("Try again !\n");
    }
    
    printf("press 0 for exit\npress 1 for continue\n");
    scanf("%d", &exit);

    }while(exit);


   return 0; 
}
