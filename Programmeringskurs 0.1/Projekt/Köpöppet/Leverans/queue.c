//Inl�mningsuppgift 5
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

//Function enqueue f�r att l�gga till ett element i k�n
int Enqueue(int iTime, queue_c * aQueueRefArray, int iQueueNumber)
{
    node *new_node;
    node *last_node;

    new_node = CreateNode(iTime);                       //Skapa en ny nod med funktionen create_node
    if (new_node == 0) {
        printf("Finns inget minne att l�gga till denna nod!\n");
        return 0;                                       //Avbryt h�r, det gick inte att l�gga till noden, inte tillr�ckligt med minne.
    }

    last_node = aQueueRefArray[iQueueNumber].last;      //pekare till f�reg�ende nod i k�n

    if (aQueueRefArray[iQueueNumber].first == NULL) {   //om f�rsta pekaren==NULL s� �r k�n tom, det finns inget att peka p�
        aQueueRefArray[iQueueNumber].first=new_node;    //s�tt b�de f�rsta och sista elementet till den nyk�ade noden
        aQueueRefArray[iQueueNumber].last=new_node;     //den �r ju b�de f�rst och sist eftersom k�n var tom innan.
    }
    else {
        last_node->next=new_node;                       //pekaren i f�reg�ende nod s�tts att peka p� den nyk�ade noden
        aQueueRefArray[iQueueNumber].last=new_node;     //�ven queref skall peka p� sista noden, den nyk�ade.
    }
    return 1;
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//CREATE NODE
//************************************

//Skapar en ny nod i k�n, l�gger in data och s�tter next-pekaren till 0
//(Detta �r ju ett nyskapat element, allts� sist i k�n)
static node *CreateNode(int iTime)
{
    node *noderef = (node *) malloc(sizeof(node));         //Allokera minne och f� en pekare
    noderef->iRemainingQueueTime = iTime;                  //Stoppa in tiden
    noderef->next = NULL;                                  //S�tt next-pekaren till NULL (sist i k�n)
    return noderef;                                        //Returnera pekaren till den nyskapade noden.
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//DEQUEUE
//************************************

//Dequeue tar bort en nod ur k�n och
int Dequeue(queue_c * aQueueRefArray, int iQueueNumber)
{
    node *first_node;
    if (aQueueRefArray[iQueueNumber].first == NULL) {           //K�n �r tom
        printf("Dequeue: k�n �r tom.\n\n");
        return 0;                                               //returnera 0 om k�n �r tom
    }

    first_node = aQueueRefArray[iQueueNumber].first;            //peka p� f�rsta noden i k�n
    aQueueRefArray[iQueueNumber].first = first_node->next;      //s�tt aQueueRefArray[iQueueNumber].first att peka p� n�sta nod, som skall bli f�rst
    DestroyNode(first_node);                                    //Ta sedan bort den nod som first_node pekar p�.
    if (aQueueRefArray[iQueueNumber].first == NULL) {           //Det fanns bara en nod i k�n, och den togs bort nu
        aQueueRefArray[iQueueNumber].last=NULL;                 //s�tter last till NULL ocks�, nu �r b�de first och last NULL, dvs. k�n �r tom.
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
    free(node_ref);     //"frig�r" minnet
    node_ref=NULL;      //Nolla pekaren node_ref
}
//-----------------------------------------------------------------------------------------------------------------------



//************************************
//PRINT QUEUE
//************************************

//Denna hj�lpfunktion skriver ut nuvarande k�situation
//med antal kunder och k�tid f�r varje k�.
void PrintQueue(queue_c * aQueueRefArray, int iNumberOfCashiers, int iTimeFromSimulationStart)
{
    int node_counter;                                       //Anv�nds f�r att r�kna ut antal kunder
    int iQueueTime;                                         //Anv�nds f�r att summera k�tiden
    node *curr_ptr;                                         //Pekare till den kund/nod som bearbetas

    printf("K�situationen efter %d minuter:\n", iTimeFromSimulationStart);

    int i;
    for (i=0; i<iNumberOfCashiers; i++) {                     //Loopa igenom alla kassorna
        curr_ptr = aQueueRefArray[i].first;                 //titta p� f�rsta elementet i varje kassa
        iQueueTime = 0;                                     //Nollst�ll f�r varje kassa
        node_counter = 0;

        printf("\nKASSA %d\n", (i+1));

        if (curr_ptr == NULL) {                             //Kassan/k�n �r tom
            printf("Antal Kunder:%7s%-d\n", "", node_counter);
            printf("Total k�tid:%8s%-d\n","", iQueueTime);
        }
        else {                                              //K�n �r inte tom
            while (curr_ptr != NULL) {                      //Loopa igenom alla noder/kunder
                node_counter++;
                iQueueTime += curr_ptr->iRemainingQueueTime;//r�kna upp k�tiden med denna kunds tid
                curr_ptr = curr_ptr->next;                  //Forts�tt med n�sta
                }
            printf("Antal Kunder:%7s%-d\n","", node_counter);
            printf("Total k�tid:%8s%-d min %d sek\n","", (iQueueTime/60), (iQueueTime%60));
            }
        }
    }
//-----------------------------------------------------------------------------------------------------------------------


