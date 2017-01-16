//Inl�mningsuppgift 2
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
void fibonacci(); //jag har gjort 2 versioner av fibonacci f�r tr�nings skull
void fibonacci_2();
unsigned int recursive_fibonacci(int n); //rekursiv version av sj�lva fibonacciutr�kningen
int get_selection ();
int pause();
//end Funktionsprototyper


//Huvudprogram enligt inl�mningsuppgift
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
    printf("   2. Kasta t�rning\n");
    printf("   3. Fibonacci\n");
    printf("   4. Avsluta\n\n");
    printf("Ange ett alternativ 1-4:");
}
//END show menu


//function run_selection
void run_selection(int selection)
{
   switch(selection){ //f�r att starta "r�tt" menyval enligt anv�ndarens inmatning

   case 1 :
      printf("Du valde Gissa Tal\n\n");
      gissa_tal();
      break;

   case 2 :
       printf("Du valde Kasta T�rning\n\n");
       kasta_tarning();
       break;

   case 3 :
       printf("Du valde Fibonacci\n\n");
       fibonacci_2(); //Startar fibonacci (h�r �r det den rekursiva varianten)
       break;

   case 4 :
       printf("Du valde att avsluta\n\n");
       exit(0); //avbryt programmet om anv�ndaren v�ljer 4
       break;
   }
}
//end run_selection


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


//function get_selection
int get_selection()
{
   int valt_tal;

do {
    scanf("%d", &valt_tal); //l�s in menyvalet
    if (valt_tal < 1 || valt_tal >4) {
    printf("Fel, talet skall vara mellan 1 och 4! \n\n"); //kolla om talet �r mellan 1 & 4
    show_menu(); //om inte - visa menyn igen tills anv�ndare v�ljer "r�tt"
    }
}while(valt_tal < 1 || valt_tal >4);
return valt_tal; //skicka tillbaks det anv�ndaren valt
}
//end get_selection


//function kasta_tarning
void kasta_tarning()
{
    printf("Ange hur m�nga g�nger t�rningen skall kastas: ");
    int tarningssida;               //vilken sida p� t�rningen som kommer upp
    int antal_kast;                 //antal g�nger t�rningen skall kastas
    int kast_nr;                    //nummer f�r det aktuella kastet

    int antal_ettor = 0; //Dessa variabler �r f�r att r�kna antalet tr�ffar
    int antal_tvaor = 0; //p� respektive t�rningssida
    int antal_treor = 0;
    int antal_fyror = 0;
    int antal_femmor = 0;
    int antal_sexor= 0;

    scanf("%d", &antal_kast);       //be anv�ndare mata in hur m�nga kast som skall g�ras
    srand(time(0));                 //fr� till rand

    // Kasta antal_kast g�nger
    for(kast_nr=1; kast_nr<=antal_kast; ++kast_nr) {

    tarningssida = (rand()%6)+1;    //kasta t�rningen

    switch (tarningssida) {         //kolla vilken sida som kom upp,
        case 1 :                    //och r�kna upp antalet p� respektive sida
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

    //Skriv ut resultatet i numer�rer
    printf("\n\nResultatet av %d kast:\n", antal_kast);//skriv ut resultatet i kolumner
    printf("Ettor:%8s%-d\n","", antal_ettor); //g�r f�rst en kolumn f�r att sedan
    printf("Tv�or:%8s%-d\n", "", antal_tvaor);//v�nsterjuster i andra kolumnen
    printf("Treor:%8s%-d\n", "",antal_treor);
    printf("Fyror:%8s%-d\n", "", antal_fyror);
    printf("Femmor:%7s%-d\n", "", antal_femmor);
    printf("Sexor:%8s%-d\n\n", "", antal_sexor);

    //Skriv ut resultatet i frekvens i procent.
    printf("\nFrekvens i procent:\n");
    printf("Ettor:%8s%-.1f%%\n", "", (double) antal_ettor/antal_kast*100);
    printf("Tv�or:%8s%-.1f%%\n", "", (double) antal_tvaor/antal_kast*100);
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
    unsigned int fib = 0; //anv�nder detta tal som mellanlagring
    unsigned int maxtal;
    printf("Skriv in ett maxtal f�r Fibonacciserien\n");
    scanf("%u", &maxtal);
    printf("Fibonacciserien �r: ");

    while (fib <= maxtal){
        fib = recursive_fibonacci(n);
        if (fib <= maxtal) {         //kollar att fib unte �r f�r stort, ist�llet f�r att
            printf("%u ", fib);      //anropa rekursiva funktionen tv� g�nger (vilket
            n++;                     //f�rbrukar minne och resurser i on�dan). Val �r "billiga"
        }//end if                    //kunde ha skrivit enklare:
        else {                       //while (recursive_fibonacci (n) <= max_tal), edan skriva ut.
            break;
        }//end else
    }//end while
}
//end function fibonacci_2()

//function recursive_fibonacci
unsigned int recursive_fibonacci(int n) //denna funktion ber�knar fibonacci-talet f�r ett tal n
{
    if (n == 0 || n == 1){ //basfallet f�r den rekursiva ber�kningen, att n = 0 eller n = 1
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

    printf("V�lkommen till talserien Fibonacci\n");
    printf("\n\nAnge det st�rsta tal som skall skrivas ut i serien:\n");

    scanf("%u", &max_nr);      //l�s in talet
    printf("\nFibonacciserien: ");

    while(fibonacci_nr + prev_fibonnaci_nr <= max_nr) { //Kolla att max_nr inte �verskrids

         if (max_nr == 0) { //Om max_nr �r == 0 skall bara nollan skrivas ut
            printf("%u", fibonacci_nr);
            break; // avbryt while-loopen om max_tal �r 0
         }//end if

         if (fibonacci_nr==0) { //specialfallet i b�rjan av serien
            printf(" %u", fibonacci_nr);  //skriv ut 0-an
            fibonacci_nr=1; //s�tt till 1
            printf(" %u", fibonacci_nr); //skriv ut 1-an
        }//end if

        else {
            unsigned int new_fib_nr; //anv�nder new_fib_nr f�r "mellanlagring"
            new_fib_nr = fibonacci_nr + prev_fibonnaci_nr; // r�kna ihop talen som blir n�sta fib tal.
            prev_fibonnaci_nr = fibonacci_nr; //uppdatera f�reg�ende med nuvarande
            fibonacci_nr = new_fib_nr;  //s�tt nuvarande fib till det som mellanlagrades, nya
            printf(" %u", fibonacci_nr); //skriv ut
        } //end else
    }
}
//end fibonacci


//function gissa_tal()
void gissa_tal()
{
    int rand_nbr;                   //talet genererat av systemet
    int guess;                      //heltal, anv�ndarens gissning
    int counter = 0;                //R�knare f�r antalet gissningar
    srand(time(0));                 //fr� till rand
    rand_nbr = (rand()%100)+1;      //generera ett slumptal mellan 1-100

    //starta loop f�r att l�sa in anv�ndarens gissningar
    do{

    printf("\n\nGissa ett tal:\n");
    scanf("%d", &guess);      //l�s in gissningen
    counter++;

        if (guess < rand_nbr) {     //J�mf�r gissningen med systemets tal
            printf("f�r l�gt! \n\n");
        }
        else if (guess > rand_nbr) {
            printf("f�r h�gt!\n\n");
        }

    }while(rand_nbr!= guess); //s� l�nge som talet skiljer sig => forts�tt gissa
    //vid r�tt gissning => loopen avslutas.

    printf("Du gissade r�tt, talet var: %d\n", guess);
    printf("Du beh�vde %d f�rs�k f�r att gissa r�tt: \n\n\n", counter);
}
//end gissa_tal
