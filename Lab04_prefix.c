// A program to evaluate value of a prefix expression
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
// creating a function that returns value of a given prefix expression
int evaluatePrefix(char *expression)
{
	struct Stack* stack = createStack(strlen(expression));
	for (int bwdIndex = strlen(expression) - 1; bwdIndex >= 0; bwdIndex--) {
	
		// if bwdIndexth character is the delimiter ( which is space in this case) then skip it
		if (expression[bwdIndex] == ' ')
			continue;
		if (isdigit(expression[bwdIndex])) {
			// there may be more than one digits in a number
			int num = 0;
			int count;
			int fwdIndex = bwdIndex;
			while (bwdIndex < strlen(expression) && isdigit(expression[bwdIndex]))
				bwdIndex--;
			bwdIndex++;			
			// from [bwdIndex, fwdIndex] expression contains a number
			for (int count = bwdIndex; count <= fwdIndex; count++)
				num = num * 10 + (int)(expression[count] - '0');
			push(stack,num);
		}
		else {
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (expression[bwdIndex]) {
			case '+':
				push(stack, val1 + val2);
				break;
			case '-':
				push(stack, val1 - val2);
				break;
			case '*':
				push(stack, val1 * val2);
				break;
			case '/':
				push(stack, val1 / val2);
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
	printf ("%d", evaluatePrefix(expression));
	return 0;
}
