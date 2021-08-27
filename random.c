#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next; //next is pointer of the last node
} *head = NULL; //head points to the first node
/*int linearSearch(int data)
{
    struct Node *node = head;
    int index = -1;
    int count = 0;
    while (node != NULL)
    {
        if (node->data == data)
        {
            index = count;
            break;
        }
        count++;
        node = node->next;
    }
    return index;
}*/
/*void insertion(int element)
{
    struct Node *node = head; 		// IF head node is not present
    if (node == NULL)
    {
        node = (struct Node *)malloc(sizeof(struct Node)); //Memory for new node
        node->data = element;
        node->next = NULL; //Change next of new node to point to head
        head = node; //Change head to point to recently created node
    }
    else
    {

        while (node->next != NULL)
        {
            node = node->next;
        }
        // Now node is pointing to last node
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        node->next = newNode;
        newNode->data = element;
        newNode->next = NULL;
    }
}*/
int isEmpty(struct Node* node){
    if (node==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* node){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void insertion(int element)  
    {  
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node ));  
        if(isFull(newNode)) 
        {  
            printf("\nStack Overflow\n");  
        }  
        else  
        {  
            newNode->data = element;  
            newNode->next = head;  
            head = newNode;  
            printf("\nNode inserted successfully\n");  
        }  
     }  
int deletion(int element)
{
	struct Node *node = head;
        int removed;
    if (isEmpty(node)){
        printf("\nStack Underflow\n");
	return INT_MIN;
	}
    else {
        struct Node *temp = head;
            removed = head->data;
            head = head->next;
            free(temp);
        }
        return removed;
}
void top()
{
	struct Node *node = head;
	if (node == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {

        printf("\nPrinting the list:\n");
        printf("\nElement at top of the list : %d", node->data);
	printf("\n");
    }
}
void print()
{

    struct Node *node = head;
    if (node == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {

        printf("\nPrinting the list:\n");
        while (node != NULL)
        {
                printf("%d->", node->data);
                node = node->next;
        }
	printf("NULL");
       printf("\n");
    }
}
int main()
{

   int element, operation1, operation2;
	struct Node *node = head;
   printf("\n\n\t\t\t\t\t\tWelcome Back Arjun\t\t\n");
    do
    {
        printf("\nEnter the operation\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Display Top\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        scanf("%d", &operation1);
        switch (operation1)
        {
        case 1:
		do
        	{
                printf("\n\nChoose any option\n");
                printf("1.Want to add new node\n");
                printf("2.Do not want to add new node\n");
		printf("0.Back\n");
                scanf("%d", &operation2);
                switch(operation2)
                {
                        case 1:
                                if(node == NULL || node != NULL){
				printf("\nEnter the element you want to insert:\n");
            			scanf("%d", &element);
            			insertion(element);
				}
                                break;
                        case 2:
				print();
				isFull(node);
                                printf("\nStack Overflow\n");
				break;
                        default:
				if((operation2 != false))
                                printf("\nWrong choice, try again\n");
                                break;
                }
        	}while(operation2 != false);
		break;
        case 2:;
            int removeElement;
            int remove = deletion (removeElement);
            if (remove != INT_MIN)
            {
                printf("%d Removed.", remove);
            }
		printf("\n");
            break;
        case 3:;
            top();
            break;
        case 4:
            print();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    } while (1);
    return 0;
}
