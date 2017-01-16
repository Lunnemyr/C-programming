//Projektuppgift K�p�ppet
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
int iTimeToPay = 20;                    //Tid att utf�ra betalningen
//int aNewCustomerSelectionArray [4]= {0, 1, 2, 3};
int iTimeFromSimulationStart = 0;
//int iNumberOfQueues = 8;              //default = 8
int iTimeToRunSimulation = 0;           //Tid som anv�ndaren vill k�ra tidssimuleringen
int iTimeToRunMultipleSimulation = 0;   //Tid f�r multipla k�rningar

//Variabler f�r inmatningen till simuleringen
int isSavingsPackage = 0;
int isRationalStore = 0;
int isCreditCardStore = 0;
int isDoubleNoCustomers = 0;
int isStepSimulation = 1;
int iNumberOfCashiers = 5;  //default == 5
int iPauseTime = 0;
int isMultipleRunSimulation = 0;      //F�r att kunna k�ra simuleringen med samma indata om och m igen.

//Skapa K�-array och tidsarray
queue_c aQueueRefArray[MAXCASHIERS];  //Skapa k�erna/kassorna. Array med element som har pekare till f�rsta och sista elementet f�r resp k�.
int aQueueTimeArray [MAXCASHIERS];    //Skapa en tids-array med total tid kvar till tom k� f�r respektive k�.
                                      //f�r att enkelt hitta tillg�nglig k�


//************************************
//MAIN
//************************************
int main()
{
    do{

        InitializeSimulation();           //Initiera och l�s in anv�ndarens val
        Pause(1, 0, 0);

        do{
            RunSimulation();
        } while(Pause(isStepSimulation, iTimeToRunSimulation, iPauseTime));

        printf("\nSimuleringen avslutades.\n");
        GetSelection(&isMultipleRunSimulation, "Vill du k�ra simuleringen igen med samma data (0 = nej, 1 = ja)?: ", 0,1);

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
    //Vid uppstart av programmet �r k�erna tomma, allts� s�tts elementen till NULL.
    //Initialisera k�-arrayen
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
        printf("V�LKOMMEN TILL K�P�PPET av Henrik Axelsson.\n\nDetta program simulerar k�situationen i ett antal kassor enligt \nprojektbeskrivningen f�r kurs DA105A.\n\n");
        printf("Programmet startar med att anv�ndaren ombeds mata in ett antal \nparamentrar f�r simuleringen.\n\n\n");

        //Antal kassor?
        GetSelection(&iNumberOfCashiers, "ANTAL KASSOR\nV�lj antal kassor i denna simulering (mellan 1 och 10): ", 1, 10);
        printf("Antal kassor = %d\n\n", iNumberOfCashiers);

        //Ekonomisk �tstramning?
        GetSelection(&isSavingsPackage, "�TSTRAMNINGSPAKET\nV�lj om det skall vara ekonomiskt �tstramningspaket(0 = nej, 1 = ja): ", 0,1);

        if(isSavingsPackage){
            iMaxNbrOfMerchandise = 20;
            printf("Ekonomiskt �tstramningspaket, max antal varor = %d\n\n", iMaxNbrOfMerchandise);
        }
        else{
            printf("Ej ekonomiskt �tstramningspaket, max antal varor = %d\n\n", iMaxNbrOfMerchandise);
        }

        //rationalisering av kassorna?
        GetSelection(&isRationalStore, "RATIONELLA KASSOR\nV�lj om det skall vara rationalisering av kassorna (0 = nej, 1 = ja): ", 0,1);
        if(isRationalStore){
            iMerchandiseProcessingTime = 5;
            printf("Rationalisering i kassorna, behandlingstid per vara = %d\n\n", iMerchandiseProcessingTime);
        }
        else{
            printf("Ej rationalisering i kassorna, behandlingstid per vara = %d\n\n", iMerchandiseProcessingTime);
        }

        //Penningl�st varuhus?
        GetSelection(&isCreditCardStore, "PENNINGL�ST VARUHUS\nV�lj om det skall vara penningl�st varuhus (0 = nej, 1 = ja): ", 0,1);
        if(isCreditCardStore){
            iTimeToPay = 45;
            printf("Penningl�st varuhus, behandlingstid per betalning = %d\n\n", iTimeToPay);
        }
        else{
            printf("Ej penningl�st varuhus, behandlingstid per betalning = %d\n\n", iTimeToPay);
        }

        //Dubbel kundtillstr�mning?
        GetSelection(&isDoubleNoCustomers, "DUBBEL KUNDTILLSTR�MNINGSHASTIGHET\nV�lj om det skall vara dubbel kundtillstr�mningshastighet (0 = nej, 1 = ja): ", 0,1);
        if(isDoubleNoCustomers){
            printf("Dubbel kundtillstr�mningshastighet.\n\n");
        }
        else{
            printf("Normal kundtillstr�mningshastighet.\n\n");
        }
        //Stega fram simuleringen, eller k�r ett antal minuter.
        GetSelection(&isStepSimulation, "SIMULERA STEG F�R STEG\nV�lj om simuleringen skall stega fram ett steg i taget (0 = nej, 1 = ja): ", 0,1);
        if(isStepSimulation){
            printf("Simuleringen k�rs steg f�r steg.\nT�nk p� att du f�r trycka enter f�r att stega fram.\n\n");
        }
        else{
            GetSelection(&iTimeToRunMultipleSimulation, "V�lj tid som simuleringen skall k�ras: ", 1, MAXSIMULATIONTIME);
            GetSelection(&iPauseTime,"V�lj paustid mellan de automatiska tidsstegen (0 till max 5 sekunder): ", 0, 5 );
            printf("Simuleringen k�rs i %d minuter.\n\n", iTimeToRunMultipleSimulation);
        }
    }
    iTimeToRunSimulation = iTimeToRunMultipleSimulation;        //Se till att r�tt tid anv�nds vid multipla simuleringar
}
//-----------------------------------------------------------------------------------------------------------------------





//************************************
//RUN SIMULATION
//************************************

//Denna funktion k�r en k�rning i simuleringen inuti do-while loopen i main.
void RunSimulation()
{
        NewCustomerRoutine();                               //Skapa nya kunder och l�gg in i k�erna
        iTimeFromSimulationStart++;                         //Nu r�knas tiden upp.
        HandleCustomersRoutine();                           //Hantera kunderna, behandla varor, ta betalat, checka ut
        CalculateQueueTimes();                              //Ber�kna nya k�tider (som anv�nds i NewCustomerRoutine)
        system("cls");                                      //Rensa sk�rmen f�r snygg utskrift

        PrintQueue(aQueueRefArray, iNumberOfCashiers, iTimeFromSimulationStart);     //Skriv ut k�situationen

        iTimeToRunSimulation--;                             //R�kna ner kvarvarande tid p� simuleringen
                                                            //Ingen effekt om det �r en steppad simulering.
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//NEW CUSTOMER ROUTINE
//************************************

//Dra ut ett antal kunder som skall l�ggas till slumpm�ssigt med sannolikhetsf�rdelningen
//Det blir antingen 0, 1, 2, eller 3 kunder fr�n IntervallRandNumber.
//Dubblera om det �r dubbel kundtillstr�mning
void NewCustomerRoutine()
{
    int iNbrOfCustomersToAdd = 0;
    int iNextQueue = 0;                                     //N�sta k� att l�gga till i
    int iNbrOfMerchandise = 0;                              //Antal varor f�r en kund

    if (isDoubleNoCustomers) {                              //Dubblera om double no of customers
        iNbrOfCustomersToAdd = 2*IntervallRandNumber();
    }
    else {
        iNbrOfCustomersToAdd = IntervallRandNumber();
    }

                                                            //L�gg till en kund i taget i den kortaste
    while (iNbrOfCustomersToAdd > 0) {                      //k�n tills alla kunder har hittat en k�

        iNextQueue = FindShortestQueue();                   //Leta upp den k� som har l�gst l�ngd p� k�n
        iNbrOfMerchandise = RandomInRange(1, iMaxNbrOfMerchandise); //Dra slumptals mellan 1..max antal varor
        AddCustomerToQueue(iNextQueue, iNbrOfMerchandise);  //l�gg till kunden i den k�n med detta antal varor
        CalculateQueueTimes();                              //ber�kna nya k�tider f�r n�sta s�kning av kortaste k�n
        iNbrOfCustomersToAdd--;                             //Kunden klar, r�kna ner antalet kvarvarande kunder
    }
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//HANDLE CUSTOMERS ROUTINE
//************************************

//Loopar igenom k�erna och r�knar av tider samt tar bort kunder
//(checkar ut dem) och behandlar n�sta. Anv�nder de 60 sekunderna till fullo.
void HandleCustomersRoutine()
{
    int i;
    int iHandleTime;                                                //Tid kvar f�r att behandla kunder i denna k�rning
    node * curr_ptr;                                                //Pekare till nuvarande kund/nod

    for (i=0; i<iNumberOfCashiers; i++) {
        iHandleTime = 60;                                           //60 sekunder per kassa
        curr_ptr = aQueueRefArray[i].first;

        while ((iHandleTime > 0) && (curr_ptr != NULL)){            //S� l�nge det finns "behandlingstid" kvar och k�n inte �r tom.
                                                                    //Tom k� ignoreras och n�sta k� behandlas ist�llet.
            if (curr_ptr->iRemainingQueueTime <= iHandleTime) {     //Om det finns mer tid kvar att behandla kunder med �n vad som �r i noden .
                iHandleTime -= curr_ptr->iRemainingQueueTime;       //Dra av tiden fr�n noden p� "behandlingstiden"
                Dequeue(aQueueRefArray, i);                         //Ta bort noden/kunden
                curr_ptr = aQueueRefArray[i].first;                 //first pekar nu p� det som "var" n�sta nod, eller p� NULL om tom k�
            }
            else {
                curr_ptr->iRemainingQueueTime -= iHandleTime;       //Dra d� bort tiden fr�n noden som f�r en mindre
                iHandleTime = 0;                                    //tid kvar tills den �r f�rdigbehandlad. Hanteringetiden �r nu slut.
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//CALC QUEUE TIMES
//************************************

//Ber�knar alla k�tider och sparar i en array, aQueueTimeArray
void CalculateQueueTimes()
{
    int i;
    node * curr_ptr;


    for (i=0; i<iNumberOfCashiers; i++) {
        curr_ptr = aQueueRefArray[i].first;
        int iResult = 0;

        if (curr_ptr == NULL) {                             //K�n �r tom, returnera tiden = 0.
            iResult = 0;
        }

        while (curr_ptr != NULL) {
            iResult += curr_ptr->iRemainingQueueTime;       //L�gg till tiden som �r kvar p� kunden
            curr_ptr=curr_ptr->next;
        }
        aQueueTimeArray[i] = iResult;
    }
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//FIND SHORTEST QUEUE
//************************************

//Denna funktion letar upp den kortaste (och f�rsta i tids-arrayen) k�n
//och returnerar index till den k�n.
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

//Denna funktion l�gger till en kund i k�n genom att ber�kna k�tiden f�r
//denna kund (beror av antalet varor och tid f�r betalning)
//Kollar om det gick att l�gga till kunden, skriver annars ut ett felmeddelande.
void AddCustomerToQueue(int iNextQueue, int iNbrOfMerchandise)
{
    int iResultat;
    int iTime = (iTimeToPay + iNbrOfMerchandise*iMerchandiseProcessingTime);      //tiden att betala + antal varor*tid att behandla varje vara
    iResultat = Enqueue(iTime, aQueueRefArray, iNextQueue);

    if (!iResultat) {
        printf("Det gick inte att l�gga till noden, minnet slut!\n");
    }
}
//-----------------------------------------------------------------------------------------------------------------------
