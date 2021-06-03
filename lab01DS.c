#include<stdio.h>
#include<stdlib.h>
int printArray(int *array, int size){
    int count;
    for(count=0;count<size;++count){
        printf("\narray[%d] = %d", count, *(array+count));
    }
    return(count + 1);
}
int insertElementInListAt(int*list, int size, int location, int item){
    int newSizeOfList,count;
    list=realloc(list,((size+1)*sizeof(int)));        // Dynamically re-allocate memory using realloc()
    /* here using for loop to shift the elements to the right,
    to make space for the element to be inserted,then
    starting the loop from the last and shifting elements until the required index  */
    for(count=size;count>=location;count--)
        list[count+1] = list[count];
    list[location] = item;                            // element inserted is at its required index
    newSizeOfList = ++size;                        // size of array increased after insertion
    return newSizeOfList;
}
int deletion(int*list, int size, int index){
    int newSizeOfList,count;
    /* here using for loop to shift the elements to the left,
    after the deletion of the element from the list to fill up the empty index */
    for(count=index ;count < size-1; count++)
        list[count] = list[count+1];                            // every element is shifted to its left to fill empty index
    newSizeOfList = --size;                         // size of array reduced after deletion
    return newSizeOfList;
}
int linearSearch(int*list, int size, int element){
    int newSizeOfList,count;
    /* here for loop is used to search the element traversely,
    until the element is found */
    for(count=0 ;count < size; count++){
        if(list[count]==element){
            printf("\n%d is present at location %d.\n", element, count);
            return count;
        }
    }
    return -1;
}
int main()
{
    int *listA;
    int count, sizeOfListA, element, index, location, item;
    /* for convenience item is used in insertion and element is used in linearSearch as both have same meaning,
    location is used in insertion and index is used in deletion as both have same meaning */
    printf("How many numbers?\n");
	scanf(" %d", &sizeOfListA);
    listA = (int*)malloc(sizeof(int));                             //Dynamically allocating memory using malloc()
    for (count = 0; count < sizeOfListA; ++count)
	{
		printf("\nEnter listA[%d]\n", count);
		scanf(" %d", (listA+count));
	}
	for (count = 0; count < sizeOfListA; ++count)
	{
		printf("\nlistA[%d] = %d\n", count, *(listA+count));
	}
    printf("\nEnter the location where you want to insert the element :\n");
    scanf("%d",&location);
    printf("\nEnter the element to be inserted :\n");
    scanf("%d",&item);
    sizeOfListA = insertElementInListAt(listA, sizeOfListA, location, item);
    printArray(listA, sizeOfListA);
    printf("\n\nElement inserted successfully\n");
    printf("\nEnter the index of the element to be deleted :\n");
    scanf("%d",&index);
    sizeOfListA = deletion(listA, sizeOfListA,index);
    printArray(listA, sizeOfListA);
    printf("\n\nElement deleted successfully\n\n");
    printf("\nEnter the element to be searched :\n");
    scanf("%d",&element);
    int searchElement = linearSearch(listA, sizeOfListA, element);
    free(listA);
    printf("\nMemory successfully freed.\n");
    return 0;
}
