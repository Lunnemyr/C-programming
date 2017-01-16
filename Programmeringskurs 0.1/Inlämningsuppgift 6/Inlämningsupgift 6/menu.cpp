#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

menu::menu()
{
    //ctor
}

menu::~menu()
{
    //dtor
}

//function show_menu
void menu::show_menu()
{
    printf("\n\n*****  MENY  *****\n\n");
    printf("   1. \n");
    printf("\n   2. \n");
    printf("\n   3. \n");
    printf("\n   4. \n");
    printf("\n   5. Avsluta\n\n");
    printf("Ange ett alternativ 1-5: ");
}
//END show menu


//function run_selection
void menu::run_selection(int selection)
{
   printf("\n\n");
   switch(selection){ //för att starta "rätt" menyval enligt användarens inmatning

   case 1 :

      run_menyval_1();
      break;

   case 2 :

       run_menyval_2();
       break;

   case 3 :

       run_menyval_3();
       break;

   case 4 :

       run_menyval_4();
       break;

   case 5 :
       printf("Avsluta\n\n");
       exit(0); //avbryt programmet om användaren väljer 5
       break;
   }
}
//end run_selection

void menu::run_menyval_1()
{
    cout << "Du valde meny 1 ";
}

void menu::run_menyval_2()
{
   cout << "Du valde meny 2 ";

}

void menu::run_menyval_3()
{
   cout << "Du valde meny 3 ";
}

void menu::run_menyval_4()
{

    cout << "Du valde meny 4 ";

}

//Hjälpfunktioner


//function get_selection
int menu::get_selection()
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
int menu::pause()
{
    int c;
    printf("\n\nTryck enter för att fortsätta!");
    //Tömmer inmatningsströmmen
    while((c=getchar()) != '\n' && c !=EOF);
    getchar();
    return 1;
}
//end pause

