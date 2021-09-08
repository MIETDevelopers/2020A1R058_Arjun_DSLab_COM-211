// A program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct Stack
{
	int top;
	unsigned maxSize;
	int *array;
};
struct Stack* createStack( unsigned maxSize )
{
	struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->maxSize = maxSize;
	stack->array = (int*) malloc(stack->maxSize * sizeof(int));
	return stack;
}
int isEmpty(struct Stack *stack)
{
	return stack->top == -1 ;
}
int peek(struct Stack *stack)
{
	return stack->array[stack->top];
}
int pop(struct Stack *stack)
{
	if(isEmpty(stack))
	{
    	printf("\nStack Underflow\n");
    	return '\0';
	}
	else
		return stack->array[stack->top--] ;
}
void push(struct Stack* stack,int value)
{
	stack->array[++stack->top] = value;
}
// creating a function that returns value of a given postfix expression
int evaluatePostfix(char* expression)
{
	// Create a stack of maxSize equal to expression size
	struct Stack* stack = createStack(strlen(expression));
	int index;
	for (index = 0; expression[index]; ++index)
	{
		//if the character is blank space then continue
		if(expression[index] == ' ')
			continue;
		/* If the scanned character is an operand (number here),extract the full number
		and push it to the stack. */
		else if (isdigit(expression[index]))
		{
			int num=0;
			//extract full number
			while(isdigit(expression[index]))
			{
			num=num*10 + (int)(expression[index]-'0');
				index++;
			}
			index--;
			//push the element in the stack
			push(stack,num);
		}
		
		// If the scanned character is an operator, pop two elements from stack and apply the operator
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			
			switch (expression[index])
			{
				case '+':
					push(stack, val2 + val1);
					break;
				case '-':
					push(stack, val2 - val1);
					break;
				case '*':
					push(stack, val2 * val1);
					break;
				case '/':
					push(stack, val2/val1);
					break;
			}
		}
	}
	return pop(stack);
}
int main()
{
	char expression[100];
	printf("\n\t\t\t\tWelcome back Arjun\n");
	printf("\nEnter the expression : \n");
	gets(expression);
	printf ("%d", evaluatePostfix(expression));
	return 0;
}