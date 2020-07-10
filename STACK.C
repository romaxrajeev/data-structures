#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct stack{
char arr[100];
int top;
}stack;

stack make_stack()
{
 stack s;
 s.top = -1;
 return(s);
}

void push(stack *s,char n){
 s->arr[++s->top] = n;
}

char pop(stack *s){
 return(s->arr[s->top--]);
}

char peek(stack *s){
 return(s->arr[s->top]);
}

int isempty(stack *s){
 if(s->top == -1){
   return(1);
 }
 return(0);
}

void main(){
 stack s;
 int i;
 char input[100],x;
 clrscr();
 s = make_stack();
 gets(input);
 for(i=0;i<strlen(input);i++)
 {
   if(input[i] == '(' || input[i] == '{' || input[i] == '['){
    push(&s,input[i]);
   }
   else if((input[i] == ')' && peek(&s) == '(') || (input[i] == '}' && peek(&s) == '{') || (input[i] == ']' && peek(&s) == '[') ){
  x = pop(&s);
   }
 }
 if(isempty(&s)){
  printf("Well formed");
 }
 else{
  printf("Not well formed");
 }
 getch();
}