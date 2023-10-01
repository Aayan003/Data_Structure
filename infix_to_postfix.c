#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
typedef struct stackprogram
{
    int top;
    int size;
    char *a;
    int *ptr;
}stack;

int init(stack *s1,int len)
{
    s1->top = -1;
    s1->size=len;
    s1->a=(char*)malloc(s1->size * sizeof(char));
    s1 -> ptr = (int*)malloc(s1 -> size * sizeof(int));
}
int isfull(stack *s4)
{
    if(s4->top==s4->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(stack *s2,char item)
{
    if(isfull(s2) == 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        s2->a[++s2->top]=item;
    }

}

int isempty(stack *s) 
{
    if(s->top==-1)
    {
       return 1;
    }
    else
    {
        return 0;
    }
}
char pop(stack *s3)
{
    char x;
    if(isempty(s3) == 1)
    {
        printf("Stack is empty\n");
      
    }
    else
    {
        x=s3->a[s3->top--];
        return x;
    }
}
char peek(stack *s)
{
    return s->a[s->top];
}
void push_int(stack *s, int item)
{
    if(isfull(s))
    {
        printf("Stack is full");
    }
    else
    {
        s -> ptr[++s -> top] = item;
    }
}
int peek_int(stack *s)
{
	return s -> ptr[s -> top];
}
int pop_int(stack *s)
{
    if(isempty(s))
    {
        printf("Stack is empty");
        
    }
    else
    {
        return s -> ptr[s -> top--];
    }
}
int isoperator(char a)
{
     return ((a == '+') || (a == '-') || (a == '*') || (a == '/') || (a == '^'));
    
}
int precedence(char ch)
{
   
       if(ch=='+'||ch=='-')
       {
            return 1;
       }
       else if(ch=='*'||ch=='/')
       {
            return 2;
       }
       else if (ch=='^')
       {
            return 3;
       }
       else
       {
       return -1;
       }
}
char *infix_to_postfix(char *infix, stack *s)
{
    int len=strlen(infix), j = 0;
    init(s,len);
    char *postfix;
    postfix = (char*)malloc(sizeof(char)*(len + 1));
    for(int i=0; i<len;i++)
    {
        if(isalnum(infix[i]))
        {
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='(')
        {
            push(s,infix[i]);
        }
        else if(isoperator(infix[i]))
        {
            while(precedence(infix[i])<=precedence(peek(s)) && peek(s) != '(')
            {
                postfix[j++]=pop(s);
            }
            push(s,infix[i]);
        }
        else if(infix[i]==')')
        {
            while((s -> top > -1) && peek(s)!='(')
            {
                postfix[j++]=pop(s);
            }
            if(peek(s) == '(')
            {
            	pop(s);
            }
        }
    }
    while(isempty(s) != 1 && peek(s) != '(')
        {
            postfix[j++]=pop(s);
        }
    return postfix;
}
int value(char ch, stack *s)
{
    int val;
    int a, b;
    a = pop_int(s);
    b = pop_int(s);
    switch(ch)
    {
        case '+' : val = b + a;
            break;
        case '-' : val = b - a;
            break;
        case '*' : val = b * a;
            break;
        case '/' : val = b / a;
            break;
        case '^' : val = pow(b, a);
            break;
        default : printf("Invalid input\n");
    }
    return val;
}
int postfixtovalue(char *postfixed, stack *s2)
{
    int len, val = 0;
    len = strlen(postfixed);
    postfixed[len + 1] = '\0';
    for(int i = 0; postfixed[i] != '\0'; i++)
    {
            int temp;
        if((int)(postfixed[i] >= 48) && (int)(postfixed[i]) <= 57)
        {
            temp = postfixed[i] - '0';
            push_int(s2, temp);
        }
        else if(isoperator(postfixed[i]))
        {
            val = value(postfixed[i], s2);
            push_int(s2,val);
        }
        else
        {
            val = -111111111;
        }
    }
    return peek_int(s2);
}
int main()
{
    char *infix;
    stack s;
    int n, val;
    printf("how many characters u have to input:\n");
    scanf("%d",&n);
    infix=(char*)malloc(sizeof(char)*n+1);
    infix[n] = '\0';
    printf("enter the expression:\n");
    for(int i=0;i<n;i++)
    {
        scanf("\n%c", &infix[i]);
    }
    printf("the postfix expression:\n");
    char *postfixed;
    postfixed = infix_to_postfix(infix, &s);
    free(infix);
    puts(postfixed);
    val = postfixtovalue(postfixed, &s);
    free(postfixed);
    printf("%d", val);
    free(s.a);
    free(s.ptr);
    return 0;
}
