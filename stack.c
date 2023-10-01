#include <stdio.h>
#include <stdlib.h>

//Creating a Structure for Stack Implemention
typedef struct stack
{
	int size;
	int *a;
	int top;
}st;

//IsFull function checks if the Stack is full with elements and no more position to push
int isfull(st *s)
{
	if(s -> top == s -> size - 1)
	{
		return 1;  //Returns 1 if stack is full
   }
	else
	{
		return 0; //Returns 0 if not empty
	}
}

//Isempty function checks if the Stack is empty and no more elements to pop
int isempty(st *s)
{
	if(s -> top == - 1)
	{
		return 1;	//Returns 1 if stack is empty
	}
	else
	{
		return 0;	//return 0 if stack is no empty
	}
}

//Here the stack gets initialised
void initialisation(st *s)		//pointer to the stack is written,
{								//as we will perform operation on a single stack,
	int s1;						//if the stack has been called with value, new stacks will be created in each function
	printf("Enter the size of the array-\n");
	scanf("%d", &s1);
	s -> size = s1;
	s -> top = -1;
	s -> a = (int *)malloc(s -> size * sizeof(int));		//Dynamic allocation of memory
}

//Pushing elements in stack
int push(st *s, int item)
{
	if(isfull(s))		//Checks for stack is full or not
	{
		return 0;
	}
	else
	{
		s ->  a[++s -> top] = item;		//Pushing the element in stack
		return item;					//Return the element for printing purpose
	}
}

//Popping element from stack
int pop(st *s)
{
	int item;
	if(isempty(s))		//Check for empty stack
	{
		return 0;
	}
	else
	{
		item = s -> a[s -> top--];		//Popping elements from stack
	}
	return item;
}


int main()
{
	st s;
	int item;
	int z, po, po_p;
	initialisation(&s);
	printf("If you want to push input 1 or else u want to pop input 2 : ");
	scanf("%d", &z);
	while(z == 1 || z == 2)
	{
		switch(z)
		{
			case 1 :
		                printf("enter element to push: ");
		            	scanf("%d", &item);
		            	
		                po = push(&s, item);
		
						if(po == 0)
						{
		                    printf("stack is full\n");
		                    break;
						}
				break;
			case 2 : 
		                po_p = pop(&s);
		
						if(po_p == 0)
						{
							printf("stack is empty\n");
		                    break;
						}
		                else
		                {
		                    printf("%d is popped out of stack \n",po_p);
		                }
				break;
		
				default: 
		            printf("Invalid Input\n");
		}
		printf("If you want to push input 1 or else u want to pop input 2 :");
		scanf("%d", &z);
	    printf("enter anything else to close the program \n");
	
	}
	return 0;
}
