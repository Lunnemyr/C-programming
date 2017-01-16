//Projektuppgift K�p�ppet
//Henrik Axelsson, 750328-4999

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


//L�gger definitionerna h�r s� att simulatorn kan skapa sina datastrukturer med dem.
typedef struct node {
    int iRemainingQueueTime;
    struct node *next;
} node;

typedef struct {
    struct node *first;
    struct node *last;
} queue_c;

int Enqueue(int iTime, queue_c * aQueueRefArray, int iQueueNumber);      //L�gg till nod i k�n
int Dequeue(queue_c * aQueueRefArray, int iQueueNumber);                 //Ta bort en nod ur k�n
void PrintQueue(queue_c * aQueueRefArray, int iNumberOfCashiers, int iTimeFromSimulationStart); //Skriv ut k�n


#endif // QUEUE_H_INCLUDED
