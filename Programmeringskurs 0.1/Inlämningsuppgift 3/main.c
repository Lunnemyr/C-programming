//Inlämningsuppgift nr 3, Henrik Axelsson, 750328-4999
//C-programmering DA105A, HT2013, Malmö Högskola

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //deklarerar en symbolisk konstant

//Funktionsprototyper
void fill_rand_ver1(int array[], int size);
void sort_ver1(int array[], int size);
void print_values_ver1(char string[], int array[], int size);

void fill_rand_ver2(int *pointer, int size);
void sort_ver2(int *pointer, int size);
void print_values_ver2(char *string, int *pointer, int size);
//end prototyper


//Start mainfunktion
int main()
{
    int array[SIZE]; //Deklarerar en array av int
    srand(time(0)); //frö till rand()

    //Fyll arrayen med slumptal
    fill_rand_ver1(array, SIZE);

    //skriv ut textsträngen och arrayens värden
    print_values_ver1("Osorterad array, version 1", array, SIZE);

    //stortera arrayen
    sort_ver1(array, SIZE);

    //Skriv ut sorterad array
    print_values_ver1("Sorterad array, version 1", array, SIZE);

    int *pointer; //deklarerar en pekare av typen integer

    pointer = array; //Pekaren initieras att peka på element nr 1 i arrayen

    //Fyll arrayen med nya slumptal
    fill_rand_ver2(pointer, SIZE);

    //skriv ut textsträngen och arrayens värden
    print_values_ver2("Osorterad array, version 2", pointer, SIZE);

    //stortera arrayen
    sort_ver2(pointer, SIZE);

    //Skriv ut sorterad array
    print_values_ver2("Sorterad array, version 2", pointer, SIZE);

    return 0;
} //End main


//Function body fill_rand_ver1(()
void fill_rand_ver1(int array[], int size)
{
 int i; //räknare
 for(i=0; i<size; i++){  //loopa igenom arrayen
    array[i] = (rand()%10)+1; //tilldela slumptal till varje element
    } //end for
} //end fill_rand_ver1()


//Function body sort_ver1()
void sort_ver1(int array[], int size)
{
  int i, j, temp;
  for(i=0; i<size; i++){
    for (j=i+1; j<size; j++){
        if (array[j]<array[i]){
            temp = array[i]; //stoppa värdet för i i en temporär variabel
            array[i] = array[j]; //kopiera värdet för j till pos i
            array[j] = temp; //kopiera temp-värdet (tidigare i-värdet) till j
        }//end if
    } //end inre for loop
  } //end yttre for-loop
} //end sort_ver1()


//Function body print_values_ver1()
void print_values_ver1(char string[], int array[], int size)
{

    int j; // räknare till for loop
    printf("%s\n", string); //skriv ut strängen först

    //Skriv ut talen i arrayen
    for (j=0; j<size; j++){
       printf("%d ", array[j]);
    } //end for
    printf("\n\n");
}//end print_values_ver1()

//
//-------------------------------------------------
//VERSION 2 av funktionerna


//Function body fill_rand_ver2(()
void fill_rand_ver2(int *pointer, int size)
{
 int *pi; //räknare
 for(pi=pointer; pi < (pointer + size); pi++){  //loopa igenom adresserna
    *pi = (rand()%10)+1; //tilldela slumptal till det element som pekas på
    } //end for
} //end fill_rand_ver2()


//Function body sort_ver2()
void sort_ver2(int *pointer, int size)
{
  int *pi, *pj;
  int temp; //temporär variabel för "swap"
  for(pi = pointer; pi < (pointer + size); pi++){
    for (pj=pi+1; pj < (pointer + size); pj++){
        if (*pj < *pi){
            temp = *pi; //stoppa värdet på adressen pi i en temporär variabel
            *pi = *pj; //kopiera värdet för adressen pj till pos pi
            *pj = temp; //kopiera temp-värdet (tidigare pi-värdet) till elemet på
                        //adressen pj
        }//end if
    } //end inre for loop
  } //end yttre for-loop
} //end sort_ver2()


//Function body print_values_ver2()
void print_values_ver2(char *string, int *pointer, int size)
{

    int *pj; // pekare  till for loop
    printf("%s\n", string); //skriv ut strängen först

    //Skriv ut talen i arrayen
    for (pj = pointer; pj < (pointer + size); pj++){
       printf("%d ", *pj);
    } //end for
    printf("\n\n");
}//end print_values_ver2()
