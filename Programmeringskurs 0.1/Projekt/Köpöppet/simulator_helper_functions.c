//Projektuppgift K�p�ppet
//Henrik Axelsson, 750328-4999

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulator_helper_functions.h"
#include <time.h>

//Prototyper
static int PauseSec(int x);



//************************************
//PAUSE
//************************************

//Kollar om det �r stegsimulering -> v�nta p� anv�ndaren. Returnerna 1 s� k�rs loopen igen.
//Om inte, s� kolla om tid finns kvar f�r simuleringen, annars returnera 0, avslutar simuleringen

int Pause(int isStepSimulation, int iTimeToRunSimulation, int iPauseTime)
{
    int c;

    if (isStepSimulation) {
        printf("\nTryck enter f�r att forts�tta.");         //T�mmer inmatningsstr�mmen
        while((c=getchar()) != '\n' && c !=EOF);
        getchar();
        return 1;
    }
    else if(iTimeToRunSimulation>0) {                       //Om det �r en icke stegad simulering
        PauseSec(iPauseTime);                               //S� l�ggs en paus i varje steg
        return 1;
    }
    else {                                                  //Annars �r simuleringen klar
        return 0;
    }
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//GET SELECTION
//************************************
void GetSelection(int * iSelection, char cText [], int iMin, int iMax)
{
  do {
    printf("%s", cText);                                    //Skriv ut texten f�r detta val
    scanf("%d", iSelection);                                //L�s in
    if ((*iSelection < iMin) || (*iSelection > iMax)) {     //kolla att inom till�tet intervall
        printf("Fel, talet skall vara mellan %d och %d!\n\n", iMin, iMax);
    }
  }while(*iSelection < iMin || *iSelection > iMax);
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//INTERVALL RANDOM NUMBER
//************************************

//Returnerar ett v�rde mellan 1 och 4
//Talet baseras p� f�rdelningen iProbabilities
//Anv�nds sedan f�r att best�mma antal nya kunder.
//�ven denna funktion �r "l�nad" fr�n n�tet.
int IntervallRandNumber()
{
    int iProbabilities [4] = {1, 3, 5, 1};                  //Enligt projektdefinitionen
    int iSumOfWeight = 0;
    int NbrOfChoices = 4;
    int i;

    for(i=0; i<NbrOfChoices; i++) {
        iSumOfWeight += iProbabilities[i];
    }

    int rnd = RandomInRange(0, iSumOfWeight);

    for(i=0; i<NbrOfChoices; i++) {
        if(rnd < iProbabilities[i]) {
            return i;
        }
        rnd -= iProbabilities[i];
    }
printf("IntervallRandNumber should never get here");
return 0;
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//RANDOM IN RANGE
//************************************

//Returnerar ett slumptal i intervallet min till max.
//Denna funktion �r "l�nad" p� n�tet och integrerad i min kod.
int RandomInRange (int min, int max)
{
  int base_random = rand(); /* in [0, RAND_MAX] */
  if (RAND_MAX == base_random) return RandomInRange(min, max);

  /* now guaranteed to be in [0, RAND_MAX) */
  int range       = max - min,
      remainder   = RAND_MAX % range,
      bucket      = RAND_MAX / range;

  /* There are range buckets, plus one smaller interval
     within remainder of RAND_MAX */
  if (base_random < RAND_MAX - remainder) {
    return min + base_random/bucket;
  }
  else {
    return RandomInRange (min, max);
  }
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//PAUSE SEC
//************************************

//Liten pausfunktion, l�nad fr�n n�tet, anv�nder sekunder
static int PauseSec(int x)
 {
    //long T1;
    long T3;
    long T2;
      //T1 = time(&T2);
      T3 = (time(&T2)) + x;
      while(time(&T2) < T3);
    return(x);
 }
 //-----------------------------------------------------------------------------------------------------------------------

