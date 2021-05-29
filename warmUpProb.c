#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *array;
    int numberOfElements, i;
    printf("Enter number of elements:\n",numberOfElements);
    scanf("%d",&numberOfElements);
    array = (int*)malloc(numberOfElements * sizeof(int));            // Dynamically allocate memory using malloc()
     if (array == NULL || array == NULL) {              /*Check if the memory has been successfully
                                                        allocated by malloc or not*/
        printf("\nMemory not allocated.\n");
        exit(0);
    }
    else {
        printf("\nMemory successfully allocated using malloc.\n");
        for (i = 0; i < numberOfElements; ++i) {
            array[i] = i + 1;
        }
        printf("\nThe elements of the array are:\n");
        for (i = 0; i < numberOfElements; ++i) {
            printf("%d ", array[i]);
        }
                printf("\n\nEnter the element to be searched:\n");
        scanf("%d", &numberOfElements);
        for (i = 0; i < numberOfElements; i++)
        {
            if (array[i] == numberOfElements)
            {
                printf("%d is present at location %d.\n", numberOfElements, i);
                break;
                }
        }
        if (i == numberOfElements)
        printf("%d is not present in the array.\n", numberOfElements);
    }
        printf("\n\nEnter the new size of the array:\n", numberOfElements);
        scanf("%d",&numberOfElements);
        array = realloc(array, (numberOfElements + 1) * sizeof(int));         // Dynamically re-allocate memory using realloc()
        printf("\nMemory successfully re-allocated using realloc.\n");
        // Get the new elements of the array
        for (i = 0; i < numberOfElements; ++i) {
            array[i] = i + 1;
        }
        printf("\nThe elements of the array are:\n");
        for (i = 0; i < numberOfElements; ++i) {
            printf("%d ", array[i]);
        }
    free(array);
    printf("\n\nMemory successfully freed.\n");
    return 0;
}
