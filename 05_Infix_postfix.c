
#include<string.h>
#include "stack.h"
 
    
int isoperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/') return 0;
    else return 1;
}
int precedence(char x){
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 2;
   
}
char *infitopost(char *infix){
    struct stack st;
    st.size = 30;
    st.top = -1;
    st.s = (char*)malloc(st.size*sizeof(char));
    int lp = strlen(infix) + 1;
    char *postfix = (char *)malloc(lp*sizeof(char));
    int i = 0,j = 0;
    while (infix[i] != '\0')                                                
    {
        if(isoperand(infix[i])) postfix[j++] = infix[i++];
        else{
            if(precedence(infix[i]) > precedence(peek(st))){
                push(&st,infix[i++]);
            }  
            else{
                postfix[j++] = pop(&st);
            }

             }
        
    }
     while(!Empty(st)){
                postfix[j++] = pop(&st);
            }
            postfix[j] = '\0';
            return postfix;
}
int main(){
   
    
    char*post;
    char infix[30];
    printf("Enter a infix expression\n");
    gets(infix);
   
    post = infitopost(infix);
    printf("%s", post);
    



    
    return 0;
}