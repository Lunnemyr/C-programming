//Projektuppgift Köpöppet
//Henrik Axelsson, 750328-4999

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulator_helper_functions.h"
#include "queue.h"

//DEFINES
#define MAXCASHIERS 10
#define MAXSIMULATIONTIME 480

//PROTOTYPER
void InitializeSimulation();
void RunSimulation();
void CalculateQueueTimes();
void NewCustomerRoutine();
void HandleCustomersRoutine();
int FindShortestQueue();
void AddCustomerToQueue(int iNextQueue, int iNbrOfMerchandise);
void PrintQueueTimes();

//DEKLARATIONER
int iMaxNbrOfMerchandise = 50;          //Max antal varor, default
int iMerchandiseProcessingTime = 8;     //Tid att processa EN vara
int iTimeToPay = 20;                    //Tid att utföra betalningen
//int aNewCustomerSelectionArray [4]= {0, 1, 2, 3};
int iTimeFromSimulationStart = 0;
//int iNumberOfQueues = 8;              //default = 8
int iTimeToRunSimulation = 0;           //Tid som användaren vill köra tidssimuleringen
int iTimeToRunMultipleSimulation = 0;   //Tid för multipla körningar

//Variabler för inmatningen till simuleringen
int isSavingsPackage = 0;
int isRationalStore = 0;
int isCreditCardStore = 0;
int isDoubleNoCustomers = 0;
int isStepSimulation = 1;
int iNumberOfCashiers = 5;  //default == 5
int iPauseTime = 0;
int isMultipleRunSimulation = 0;      //För att kunna köra simuleringen med samma indata om och m igen.

//Skapa Kö-array och tidsarray
queue_c aQueueRefArray[MAXCASHIERS];  //Skapa köerna/kassorna. Array med element som har pekare till första och sista elementet för resp kö.
int aQueueTimeArray [MAXCASHIERS];    //Skapa en tids-array med total tid kvar till tom kö för respektive kö.
                                      //för att enkelt hitta tillgänglig kö


//************************************
//MAIN
//************************************
int main()
{
    do{

        InitializeSimulation();           //Initiera och läs in användarens val
        Pause(1, 0, 0);

        do{
            RunSimulation();
        } while(Pause(isStepSimulation, iTimeToRunSimulation, iPauseTime));

        printf("\nSimuleringen avslutades.\n");
        GetSelection(&isMultipleRunSimulation, "Vill du köra simuleringen igen med samma data (0 = nej, 1 = ja)?: ", 0,1);

    } while (Pause(1, 0, 0));

    return 0;

} //END MAIN
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------


//FUNKTIONSDEKLARATIONER

//************************************
//INITIALIZE SIMULATION
//************************************
void InitializeSimulation()
{
    iTimeFromSimulationStart = 0;
    //Vid uppstart av programmet är köerna tomma, alltså sätts elementen till NULL.
    //Initialisera kö-arrayen
    int i;
    for (i=0; i<iNumberOfCashiers; i++) {
        aQueueRefArray[i].first = NULL;
        aQueueRefArray[i].last = NULL;
    }

    // Initialisera tids-arrayen
    for (i=0; i<iNumberOfCashiers; i++) {
        aQueueTimeArray[i] = 0;
    }

    //Rensa konsollen
    system("cls");

    if (!isMultipleRunSimulation) {
        //Start utskrifter
        printf("VÄLKOMMEN TILL KÖPÖPPET av Henrik Axelsson.\n\nDetta program simulerar kösituationen i ett antal kassor enligt \nprojektbeskrivningen för kurs DA105A.\n\n");
        printf("Programmet startar med att användaren ombeds mata in ett antal \nparamentrar för simuleringen.\n\n\n");

        //Antal kassor?
        GetSelection(&iNumberOfCashiers, "ANTAL KASSOR\nVälj antal kassor i denna simulering (mellan 1 och 10): ", 1, 10);
        printf("Antal kassor = %d\n\n", iNumberOfCashiers);

        //Ekonomisk åtstramning?
        GetSelection(&isSavingsPackage, "ÅTSTRAMNINGSPAKET\nVälj om det skall vara ekonomiskt åtstramningspaket(0 = nej, 1 = ja): ", 0,1);

        if(isSavingsPackage){
            iMaxNbrOfMerchandise = 20;
            printf("Ekonomiskt åtstramningspaket, max antal varor = %d\n\n", iMaxNbrOfMerchandise);
        }
        else{
            printf("Ej ekonomiskt åtstramningspaket, max antal varor = %d\n\n", iMaxNbrOfMerchandise);
        }

        //rationalisering av kassorna?
        GetSelection(&isRationalStore, "RATIONELLA KASSOR\nVälj om det skall vara rationalisering av kassorna (0 = nej, 1 = ja): ", 0,1);
        if(isRationalStore){
            iMerchandiseProcessingTime = 5;
            printf("Rationalisering i kassorna, behandlingstid per vara = %d\n\n", iMerchandiseProcessingTime);
        }
        else{
            printf("Ej rationalisering i kassorna, behandlingstid per vara = %d\n\n", iMerchandiseProcessingTime);
        }

        //Penninglöst varuhus?
        GetSelection(&isCreditCardStore, "PENNINGLÖST VARUHUS\nVälj om det skall vara penninglöst varuhus (0 = nej, 1 = ja): ", 0,1);
        if(isCreditCardStore){
            iTimeToPay = 45;
            printf("Penninglöst varuhus, behandlingstid per betalning = %d\n\n", iTimeToPay);
        }
        else{
            printf("Ej penninglöst varuhus, behandlingstid per betalning = %d\n\n", iTimeToPay);
        }

        //Dubbel kundtillströmning?
        GetSelection(&isDoubleNoCustomers, "DUBBEL KUNDTILLSTRÖMNINGSHASTIGHET\nVälj om det skall vara dubbel kundtillströmningshastighet (0 = nej, 1 = ja): ", 0,1);
        if(isDoubleNoCustomers){
            printf("Dubbel kundtillströmningshastighet.\n\n");
        }
        else{
            printf("Normal kundtillströmningshastighet.\n\n");
        }
        //Stega fram simuleringen, eller kör ett antal minuter.
        GetSelection(&isStepSimulation, "SIMULERA STEG FÖR STEG\nVälj om simuleringen skall stega fram ett steg i taget (0 = nej, 1 = ja): ", 0,1);
        if(isStepSimulation){
            printf("Simuleringen körs steg för steg.\nTänk på att du får trycka enter för att stega fram.\n\n");
        }
        else{
            GetSelection(&iTimeToRunMultipleSimulation, "Välj tid som simuleringen skall köras: ", 1, MAXSIMULATIONTIME);
            GetSelection(&iPauseTime,"Välj paustid mellan de automatiska tidsstegen (0 till max 5 sekunder): ", 0, 5 );
            printf("Simuleringen körs i %d minuter.\n\n", iTimeToRunMultipleSimulation);
        }
    }
    iTimeToRunSimulation = iTimeToRunMultipleSimulation;        //Se till att rätt tid används vid multipla simuleringar
}
//-----------------------------------------------------------------------------------------------------------------------





//************************************
//RUN SIMULATION
//************************************

//Denna funktion kör en körning i simuleringen inuti do-while loopen i main.
void RunSimulation()
{
        NewCustomerRoutine();                               //Skapa nya kunder och lägg in i köerna
        iTimeFromSimulationStart++;                         //Nu räknas tiden upp.
        HandleCustomersRoutine();                           //Hantera kunderna, behandla varor, ta betalat, checka ut
        CalculateQueueTimes();                              //Beräkna nya kötider (som används i NewCustomerRoutine)
        system("cls");                                      //Rensa skärmen för snygg utskrift

        PrintQueue(aQueueRefArray, iNumberOfCashiers, iTimeFromSimulationStart);     //Skriv ut kösituationen

        iTimeToRunSimulation--;                             //Räkna ner kvarvarande tid på simuleringen
                                                            //Ingen effekt om det är en steppad simulering.
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//NEW CUSTOMER ROUTINE
//************************************

//Dra ut ett antal kunder som skall läggas till slumpmässigt med sannolikhetsfördelningen
//Det blir antingen 0, 1, 2, eller 3 kunder från IntervallRandNumber.
//Dubblera om det är dubbel kundtillströmning
void NewCustomerRoutine()
{
    int iNbrOfCustomersToAdd = 0;
    int iNextQueue = 0;                                     //Nästa kö att lägga till i
    int iNbrOfMerchandise = 0;                              //Antal varor för en kund

    if (isDoubleNoCustomers) {                              //Dubblera om double no of customers
        iNbrOfCustomersToAdd = 2*IntervallRandNumber();
    }
    else {
        iNbrOfCustomersToAdd = IntervallRandNumber();
    }

                                                            //Lägg till en kund i taget i den kortaste
    while (iNbrOfCustomersToAdd > 0) {                      //kön tills alla kunder har hittat en kö

        iNextQueue = FindShortestQueue();                   //Leta upp den kö som har lägst längd på kön
        iNbrOfMerchandise = RandomInRange(1, iMaxNbrOfMerchandise); //Dra slumptals mellan 1..max antal varor
        AddCustomerToQueue(iNextQueue, iNbrOfMerchandise);  //lägg till kunden i den kön med detta antal varor
        CalculateQueueTimes();                              //beräkna nya kötider för nästa sökning av kortaste kön
        iNbrOfCustomersToAdd--;                             //Kunden klar, räkna ner antalet kvarvarande kunder
    }
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//HANDLE CUSTOMERS ROUTINE
//************************************

//Loopar igenom köerna och räknar av tider samt tar bort kunder
//(checkar ut dem) och behandlar nästa. Använder de 60 sekunderna till fullo.
void HandleCustomersRoutine()
{
    int i;
    int iHandleTime;                                                //Tid kvar för att behandla kunder i denna körning
    node * curr_ptr;                                                //Pekare till nuvarande kund/nod

    for (i=0; i<iNumberOfCashiers; i++) {
        iHandleTime = 60;                                           //60 sekunder per kassa
        curr_ptr = aQueueRefArray[i].first;

        while ((iHandleTime > 0) && (curr_ptr != NULL)){            //Så länge det finns "behandlingstid" kvar och kön inte är tom.
                                                                    //Tom kö ignoreras och nästa kö behandlas istället.
            if (curr_ptr->iRemainingQueueTime <= iHandleTime) {     //Om det finns mer tid kvar att behandla kunder med än vad som är i noden .
                iHandleTime -= curr_ptr->iRemainingQueueTime;       //Dra av tiden från noden på "behandlingstiden"
                Dequeue(aQueueRefArray, i);                         //Ta bort noden/kunden
                curr_ptr = aQueueRefArray[i].first;                 //first pekar nu på det som "var" nästa nod, eller på NULL om tom kö
            }
            else {
                curr_ptr->iRemainingQueueTime -= iHandleTime;       //Dra då bort tiden från noden som får en mindre
                iHandleTime = 0;                                    //tid kvar tills den är färdigbehandlad. Hanteringetiden är nu slut.
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//CALC QUEUE TIMES
//************************************

//Beräknar alla kötider och sparar i en array, aQueueTimeArray
void CalculateQueueTimes()
{
    int i;
    node * curr_ptr;


    for (i=0; i<iNumberOfCashiers; i++) {
        curr_ptr = aQueueRefArray[i].first;
        int iResult = 0;

        if (curr_ptr == NULL) {                             //Kön är tom, returnera tiden = 0.
            iResult = 0;
        }

        while (curr_ptr != NULL) {
            iResult += curr_ptr->iRemainingQueueTime;       //Lägg till tiden som är kvar på kunden
            curr_ptr=curr_ptr->next;
        }
        aQueueTimeArray[i] = iResult;
    }
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//FIND SHORTEST QUEUE
//************************************

//Denna funktion letar upp den kortaste (och första i tids-arrayen) kön
//och returnerar index till den kön.
int FindShortestQueue()
{
    int iLowestTime = aQueueTimeArray[0];
    int iQueueNumber = 0;

    int i;

    for (i=1; i<iNumberOfCashiers; i++) {
        if (aQueueTimeArray[i] < iLowestTime) {
            iQueueNumber = i;
            iLowestTime = aQueueTimeArray[i];
        }
    }
    return iQueueNumber;
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//ADD CUSTOMERS TO QUEUE
//************************************

//Denna funktion lägger till en kund i kön genom att beräkna kötiden för
//denna kund (beror av antalet varor och tid för betalning)
//Kollar om det gick att lägga till kunden, skriver annars ut ett felmeddelande.
void AddCustomerToQueue(int iNextQueue, int iNbrOfMerchandise)
{
    int iResultat;
    int iTime = (iTimeToPay + iNbrOfMerchandise*iMerchandiseProcessingTime);      //tiden att betala + antal varor*tid att behandla varje vara
    iResultat = Enqueue(iTime, aQueueRefArray, iNextQueue);

    if (!iResultat) {
        printf("Det gick inte att lägga till noden, minnet slut!\n");
    }
}
//-----------------------------------------------------------------------------------------------------------------------
