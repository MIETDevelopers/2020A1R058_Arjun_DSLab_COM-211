/* A program to implement singly linked list and develop functions to perform
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
    // IF the list is empty, dynamically create a first node
    if (node == NULL)
    {
        node = (struct Node *)malloc(sizeof(struct Node)); //creating a new node dynamically
        node->data = element; 
        node->next = NULL;  //Change next of new node to point to head
        head = node;        //Change head to point to recently created node
    }
    else
    {
    /* if the list is not empty,
    shift to the last node pointing towards NULL and dynamically create a new node*/
        while (node->next != NULL)
        {
            node = node->next;
        }
        // Now node is pointing to last node
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        node->next = newNode;       //next of node will point to new node
        newNode->data = element;    //inserting the data value in newly created node
        newNode->next = NULL;       //making the next of newNode point towards NULL
    }
}
//creating a function to delete a node from the beginning
int deletion(int element)
{
    int removed;
    if (head  == NULL){
        printf("\nList is empty\n");
        return INT_MIN;
    }
    else {
        struct Node *temp = head;
        removed = head->data;       //moving the data value of first node into the removed variable
        head = head->next;          //pointing the head towards the next of to be deleted node i.e 2nd node
        free(temp);             //freeing the memory for the first node
    }
    return removed; 
}
//creating a function to search element in the list traversely
int linearSearch(int data)
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
}
//creating a function to display all the nodes data from the list
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
        //loop will run until the node is not equal to NULL and will print all the data values of list
        while (node != NULL)
        {
            printf("%d->", node->data);
            node = node->next;
        }
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
        case 2:
            printf("\n");
            int removeElement;
            int remove = deletion (removeElement);
            if (remove != INT_MIN)
            {
                printf("%d Removed.", remove);
            }
            else
            {
                printf("%d",INT_MIN);
            }
            break;
        case 3:
            printf("\n");
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