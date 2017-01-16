//Projektuppgift Köpöppet
//Henrik Axelsson, 750328-4999

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


//Lägger definitionerna här så att simulatorn kan skapa sina datastrukturer med dem.
typedef struct node {
    int iRemainingQueueTime;
    struct node *next;
} node;

typedef struct {
    struct node *first;
    struct node *last;
} queue_c;

int Enqueue(int iTime, queue_c * aQueueRefArray, int iQueueNumber);      //Lägg till nod i kön
int Dequeue(queue_c * aQueueRefArray, int iQueueNumber);                 //Ta bort en nod ur kön
void PrintQueue(queue_c * aQueueRefArray, int iNumberOfCashiers, int iTimeFromSimulationStart); //Skriv ut kön


#endif // QUEUE_H_INCLUDED
