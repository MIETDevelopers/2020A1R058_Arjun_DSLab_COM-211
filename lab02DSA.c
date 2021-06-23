#include <stdio.h>
#include <stdlib.h>
struct Stack
{
   int *data;
   int maxSize; // maximum size of the stack.
   int top; //initially size of of the stack is 0.
};
// creating a function to check whether the stack is empty or not.
int isEmpty(struct Stack *stack)
{
   if(stack->top == -1){
      return 1;
   }
   else{
      return 0;
   }
}
// creating a function to check whether the stack is full or not.
int isFull(struct Stack *stack)
{
   if(stack->top == stack->maxSize - 1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
// creating a function to push element into the stack.
int pushStack(struct Stack *stack, int value)
{
   if(isFull(stack))
   {
      printf("\nStack Overflow\n");
   }
   else
   {
      stack->top++;
      stack->data[stack->top] = value;
      printf("\nElement pushed successfully\n");
   }
}
// creating a function to pop top element from the stack.
int popStack(struct Stack *stack, int value)
{
   if(isEmpty(stack))
   {
      printf("\nStack Underflow\n");
      return -1;
   }
   else
   {
      value = stack->data[stack->top];
      stack->top--;
      return value;
   }
}
// creating a function to display all the elements of the stack.
void peekStack(struct Stack *stack)
{
   int top;
   if (isEmpty(stack))
   {
      printf("\nStack is empty! \n");
   }
   else
   {
      printf("\nElements in the stack are :\n");
      top = stack->top;
      while (top != -1)
      {
         printf("%d \n", stack->data[top]);
         --top;
      }
   }
}
// creating a function to display the top element of the stack.
int topStack(struct Stack *stack)
{
   int top;
   if (isEmpty(stack))
   {
      printf("\nStack is empty! \n");
   }
   else{
      return top = stack->data[stack->top];
   }
}
int main()
{
   int value, operation, top, maxSize;
   printf("\n\n\t\t\t\t\t\tWelcome Back Arjun\t\t\n");
   printf("\nEnter the size of the stack :");
   scanf("%d", &maxSize);
   // creating the structure with the name stackA
   struct Stack *stackA = (struct Stack *)malloc(sizeof(struct Stack));
   stackA->maxSize = maxSize;
   stackA->top = -1;   // top = -1 means the top is at the index -1 and there is no element in the stack.
   stackA->data = (int *)malloc(stackA->maxSize * sizeof(int));
   do
   {
      printf("\nChoose an operation\n");
      printf("1.Push In Stack\n");
      printf("2.Pop From Stack\n");
      printf("3.Display All Elements of Stack\n");
      printf("4.Display Top Element of Stack\n");
      printf("5.Exit\n");
      scanf("%d", &operation);
      switch (operation){
         case 1:
            printf("\nEnter the element to be pushed\n");
            scanf("%d", &value);
            pushStack(stackA, value);    // calling the push function
            break;
         case 2:
            printf("\nPop out the element\n");
            int popped = popStack(stackA,value); // calling the pop function
            if (stackA->top == -1 && popped == 0)
            {
            // s->top is -1 which means the stack is empty
               return 2;
            }
            else
               printf("%d popped from the stack \n", popped);
            break;
         case 3:
            peekStack(stackA);       // calling the peek function
            break;
        case 4:
            printf("\nElement at the top of the Stack is %d\n", topStack(stackA));   // calling the top function
            break;
         case 5:
            printf("\nPress enter to exit\n");
            exit(0);
            break;
         default:
            printf("\nWrong operation\n");
            break;
      }
   }
   while (1);
   return 0;
}
