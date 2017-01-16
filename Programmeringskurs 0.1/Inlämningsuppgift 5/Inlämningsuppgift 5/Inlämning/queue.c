//Inl�mningsuppgift 5
//Henrik Axelsson, 750328-4999

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    struct node *first;
    struct node *last;
} queue_c;

//Skapa och intitiera pekarstrukten som pekar p� f�rsta och sista elementen i k�n
//Vid uppstart av programmet �r k�n tom, allts� s�tts elementen till NULL.
static queue_c queueref = {.first=NULL, .last=NULL};


/* Funktionsprototyper */
static int destroy_node(node *node_ref);
static node *create_node(int data);

//Implementation av add_to_queue
void add_to_queue()
{
    int heltal;
    int resultat;

    printf("\n\nL�gg till en nod i k�n.\n");
    printf("\nVilket heltalsv�rde vill du l�gga in i noden?: ");
    scanf("%d", &heltal);

    resultat=enqueue(heltal);

    if (resultat) {
        printf("Noden �r tillagd.\n");
    }
    else {
        printf("Det gick inte att l�gga till noden!\n");
    }
}//end add_to_queue


//Implementation av remove_from_queue
void remove_from_queue()
{
    printf("\n\nTa bort en nod ur k�n.\n");
    int resultat;
    int heltal;

    resultat = dequeue(&heltal); //ta bort f�rsta noden i k�n
    //Kolla f�rst om k�n �r tom
    if (resultat == 0) {
        printf("\nK�n �r tom, det finns ingen nod att ta bort.\n");
    }
    else {
        printf("Den borttagna nodens data �r: %d\n", heltal);
    }
}

void delete_from_queue()
{
    int heltal;
    int resultat;

    printf("\n\nSkriv in data som du vill s�ka efter och ta bort nod med: \n");
    scanf("%d", &heltal);

    resultat=delete(heltal);

       if (resultat==1) {
            printf("Data hittades, noden togs bort\n");
       }

       else if (resultat == 2) {
            printf("K�n �r tom!\n");
       }
       else{
            printf("Noden hittades inte!\n");
       }
}  //end delete_from_queue


int delete(int data)
{
    int result = 0;
    node *curr_ptr;
    node *prev_ptr;
    node *temp_ptr;
    prev_ptr=queueref.first; //s�tt till f�rsta noden, h�r b�rjar vi s�kningen

    if (prev_ptr == NULL) {  //K�n �r tom
        return 2; //Avbryt om k�n �r tom
    }

    if (prev_ptr->data == data) { //kolla om f�rsta elementet har s�kt data
        queueref.first=prev_ptr->next; //s�tt is�fall queueref.first att peka p� n�sta element
        destroy_node(prev_ptr); //Ta sedan bort den nod som first_node pekar p�. Data returneras, men ignoreras

        if (queueref.first == NULL) {  //Kolla om k�n �r tom nu
            printf("Sista noden i k�n togs bort!\n");
            queueref.last=NULL; //s�tter last till NULL ocks�, nu �r b�de first och last NULL, dvs. k�n �r tom.
        }
        return 1; //noden hittades och togs bort, avbryt h�r.
    }

    //Inte f�rsta noden i k�n, k�r loopad s�kning

    curr_ptr=prev_ptr->next; //pekare till andra noden (som h�mtas fr�n next i f�rsta).

    while (curr_ptr!=NULL) {
        if (curr_ptr->data == data) {
            //Hittades, ta bort noden
            temp_ptr=curr_ptr;
            prev_ptr->next=curr_ptr->next; //peka f�reg�ende nod till n�sta nod, hoppa f�rbi current.
            destroy_node(temp_ptr); //ta bort noden, frig�r minne, s�tt pekare till NULL.
            return 1; //eftersom det gick bra!
        }
        else {
            //HIttades inte, flytta fram pekarna ett steg vardera mha. temp_ptr.
            temp_ptr=curr_ptr->next;
            prev_ptr=curr_ptr;
            curr_ptr=temp_ptr;
        }
    }
    return result;
}

//Function enqueue f�r att l�gga till ett element i k�n
int enqueue(int data)
{
    node *new_node, *last_node;
    int result = 0;
    new_node = create_node(data); //Skapa en ny nod med funktionen create_node
    if (new_node == 0) {
        printf("Finns inget minne att l�gga till denna nod!\n");
        return 0; //Avbryt h�r, det gick inte att l�gga till noden, inte tillr�ckligt med minne.
    }

    //pekare till f�reg�ende nod i k�n
    last_node=queueref.last;

    if (queueref.first==NULL) {  //om f�rsta pekaren==NULL s� �r k�n tom, det finns inget att peka p�

        queueref.first=new_node; //s�tt b�de f�rsta och sista elementet till den nyk�ade noden
        queueref.last=new_node;  //den �r ju b�de f�rst och sist eftersom k�n var tom innan.
    }
    else {
        last_node->next=new_node; //pekaren i f�reg�ende nod s�tts att peka p� den nyk�ade noden
        queueref.last=new_node;   //�ven queref skall peka p� sista noden, den nyk�ade.
    }
    return 1;
}

//Skapar en ny nod i k�n, l�gger in data och s�tter next-pekaren till 0
//(Detta �r ju ett nyskapat element, allts� sist i k�n)
static node *create_node(int data)
{
    node *noderef = (node *) malloc(sizeof(node));
    noderef->data=data;
    noderef->next=NULL;
    return noderef;
}


int dequeue(int *data)
{
    node *first_node;
    if (queueref.first == NULL) { //K�n �r tom?
        return 0;
    }
    first_node = queueref.first; //peka p� f�rsta noden i k�n
    queueref.first = first_node->next;  //s�tt queueref.first att peka p� n�sta nod, som skall bli f�rst
    *data = destroy_node(first_node); //Ta sedan bort den nod som first_node pekar p�. Data returneras.
    if (queueref.first == NULL) {  //Det fanns bara en nod i k�n, och den togs bort nu
        queueref.last=NULL; //s�tter last till NULL ocks�, nu �r b�de first och last NULL, dvs. k�n �r tom.
    }
    return 1;
}


static int destroy_node(node *node_ref)
{
    int data;
    data=node_ref->data;  //Kopiera data till utparametern
    free(node_ref);     //"frig�r" minnet
    node_ref=NULL;      //Nolla pekaren node_ref
    return data;
}


void print_queue()
{
    int node_counter = 1;
    printf(("\nSkriv ut k�n.\n\n"));
    node *curr_ptr = queueref.first;
    if (queueref.first == NULL) {
        printf("K�n �r tom, inget att skriva ut\n");
    }
    while (curr_ptr != NULL) {
        printf("Data i nod nummer %d �r:%d\n", node_counter, curr_ptr->data);
        curr_ptr=curr_ptr->next;
        node_counter++;

    }
}


