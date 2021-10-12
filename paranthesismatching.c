#include<stdio.h>
#include<string.h>
#include "stack.h"
int main(){
    struct stack st;
    char a[] = "{([a + b]*[c + d)]}";
    // 
    st.size = strlen(a) ;
    st.top  = -1;
    st.s = (char *)malloc(st.size*sizeof(char));
    
   for(int i = 0;i < strlen(a); i++){
       if(a[i] == 40 || a[i] == 91 || a[i] == 123){
           push(&st,a[i]);
       }
       else if(st.top == 40 && a[i] == 41 ){
           pop(&st);
       }
       else if(st.top == 91 && a[i] == 93){
              pop(&st);
       }
       else if(st.top == 123 && a[i] == 125){
            pop(&st);
       }
   }
   if(Empty(st)){
       printf("paranthesis is matching");
   }
   else{
        printf("paranthesis is not matching");
   }

    
    return 0;
}