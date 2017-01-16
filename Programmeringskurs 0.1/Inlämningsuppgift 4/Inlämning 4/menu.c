//Inlämningsuppgift 4
//Henrik Axelsson, 750328-4999

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include "menu.h"
//end includes

//PROTOTYPER, behöver dem ej i h-filen, syns bara här.
//Function add_to_queue, läser in och lägger till en person till kön
void add_to_queue();

//Function remove_from_queue, tar bort en person från kön
void remove_from_queue();

//Function print_queue, skriver ut hela kön
void print_queue();
//Slut PROTOTYPER


//function show_menu
void show_menu()
{
    printf("\n\n*****  MENY  *****\n\n");
    printf("   1. Lägg till person i kön\n");
    printf("   2. Ta bort en person ur kön\n");
    printf("   3. Skriv ut kön\n");
    printf("   4. Avsluta\n\n");
    printf("Ange ett alternativ 1-4:");
}
//END show menu


//function run_selection
void run_selection(int selection)
{
   switch(selection){ //för att starta "rätt" menyval enligt användarens inmatning

   case 1 :
      //Lägg till person i kön
      add_to_queue();
      break;

   case 2 :
       //Ta bort person ur kön
       remove_from_queue();
       break;

   case 3 :
       //Skriv ut hela kön
       print_queue();
       break;

   case 4 :
       printf("Du valde att avsluta\n\n");
       exit(0); //avbryt programmet om användaren väljer 4
       break;
   }
}
//end run_selection

//function get_selection
int get_selection()
{
   int valt_tal;

do {
    scanf("%d", &valt_tal); //läs in menyvalet
    if (valt_tal < 1 || valt_tal >4) {
    printf("Fel, talet skall vara mellan 1 och 4! \n\n"); //kolla om talet är mellan 1 & 4
    show_menu(); //om inte - visa menyn igen tills användare väljer "rätt"
    }
}while(valt_tal < 1 || valt_tal >4);
return valt_tal; //skicka tillbaks det användaren valt
}
//end get_selection

// function pause
int pause()
{
    int c;
    printf("\n\nTryck enter för att fortsätta!");
    //Tömmer inmatningsströmmen
    while((c=getchar()) != '\n' && c !=EOF);
    getchar();
    return 1;
}
//end pause

//Implementation av add_to_queue
void add_to_queue()
{
    person_type temp_person;
    printf("\n\nLägg till en person i kön.\n");

    if (is_full()) {
        printf("\nKön är full! Ta bort en person ur kön om du vill lägga till.\n");
    } //end if
    else {
        printf("\nFörnamn: ");
        scanf("%20s", temp_person.firstName);
        printf("Efternamn: ");
        scanf("%20s", temp_person.surName);
        printf("Personnummer: ");
        scanf("%11s", temp_person.persNbr);
        //print_name(&temp_person);
        enqueue(temp_person);

    } //end else
}//end add_to_queue

//Implementation av remove_from_queue
void remove_from_queue()
{
    printf("\n\nTa bort en person ur kön.\n");

    //Kolla först om kön är tom
    if (is_empty()) {
        printf("\nKön är tom, finns ingen person att ta bort.\n");
    } //end if
    else {   //Om kön inte är tom, ta bort en person och skriv ut den borttagna personen
        person_type temp_person;
        dequeue(&temp_person);
        printf("\nDen borttagna personens data är:\n");
        print_name(&temp_person);
    }
}

//Implementation av print_queue
void print_queue()
{
    printf("\n\nSkriv ut kön.\n");
    person_type print_person; //tillfällig lagring för utskriften
    int nbr_in_queue = get_number_of_pers(); //hämtar antalet i kön

    int i; //räknare för for-loopen

    //Kolla först om kön är tom
    if (is_empty()) {
        printf("\nDet finns inget att skriva ut.");
    } //end if
    else {
        for(i = 0; i < nbr_in_queue; ++i) {
        printf("\nKöplats nr: %d\n", (i+1));
        get_person(&print_person, i);
        print_name(&print_person);
        } //end for
    } //end else
} //end print_queue
