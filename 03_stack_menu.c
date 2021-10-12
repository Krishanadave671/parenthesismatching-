#include<stdio.h>
#include<stdlib.h>
struct stack 
{
    int size ;
    int top;
    int *s;
};
int Empty(struct stack st){
    if(st.top == -1){
      return 1;
    }
    return 0;
}
int isfull(struct stack st){
     if(st.top == st.size-1){
       return 1;
    }
    return 0;
}
void push(struct stack *st, int x){
    if(st->top == st->size-1){
        printf("stack overflow\n");
    }
    st->top++;
    st->s[st->top] = x;
}
int pop(struct stack *st){
    int x;
    if(st->top == -1){
        printf("stack underflow\n");
    }
    x = st->s[st->top];
    st->top--;
    return x;
}
void Display(struct stack st){
    for(int i = 0 ; i <= st.top; i++){
        printf("%d ", st.s[i]);
    }
    printf("\n");
}
int peek(struct stack st){
    if(st.top == -1){
        return -1;
    }
    return st.s[st.top];
}
int main(){
    int exit = 1;
    int n;
    struct stack st;
    printf("Enter size of stack\n");
    scanf("%d", &st.size);
    st.s= (int*)malloc(st.size*sizeof(int));
    st.top = -1;
    do{
        
        int x;
    printf("which operation you would like to perform\n 1. Push\n 2. pop \n 3. peek\n 4. Display \n");
    scanf("%d", &n);

    
    
  
    switch (n)
    {
    case 1:
        
        printf("Enter the element you want to push in stack\n");
        scanf("%d", &x);
        push(&st,x);
        break;
    case 2:
    printf("I popped %d \n", pop(&st));
    break;
    case 3:
    printf("The top element is  %d\n", peek(st));
    break;
    case 4:
    Display(st);
    break;
    default:
    printf("Try again !\n");
    }
    
    printf("Enter 0 for exit\nEnter 1 for continue\n");
    scanf("%d", &exit);

    }while(exit);
    
    return 0;
}