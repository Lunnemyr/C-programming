//Inlämningsuppgift 5
//Henrik Axelsson, 750328-4999

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include "menu.h"
//end includes




//function show_menu
void show_menu()
{
    printf("\n\n*****  MENY  *****\n\n");
    printf("   1. Lägg till en nod i kön\n");
    printf("   2. Ta bort en nod ur kön\n");
    printf("   3. Sök efter nod med specifik data och ta bort noden\n");
    printf("   4. Skriv ut kön\n");
    printf("   5. Avsluta\n\n");
    printf("Ange ett alternativ 1-5:");
}
//END show menu


//function run_selection
void run_selection(int selection)
{
   switch(selection){ //för att starta "rätt" menyval enligt användarens inmatning

   case 1 :
      //Lägg till nod i kön
      add_to_queue();
      break;

   case 2 :
       //Ta bort nod ur kön
       remove_from_queue();
       break;

   case 3 :
       //Säk och ta bort
       delete_from_queue();
       break;

   case 4 :
       //Skriv ut hela kön
       print_queue();
       break;

   case 5 :
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
    if (valt_tal < 1 || valt_tal >5) {
    printf("Fel, talet skall vara mellan 1 och 5! \n\n"); //kolla om talet är mellan 1 & 4
    show_menu(); //om inte - visa menyn igen tills användare väljer "rätt"
    }
}while(valt_tal < 1 || valt_tal >5);
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
