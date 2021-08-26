/* A program to implement doubly linked list and develop functions to perform
operations like insertion, deletion and linear search */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next; //next is pointer of the last node
	struct Node *prev;
};
struct Node *head; //head points to the first node
// creating a function to insert a new node in the end of list
void insertion(int element)
{
    struct Node *node = head;
    // IF head node is not present, dynamically create a node
    if (node == NULL)
    {
        node = (struct Node *)malloc(sizeof(struct Node)); //Memory for new node
        node->data = element; 
        node->next = NULL; 	//making next of new node to point to NULL
        node->prev = NULL; 	//making prev of new node to point to NULL
	head = node; 		//making head to point to recently created node
    }
    else
    {
	/* if list is not empty, shift the last node,
	and create a new node in the last of list */
        while (node->next != NULL)
        {
            node = node->next;
        }
        // Now node is pointing to last node
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        node->next = newNode;		//next of last node will point towards newNode
	newNode->prev = node;		//prev of newNode will point towards earlier last node
        newNode->data = element;	//inserting the data value in the newNode
        newNode->next = NULL;		//setting the next of newNode to point towards NULL
    }
}
//creating a function to delete first node of the list
int deletion(int element)
{
	int removed;
    if (head  == NULL)
        printf("\nList is empty\n");
    else {
	struct Node *temp = head;
            removed = head->data;		//moving the data value of head node into the removed variable
            head = head->next;			//now head will point towards next of earlier head node
		head->prev = NULL;		//prev of new head node point towards NULL
            free(temp);				//freeing the memory of node to be deleted
	}
	return removed;
}
//creating a function to search element in forward list as well as backward list
int linearSearch(int data)
{
    struct Node *node = head;
    int index = -1;
    int count = 0;
        int choice;
        do{
        /* press 1 if you want to search element in forward list, and
	press 2 if you want to search element in backward list */
	printf("\n\nChoose any option\n\n");
        printf("1.Search element in Forward list");
        printf("\n2.Search element in Reverse list\n\n");
        scanf("%d", &choice);
        switch(choice)
        {
                case 1:
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
                        break;
                case 2:
                        while(node->next != NULL){
                                node = node->next;
                        }
                        while (node != NULL)
                        {
                                if (node->data == data)
                                {
                                        index = count;
                                        break;
                                }
                        count++;
                        node = node->prev;
                        }
                        return index;
                        break;
                default:
                                printf("\nWrong choice, try again\n");
                                break;
        }
        }
        while(1);
        return -1;
}
//creating a function to print forward list
void printForward()
{

    struct Node *node = head;
    if (node == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {
        printf("\nPrinting the list in forward order:\n");
        while (node != NULL)
        {
            printf("%d->", node->data);
            node = node->next;
        }
        printf("\n");
    }
} 
//creating a function to reverse the list and print in reverse order
void printBackward()
{

    struct Node *node = head;
    if (node == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {
	while(node->next != NULL){
		node = node->next;
	}
        printf("\nPrinting the list in reverse order:\n");
        while (node != NULL)
        {
            printf("%d->", node->data);
            node = node->prev;
        }
        printf("\n");
    }
}
int main()
{

   int element, operation, choice;
   printf("\n\n\t\t\t\t\t\tWelcome Back Arjun\t\t\n");
    do
    {
        printf("\nEnter the operation\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Linear Search\n");
        printf("4.Display\n");
	printf("5.Exit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("\nEnter the element you want to insert:\n");
            scanf("%d", &element);
            insertion(element);
            break;
        case 2:;
            int removeElement;
            int remove = deletion (removeElement);
            if (remove != INT_MIN)
            {
                printf("%d Removed.", remove);
            }
            else
            {
                printf("No element Like that found");
            }
            break;
        case 3:;
            int searchElement;
            printf("\nEnter the element you want to search\n");
            scanf("%d", &searchElement);
            int search = linearSearch(searchElement);
            if (search != -1)
            {
                printf("\nElement found at index : %d\n", search);
            }
            else{
                printf("\nElement not found\n");
            }
            break;
        case 4:
            printForward();
            printBackward();
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
