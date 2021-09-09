// C program to convert infix expression to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
char result[100];
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};
struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array = (int*) malloc(stack->capacity *
								sizeof(int));

	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}
int peek(struct Stack* stack)
{
	return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return '$';
	else
		return stack->array[stack->top--] ;
}
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}


// A utility function to check if the given character is operand
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

/* A utility function to return
precedence of a given operator higher returned value means higher precedence */
int precedence(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}
// creating a function that converts given infix expression to postfix expression.
int infixToPostfix(char* expression)
{
	int index, k;
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(expression));
	if(!stack) // See if stack was created successfully
		return -1 ;
	for (index = 0, k = -1; expression[index] != '\0'; ++index)
	{
		
		// If the scanned character is an operand, add it to output.
		if(expression[index] == ' ')
            continue;
		else if (isOperand(expression[index]))
			result[++k] = expression[index];
		
		// If the scanned character is an opening bracket, push it to the stack.
		else if (expression[index] == '(' || expression[index] == '[' || expression[index] == '{')
			push(stack, expression[index]);
		
		/* If the scanned character is an closing bracket,
		 pop and output from the stack until an ‘(‘ is encountered. */
		else{ 
			if (expression[index] == ')')
			{
				while (!isEmpty(stack) && peek(stack) != '(')
					result[++k] = pop(stack);
				if (!isEmpty(stack) && peek(stack) != '(')
					return -1; // invalid expression			
				else
					pop(stack);
			}
			else if (expression[index] == ']')
			{
				while (!isEmpty(stack) && peek(stack) != '[')
					result[++k] = pop(stack);
				if (!isEmpty(stack) && peek(stack) != '[')
					return -1; // invalid expression			
				else
					pop(stack);
			}
			else if (expression[index] == '}')
			{
				while (!isEmpty(stack) && peek(stack) != '{')
					result[++k] = pop(stack);
				if (!isEmpty(stack) && peek(stack) != '{')
					return -1; // invalid expression			
				else
					pop(stack);
			}
			else // an operator is encountered
			{
				while (!isEmpty(stack) && precedence(expression[index]) <= precedence(peek(stack)))
					result[++k] = pop(stack);
				push(stack, expression[index]);
			}
		}	
	}
	// pop all the operators from the stack
	while (!isEmpty(stack))
		result[++k] = pop(stack );

	result[++k] = '\0';
	//printf( "%s", expression );
}
// function to reverse the expression
void reverse(char *expression){    
    int index , revIndex;
    char temp[100];
    // int size = strlen(expression);
    for(index = strlen(expression) - 1, revIndex = 0; index+1 != 0; --index, ++revIndex)
    {
    	temp[revIndex] = expression[index];
    }
    temp[revIndex] = '\0';
    strcpy(expression,temp);
}
int main()
{
	int index, operation;
	char expression[100];
	printf("\n\t\t\t\tWelcome back Arjun\n");
	printf("\nEnter the expression : \n");
	gets(expression);
	do
	{
        printf("\nChoose any option\n");
        printf("1. Infix to Postfix Conversion \n");
        printf("2. Infix to Prefix Conversion \n");
        printf("3. Exit \n\n");
        scanf("%d", &operation);
        switch (operation)
        {
            case 1:
            	infixToPostfix(expression);
            	printf("\nThe Required Postfix Expression :\n");
    			printf("%s", result);
                break;
            case 2:
				reverse(expression);
				for(index=0; expression[index] != '\0'; index++)
				{
				if(expression[index]=='(')
					expression[index]=')';
				else if(expression[index]=='[')
					expression[index]=']';
				else if(expression[index]=='{')
					expression[index]='}';
				else if(expression[index]==')')
					expression[index]='(';
				else if(expression[index]==']')
					expression[index]='[';
				else if(expression[index]=='}')
					expression[index]='{';
				}
				infixToPostfix(expression);
				reverse(result);
				printf("\nThe Required Prefix Expression :\n");
				printf("%s\n",result);
                break;
            case 3:
                printf("\nPress any key to exit\n");
                exit(0);
                break;
            default:
                printf("\nError!\n");
                break;
        }
        printf("\nContinue the process\n");
    }
    while(1);
    return 0;
}