//Inlämningsuppgift 5
//Henrik Axelsson, 750328-4999

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

//PROTOTYPER
static void DestroyNode(node *node_ref);
static node *CreateNode(int iTime);


//************************************
//ENQUEUE
//************************************

//Function enqueue för att lägga till ett element i kön
int Enqueue(int iTime, queue_c * aQueueRefArray, int iQueueNumber)
{
    node *new_node;
    node *last_node;

    new_node = CreateNode(iTime);                       //Skapa en ny nod med funktionen create_node
    if (new_node == 0) {
        printf("Finns inget minne att lägga till denna nod!\n");
        return 0;                                       //Avbryt här, det gick inte att lägga till noden, inte tillräckligt med minne.
    }

    last_node = aQueueRefArray[iQueueNumber].last;      //pekare till föregående nod i kön

    if (aQueueRefArray[iQueueNumber].first == NULL) {   //om första pekaren==NULL så är kön tom, det finns inget att peka på
        aQueueRefArray[iQueueNumber].first=new_node;    //sätt både första och sista elementet till den nyköade noden
        aQueueRefArray[iQueueNumber].last=new_node;     //den är ju både först och sist eftersom kön var tom innan.
    }
    else {
        last_node->next=new_node;                       //pekaren i föregående nod sätts att peka på den nyköade noden
        aQueueRefArray[iQueueNumber].last=new_node;     //Även queref skall peka på sista noden, den nyköade.
    }
    return 1;
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//CREATE NODE
//************************************

//Skapar en ny nod i kön, lägger in data och sätter next-pekaren till 0
//(Detta är ju ett nyskapat element, alltså sist i kön)
static node *CreateNode(int iTime)
{
    node *noderef = (node *) malloc(sizeof(node));         //Allokera minne och få en pekare
    noderef->iRemainingQueueTime = iTime;                  //Stoppa in tiden
    noderef->next = NULL;                                  //Sätt next-pekaren till NULL (sist i kön)
    return noderef;                                        //Returnera pekaren till den nyskapade noden.
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//DEQUEUE
//************************************

//Dequeue tar bort en nod ur kön och
int Dequeue(queue_c * aQueueRefArray, int iQueueNumber)
{
    node *first_node;
    if (aQueueRefArray[iQueueNumber].first == NULL) {           //Kön är tom
        printf("Dequeue: kön är tom.\n\n");
        return 0;                                               //returnera 0 om kön är tom
    }

    first_node = aQueueRefArray[iQueueNumber].first;            //peka på första noden i kön
    aQueueRefArray[iQueueNumber].first = first_node->next;      //sätt aQueueRefArray[iQueueNumber].first att peka på nästa nod, som skall bli först
    DestroyNode(first_node);                                    //Ta sedan bort den nod som first_node pekar på.
    if (aQueueRefArray[iQueueNumber].first == NULL) {           //Det fanns bara en nod i kön, och den togs bort nu
        aQueueRefArray[iQueueNumber].last=NULL;                 //sätter last till NULL också, nu är både first och last NULL, dvs. kön är tom.
    }
    return 1;
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//DESTROY NODE
//************************************

//Destroy node tar bort noden och nollar pekaren till noden.
static void DestroyNode(node *node_ref)
{
    free(node_ref);     //"frigör" minnet
    node_ref=NULL;      //Nolla pekaren node_ref
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//PRINT QUEUE
//************************************

//Denna hjälpfunktion skriver ut nuvarande kösituation
//med antal kunder och kötid för varje kö.
void PrintQueue(queue_c * aQueueRefArray, int iNumberOfCashiers, int iTimeFromSimulationStart)
{
    int node_counter;                                       //Används för att räkna ut antal kunder
    int iQueueTime;                                         //Används för att summera kötiden
    node *curr_ptr;                                         //Pekare till den kund/nod som bearbetas

    printf("Kösituationen efter %d minuter:\n", iTimeFromSimulationStart);

    int i;
    for (i=0; i<iNumberOfCashiers; i++) {                     //Loopa igenom alla kassorna
        curr_ptr = aQueueRefArray[i].first;                 //titta på första elementet i varje kassa
        iQueueTime = 0;                                     //Nollställ för varje kassa
        node_counter = 0;

        printf("\nKASSA %d\n", (i+1));

        if (curr_ptr == NULL) {                             //Kassan/kön är tom
            printf("Antal Kunder:%7s%-d\n", "", node_counter);
            printf("Total kötid:%8s%-d\n","", iQueueTime);
        }
        else {                                              //Kön är inte tom
            while (curr_ptr != NULL) {                      //Loopa igenom alla noder/kunder
                node_counter++;
                iQueueTime += curr_ptr->iRemainingQueueTime;//räkna upp kötiden med denna kunds tid
                curr_ptr = curr_ptr->next;                  //Fortsätt med nästa
                }
            printf("Antal Kunder:%7s%-d\n","", node_counter);
            printf("Total kötid:%8s%-d min %d sek\n","", (iQueueTime/60), (iQueueTime%60));
            }
        }
    }
//-----------------------------------------------------------------------------------------------------------------------


