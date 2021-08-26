/* A program to implement circular linked list and develop functions to perform
operations like insertion, deletion and linear search */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *next; //next is pointer of the last node
} *head = NULL; //head points to the first node
//creating a function to insert a new node in the end of list
void insertion(int element)
{
    struct Node *node = head;
    // IF head node is not present
    if (node == NULL)
    {
        node = (struct Node *)malloc(sizeof(struct Node)); 	//Dynamically creating the memory for new node
        node->data = element;
        node->next = node; 		//Change next of new node to point to head
        head = node; 			//Change head to point to recently created node
    }
    else
    {
	/* if the list is not empty,
        shift to the last node pointing towards NULL and dynamically create a new node*/
        while (node->next != head)
        {
            node = node->next;
        }
        // Now node is pointing to last node
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        node->next = newNode;		//pointing the next of last node to the newNode created
        newNode->data = element;	//inserting the data value in the newNode
        newNode->next = head;		//pointing the next of newNode back to the head
    }
}
//creating a function to delete a node from the beginning
int deletion(int element)
{
        int removed;
    if (head  == NULL)
        printf("\nList is empty\n");
    else {
        struct Node *temp = head;
            removed = head->data;
		/*shifting to the last node and then to the temp node created until next of temp doesn't point towards head */
		do
		{
			temp = temp->next;
		}while (temp->next != head);
		temp->next = head->next;		//pointing the next of temp to the next of head node
		temp = head;				//setting temp to head
		head = head->next;			//now pointing the head to the next of previous head node
		free(temp);				//freeing the memory of temp
        }
        return removed;
}
//creating a function to search element in the list traversely
int linearSearch(int data)
{
    struct Node *node = head;
    int index = -1;
    int count = 0;
        if(head != NULL)
        {
                do
                {
                        if (node->data == data)
                        {
                                index = count;
                                break;
                        }
                        count++;
                        node = node->next;
                }while(node != head);
        }
        return index;
}
//creating a function to display all the nodes data from the list circularly
void print()
{

    struct Node *node = head;
    if (node == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {

        printf("\nPrinting the list:\n");
	//it will traverse upto the last node and print the data values from head node to last node
        do
        {
            printf("%d->", node->data);
            node = node->next;
        }while(node != head);
	//to check its circulairty printing again the data value of head node
	printf("%d->", node->data);
        printf("\n");
    }
}
int main()
{

   int element, operation;
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
