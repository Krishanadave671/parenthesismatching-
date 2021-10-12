#include<stdio.h>
#include<string.h>
#include"stack.h"
int postfixevaluation(char *postfix){
    struct stack st;
    st.size = 30;
    st.top = -1;
    st.s = (int*)malloc(st.size*sizeof(int));
    int i = 0;
    while(postfix[i] != '\0'){
        
        if(isoperand(postfix[i]))
        push(&st,postfix[i++] - '0');
        else{
            int x = pop(&st);
            int y = pop(&st);
            switch (postfix[i++])
            {
            case '+':
                 push(&st,x + y);
                break;
            case '-':
                 push(&st,y - x);
                break;
            case '*':
                 push(&st,x*y);
                break;
            case '/':
                 push(&st,y-x);
                break;
            }

        }

        
    }
    return peek(st);
}
int main(){
     char postfix[30];
     printf("Enter a postfix expression\n");
    gets(postfix);
    printf("%d", postfixevaluation(postfix));

    
    return 0;
}