#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkArrayEmpty (const char ** anArrayPtr)
{
    int result = -1;
    if (anArrayPtr != NULL)
        {
        result = 0;
        }
    return result;
//return -1 if array is empty, that is if null?
}

size_t calcLongestStringInArray (const char ** anArrayPtr, size_t arrayLength)
{
    size_t result = 0;
    for (int i=0; i<arrayLength;i++)
    {
       if (result < strlen(anArrayPtr[i]))
       {
            result = strlen(anArrayPtr[i]);
       }
    }
    return result;
}

size_t calcShortestStringInArray (const char ** anArrayPtr, size_t arrayLength)
{
    size_t result = strlen(anArrayPtr[0]);
    for (int i=0; i<arrayLength;i++)
    {
       if (result > strlen(anArrayPtr[i]))
       {
            result = strlen(anArrayPtr[i]);
       }
    }
    return result;
}


int main()
{

    const char * array1[] = {"", "Gnu", "Hoppsan", "Fem", "Hoppsan", "Hoppsans", "R"};
    size_t firstArrayLength = sizeof(array1)/sizeof(array1[0]);

    printf("Length of array 1 is: %zd\n", firstArrayLength);

    const char * array2[] = {""};
    size_t secondArrayLength = sizeof(array2)/sizeof(array2[0]);

    const char ** array3 = NULL;

    printf("Checking if array 1 is empty, result is: %d\n", checkArrayEmpty(array1));
    printf("Checking if array 2 is empty, result is: %d\n", checkArrayEmpty(array2));
    printf("Checking if array 3 is empty, result is: %d\n", checkArrayEmpty(array3));


    size_t maxl = calcLongestStringInArray(array1, firstArrayLength);
    printf("Longest string in array1 = %zd\n", maxl);
    size_t minl = calcShortestStringInArray(array1, firstArrayLength);
    printf("Shortest string in array1 = %zd\n", minl);


    size_t maxl2 = calcLongestStringInArray(array2, secondArrayLength);
    printf("Longest string in array2 = %zd\n", maxl2);
    size_t minl2 = calcShortestStringInArray(array2, secondArrayLength);
    printf("Shortest string in array2 = %zd\n", minl2);

    //printf("Length of the ColorPtr string is: %d\n", )
    for (int i=0; i<firstArrayLength;i++)
        {
        printf("Array 1 [%d]: %s\n",i, array1[i]);
        }

    printf("Array 2: %s", *array2);
    //for (int i=0; i<= 7;i++)
    return 0;
}
