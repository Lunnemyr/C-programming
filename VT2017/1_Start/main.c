#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
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
*/

int mxdiflg(const char **firstArray, size_t firstArrayLength, const char **secondArray, size_t secondArrayLength)
{
    int result = 0;



    if (firstArray == NULL || secondArray == NULL)
    {
    result = -1;
    printf("En av arrayerna var NULL\n");}
    else
    {
        size_t minl1 = strlen(firstArray[0]);
        size_t maxl1 = strlen(firstArray[0]);
        size_t minl2 = strlen(secondArray[0]);
        size_t maxl2 = strlen(secondArray[0]);
        printf("mxdiflg startvärden: \nMin1 = %zd\nMax1 = %zd\nMin2 = %zd\nMax2 = %zd\n", minl1, maxl1, minl2, maxl2);
        /* Find shortest string in first array*/
        for (int i=0; i<firstArrayLength;i++)
        {
            if (minl1 > strlen(firstArray[i]))
            {
            minl1 = strlen(firstArray[i]);
            }
        }

        /* Find longest string in first array*/
        for (int i=0; i<firstArrayLength;i++)
        {
            if (maxl1 < strlen(firstArray[i]))
            {
            maxl1 = strlen(firstArray[i]);
            }
        }
        /* Find shortest string in second array*/
        for (int i=0; i<secondArrayLength;i++)
        {
            if (minl2 > strlen(secondArray[i]))
            {
            minl2 = strlen(secondArray[i]);
            }
        }

        /* Find longest string in first array*/
        for (int i=0; i<secondArrayLength;i++)
        {
            if (maxl2 < strlen(secondArray[i]))
            {
            maxl2= strlen(secondArray[i]);
            }
        }

        printf("mxdiflg beräknar: \nMin1 = %zd\nMax1 = %zd\nMin2 = %zd\nMax2 = %zd\n", minl1, maxl1, minl2, maxl2);
        result = abs(maxl1-minl2);
        if (abs(maxl2-minl1)>abs(maxl1-minl2))
        {
            result = abs(maxl2-minl1);
        }
    }
    return result;
}


int main()
{

    const char * array1[] = {"rastlos", "Gnu", "Hoppsan", "Fem", "Hoppsan", "Hoppsans", "R"};
    size_t firstArrayLength = sizeof(array1)/sizeof(array1[0]);
    printf("Length of array 1 is: %zd\n", firstArrayLength);

    const char * array2[] = {"Kalleballeballe", "hopparesnoppare", "Gnuburgarehoppsan"};
    size_t secondArrayLength = sizeof(array2)/sizeof(array2[0]);
    printf("Length of array 2 is: %zd\n", secondArrayLength);

    const char ** array3 = NULL;
    size_t thirdArrayLength = sizeof(array3)/sizeof(array3[0]);
    printf("Length of array 3 is: %zd\n", thirdArrayLength);

    const char ** array4 = NULL;
    size_t fourthArrayLength = sizeof(array4)/sizeof(array4[0]);
    printf("Length of array 4is: %zd\n", fourthArrayLength);

    /* TEST 1*/
    printf("\n\nTest 1\n");
    int expectedResult = 16;
    int actualResult = mxdiflg(array1, firstArrayLength, array2, secondArrayLength);
    printf("Expected Result = %d\nActual Result = %d\n", expectedResult, actualResult);


    /* TEST 2*/
    printf("\n\nTest 2\n");
    expectedResult = -1;
    actualResult = mxdiflg(array1, firstArrayLength, array3, thirdArrayLength);
    printf("Expected Result = %d\nActual Result = %d\n", expectedResult, actualResult);


    /* TEST 3*/
    printf("\n\nTest 3\n");
    expectedResult = -1;
    actualResult = mxdiflg(array4, fourthArrayLength, array3, thirdArrayLength);
    printf("Expected Result = %d\nActual Result = %d\n", expectedResult, actualResult);

    /*
    printf("Checking if array 1 is empty, result is: %d\n", checkArrayEmpty(array1));
    printf("Checking if array 2 is empty, result is: %d\n", checkArrayEmpty(array2));
    printf("Checking if array 3 is empty, result is: %d\n", checkArrayEmpty(array3));

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
    */

    return 0;
}
