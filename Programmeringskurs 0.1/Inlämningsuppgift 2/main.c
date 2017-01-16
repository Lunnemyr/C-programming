//Inlämningsuppgift 2
//Henrik Axelsson, 750328-4999


//Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//end includes


//Funktionsprototyper
void show_menu();
void run_selection(int selection);
void gissa_tal();
void kasta_tarning();
void fibonacci(); //jag har gjort 2 versioner av fibonacci för tränings skull
void fibonacci_2();
unsigned int recursive_fibonacci(int n); //rekursiv version av själva fibonacciuträkningen
int get_selection ();
int pause();
//end Funktionsprototyper


//Huvudprogram enligt inlämningsuppgift
int main()
{
    do{
    show_menu();
    run_selection(get_selection());
    } while(pause());
   return 0;
}
//end main


//FUNKTIONSKROPPAR

//function show_menu
void show_menu()
{
    printf("\n\n*****  MENY  *****\n\n");
    printf("   1. Gissa tal\n");
    printf("   2. Kasta tärning\n");
    printf("   3. Fibonacci\n");
    printf("   4. Avsluta\n\n");
    printf("Ange ett alternativ 1-4:");
}
//END show menu


//function run_selection
void run_selection(int selection)
{
   switch(selection){ //för att starta "rätt" menyval enligt användarens inmatning

   case 1 :
      printf("Du valde Gissa Tal\n\n");
      gissa_tal();
      break;

   case 2 :
       printf("Du valde Kasta Tärning\n\n");
       kasta_tarning();
       break;

   case 3 :
       printf("Du valde Fibonacci\n\n");
       fibonacci_2(); //Startar fibonacci (här är det den rekursiva varianten)
       break;

   case 4 :
       printf("Du valde att avsluta\n\n");
       exit(0); //avbryt programmet om användaren väljer 4
       break;
   }
}
//end run_selection


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


//function kasta_tarning
void kasta_tarning()
{
    printf("Ange hur många gånger tärningen skall kastas: ");
    int tarningssida;               //vilken sida på tärningen som kommer upp
    int antal_kast;                 //antal gånger tärningen skall kastas
    int kast_nr;                    //nummer för det aktuella kastet

    int antal_ettor = 0; //Dessa variabler är för att räkna antalet träffar
    int antal_tvaor = 0; //på respektive tärningssida
    int antal_treor = 0;
    int antal_fyror = 0;
    int antal_femmor = 0;
    int antal_sexor= 0;

    scanf("%d", &antal_kast);       //be användare mata in hur många kast som skall göras
    srand(time(0));                 //frö till rand

    // Kasta antal_kast gånger
    for(kast_nr=1; kast_nr<=antal_kast; ++kast_nr) {

    tarningssida = (rand()%6)+1;    //kasta tärningen

    switch (tarningssida) {         //kolla vilken sida som kom upp,
        case 1 :                    //och räkna upp antalet på respektive sida
            antal_ettor++;
            break;

        case 2 :
            antal_tvaor++;
            break;

        case 3 :
            antal_treor++;
            break;

        case 4 :
            antal_fyror++;
            break;

        case 5 :
            antal_femmor++;
            break;

        case 6 :
            antal_sexor++;
            break;
        } //end switch..case
    } //end for-loop

    //Skriv ut resultatet i numerärer
    printf("\n\nResultatet av %d kast:\n", antal_kast);//skriv ut resultatet i kolumner
    printf("Ettor:%8s%-d\n","", antal_ettor); //gör först en kolumn för att sedan
    printf("Tvåor:%8s%-d\n", "", antal_tvaor);//vänsterjuster i andra kolumnen
    printf("Treor:%8s%-d\n", "",antal_treor);
    printf("Fyror:%8s%-d\n", "", antal_fyror);
    printf("Femmor:%7s%-d\n", "", antal_femmor);
    printf("Sexor:%8s%-d\n\n", "", antal_sexor);

    //Skriv ut resultatet i frekvens i procent.
    printf("\nFrekvens i procent:\n");
    printf("Ettor:%8s%-.1f%%\n", "", (double) antal_ettor/antal_kast*100);
    printf("Tvåor:%8s%-.1f%%\n", "", (double) antal_tvaor/antal_kast*100);
    printf("Treor:%8s%-.1f%%\n", "", (double) antal_treor/antal_kast*100);
    printf("Fyror:%8s%-.1f%%\n", "", (double) antal_fyror/antal_kast*100);
    printf("Femmor:%7s%-.1f%%\n", "", (double) antal_femmor/antal_kast*100);
    printf("Sexor:%8s%-.1f%%\n", "", (double) antal_sexor/antal_kast*100);
}
//end kasta tarning


//function fibonacci_2()
void fibonacci_2()
{
    int n = 0;
    unsigned int fib = 0; //använder detta tal som mellanlagring
    unsigned int maxtal;
    printf("Skriv in ett maxtal för Fibonacciserien\n");
    scanf("%u", &maxtal);
    printf("Fibonacciserien är: ");

    while (fib <= maxtal){
        fib = recursive_fibonacci(n);
        if (fib <= maxtal) {         //kollar att fib unte är för stort, istället för att
            printf("%u ", fib);      //anropa rekursiva funktionen två gånger (vilket
            n++;                     //förbrukar minne och resurser i onödan). Val är "billiga"
        }//end if                    //kunde ha skrivit enklare:
        else {                       //while (recursive_fibonacci (n) <= max_tal), edan skriva ut.
            break;
        }//end else
    }//end while
}
//end function fibonacci_2()

//function recursive_fibonacci
unsigned int recursive_fibonacci(int n) //denna funktion beräknar fibonacci-talet för ett tal n
{
    if (n == 0 || n == 1){ //basfallet för den rekursiva beräkningen, att n = 0 eller n = 1
        return n;
    }
    else {
        return recursive_fibonacci(n-1) + recursive_fibonacci(n-2); //rekursivt anrop
    }//end else
}//end recursive fibonacci function


//function fibonacci
void fibonacci()
{
    unsigned int max_nr;
    unsigned int fibonacci_nr = 0;
    unsigned int prev_fibonnaci_nr =0;

    printf("Välkommen till talserien Fibonacci\n");
    printf("\n\nAnge det största tal som skall skrivas ut i serien:\n");

    scanf("%u", &max_nr);      //läs in talet
    printf("\nFibonacciserien: ");

    while(fibonacci_nr + prev_fibonnaci_nr <= max_nr) { //Kolla att max_nr inte överskrids

         if (max_nr == 0) { //Om max_nr är == 0 skall bara nollan skrivas ut
            printf("%u", fibonacci_nr);
            break; // avbryt while-loopen om max_tal är 0
         }//end if

         if (fibonacci_nr==0) { //specialfallet i början av serien
            printf(" %u", fibonacci_nr);  //skriv ut 0-an
            fibonacci_nr=1; //sätt till 1
            printf(" %u", fibonacci_nr); //skriv ut 1-an
        }//end if

        else {
            unsigned int new_fib_nr; //använder new_fib_nr för "mellanlagring"
            new_fib_nr = fibonacci_nr + prev_fibonnaci_nr; // räkna ihop talen som blir nästa fib tal.
            prev_fibonnaci_nr = fibonacci_nr; //uppdatera föregående med nuvarande
            fibonacci_nr = new_fib_nr;  //sätt nuvarande fib till det som mellanlagrades, nya
            printf(" %u", fibonacci_nr); //skriv ut
        } //end else
    }
}
//end fibonacci


//function gissa_tal()
void gissa_tal()
{
    int rand_nbr;                   //talet genererat av systemet
    int guess;                      //heltal, användarens gissning
    int counter = 0;                //Räknare för antalet gissningar
    srand(time(0));                 //frö till rand
    rand_nbr = (rand()%100)+1;      //generera ett slumptal mellan 1-100

    //starta loop för att läsa in användarens gissningar
    do{

    printf("\n\nGissa ett tal:\n");
    scanf("%d", &guess);      //läs in gissningen
    counter++;

        if (guess < rand_nbr) {     //Jämför gissningen med systemets tal
            printf("för lågt! \n\n");
        }
        else if (guess > rand_nbr) {
            printf("för högt!\n\n");
        }

    }while(rand_nbr!= guess); //så länge som talet skiljer sig => fortsätt gissa
    //vid rätt gissning => loopen avslutas.

    printf("Du gissade rätt, talet var: %d\n", guess);
    printf("Du behövde %d försök för att gissa rätt: \n\n\n", counter);
}
//end gissa_tal
