//Inl�mningsuppgift 5
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
    printf("   1. L�gg till en nod i k�n\n");
    printf("   2. Ta bort en nod ur k�n\n");
    printf("   3. S�k efter nod med specifik data och ta bort noden\n");
    printf("   4. Skriv ut k�n\n");
    printf("   5. Avsluta\n\n");
    printf("Ange ett alternativ 1-5:");
}
//END show menu


//function run_selection
void run_selection(int selection)
{
   switch(selection){ //f�r att starta "r�tt" menyval enligt anv�ndarens inmatning

   case 1 :
      //L�gg till nod i k�n
      add_to_queue();
      break;

   case 2 :
       //Ta bort nod ur k�n
       remove_from_queue();
       break;

   case 3 :
       //S�k och ta bort
       delete_from_queue();
       break;

   case 4 :
       //Skriv ut hela k�n
       print_queue();
       break;

   case 5 :
       printf("Du valde att avsluta\n\n");
       exit(0); //avbryt programmet om anv�ndaren v�ljer 4
       break;
   }
}
//end run_selection

//function get_selection
int get_selection()
{
   int valt_tal;

do {
    scanf("%d", &valt_tal); //l�s in menyvalet
    if (valt_tal < 1 || valt_tal >5) {
    printf("Fel, talet skall vara mellan 1 och 5! \n\n"); //kolla om talet �r mellan 1 & 4
    show_menu(); //om inte - visa menyn igen tills anv�ndare v�ljer "r�tt"
    }
}while(valt_tal < 1 || valt_tal >5);
return valt_tal; //skicka tillbaks det anv�ndaren valt
}
//end get_selection

// function pause
int pause()
{
    int c;
    printf("\n\nTryck enter f�r att forts�tta!");
    //T�mmer inmatningsstr�mmen
    while((c=getchar()) != '\n' && c !=EOF);
    getchar();
    return 1;
}
//end pause
