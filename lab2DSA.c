#include <stdio.h>
#include <stdlib.h>
struct stack
{
   int *data;
   int size; //intially size of of the stack is 0.
};
// creating a function to push element into the stack
int pushInStack(struct stack *stack, int value)
{
// if size of stack is 0 then memory will be allocated dynamically using malloc
   if (stack->size == 0)
   {
      stack->data = (int *)malloc(sizeof(int));
   }
// if size of stack is not 0 then memory will be reallocated dynamically using reaclloc
   else
   {
      stack->data = (int *)realloc(stack->data, (stack->size) + 1 * sizeof(int));
   }
   (stack->size)++;
//inserting element into the stack
   *(stack->data + (stack->size) - 1) = value;
   return stack->size;
}
int peek(struct stack *stack)
{
//displaying the element which is at the top of the stack without removing it
   return *(stack->data + (stack->size - 1));
}
// creating a function to pop out the element which is lastly added or at the top of the stack
int popFromStack(struct stack *stack)
{
   int top = peek(stack);
   (stack->size)--;
   return top;
}
int main()
{
// creating the structure with the name stackA
   struct stack stackA;
   stackA.size = 0;
   int value, operation, top;
   do
   {
      printf("Choose an operation\n");
      printf("1.Push In Stack\n");
      printf("2.Pop From Stack\n");
      printf("3.Display Top Element\n");
      printf("4.Exit\n");
      scanf("%d", &operation);
      switch (operation){
         case 1:
            printf("\nEnter the element to be pushed\n");
            scanf("%d", &value);
            pushInStack(&stackA, value);
            printf("\nElement is pushed in the stack\n");
            break;
         case 2:
            top = popFromStack(&stackA);
            printf("%d is popped: \n", top);
            printf("\nTop of the element is: %d \n", peek(&stackA));
            break;
         case 3:
            printf("\nTop of the element is:%d \n", peek(&stackA));
            break;
         case 4:
            printf("\nPress enter to exit\n");
            exit(0);
            break;
         default:
            printf("\nWrong operation\n");
            break;
      }
      printf("\nPress enter to continue");
   }
   while (1);
   return 0;
}
