#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node		//ADT for stack
{
    int data;
    struct node *next;
}NODE;

NODE *createnode(int item)		//function for creating each node of stack
{
    NODE *p;
    p=(NODE*)malloc(sizeof(NODE));		//allocating memory for a node
    p->data=item;
    p->next=NULL;
    return p;
}

void push(NODE **top,int symb)		//push function of stack
{
    NODE *p;
    p=createnode(symb);
    if(*top==NULL)			// when stack is empty
    {
	    *top=p;				//adding new node at top
	}
    else						//when stack is non-empty
    {
        p->next=*top;			 //linking new node to top
        *top=p;				//setting top at the last inserted node
    } 
    return;   		//returning the control
}

int pop(NODE **top)		
{
    NODE *p;
    if(*top!=NULL)		//when stack is non-empty
    {
        p=*top;			//pop the top element
        *top=(*top)->next;		//top goes to the next element
    }
    return p->data;		//returning the popped character
}

int operation(int opnd1,int opnd2,char symb)	//function to perform the operations between two operators
{
    switch(symb)
    {
        case '^' :			//power
            return (int)pow(opnd1,opnd2);
            break;
        case '*' :			//multiplication
            return opnd1*opnd2;
            break;
        case '/' :			//divison
            return opnd1/opnd2;
            break;
        case '+' :			//addition
            return opnd1+opnd2;
            break;
        case '-' :			//subtraction
            return opnd1-opnd2;
            break;    
    }
}

int post_evaluate(char str[])	//postfix evaluation function
{
    int i,opnd1,opnd2,value,result;
    char symb;
    NODE *top=NULL;			//initialising top as NULL i.e stack is empty
    
    for(i=0;str[i]!='\0';i++)		//scanning the input string until end
    {
        symb=str[i];
        if(symb=='^' || symb=='*' || symb=='/' || symb=='+' || symb=='-')	//when scanned symbol is a operator
        {
            opnd2=pop(&top);			//popping the 2nd operand from top of stack
            opnd1=pop(&top);			//popping the 1st operand from top of stack
            value=operation(opnd1,opnd2,symb);	//calling operation function
            push(&top,value);
        }
        else if(symb>='0' && symb<='9')		//checking the operands are single digit or not
        {
            push(&top,symb-'0');		//pushing the operands integer value to stack
        }
    }
    return pop(&top);			//pop the final result
}

void main()
{
    char str[50];
    int result,s;
    printf("\nEnter your postfix expression:");		
    gets(str);
    result=post_evaluate(str);		//storing result
    printf("\nResult of the Postfix Expresssion:%d",result);	//printing final result
}
