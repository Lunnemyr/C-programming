//Inlämningsuppgift 5
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

//Skapa och intitiera pekarstrukten som pekar på första och sista elementen i kön
//Vid uppstart av programmet är kön tom, alltså sätts elementen till NULL.
static queue_c queueref = {.first=NULL, .last=NULL};


/* Funktionsprototyper */
static int destroy_node(node *node_ref);
static node *create_node(int data);

//Implementation av add_to_queue
void add_to_queue()
{
    int heltal;
    int resultat;

    printf("\n\nLägg till en nod i kön.\n");
    printf("\nVilket heltalsvärde vill du lägga in i noden?: ");
    scanf("%d", &heltal);

    resultat=enqueue(heltal);

    if (resultat) {
        printf("Noden är tillagd.\n");
    }
    else {
        printf("Det gick inte att lägga till noden!\n");
    }
}//end add_to_queue


//Implementation av remove_from_queue
void remove_from_queue()
{
    printf("\n\nTa bort en nod ur kön.\n");
    int resultat;
    int heltal;

    resultat = dequeue(&heltal); //ta bort första noden i kön
    //Kolla först om kön är tom
    if (resultat == 0) {
        printf("\nKön är tom, det finns ingen nod att ta bort.\n");
    }
    else {
        printf("Den borttagna nodens data är: %d\n", heltal);
    }
}

void delete_from_queue()
{
    int heltal;
    int resultat;

    printf("\n\nSkriv in data som du vill söka efter och ta bort nod med: \n");
    scanf("%d", &heltal);

    resultat=delete(heltal);

       if (resultat==1) {
            printf("Data hittades, noden togs bort\n");
       }

       else if (resultat == 2) {
            printf("Kön är tom!\n");
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
    prev_ptr=queueref.first; //sätt till första noden, här börjar vi sökningen

    if (prev_ptr == NULL) {  //Kön är tom
        return 2; //Avbryt om kön är tom
    }

    if (prev_ptr->data == data) { //kolla om första elementet har sökt data
        queueref.first=prev_ptr->next; //sätt isåfall queueref.first att peka på nästa element
        destroy_node(prev_ptr); //Ta sedan bort den nod som first_node pekar på. Data returneras, men ignoreras

        if (queueref.first == NULL) {  //Kolla om kön är tom nu
            printf("Sista noden i kön togs bort!\n");
            queueref.last=NULL; //sätter last till NULL också, nu är både first och last NULL, dvs. kön är tom.
        }
        return 1; //noden hittades och togs bort, avbryt här.
    }

    //Inte första noden i kön, kör loopad sökning

    curr_ptr=prev_ptr->next; //pekare till andra noden (som hämtas från next i första).

    while (curr_ptr!=NULL) {
        if (curr_ptr->data == data) {
            //Hittades, ta bort noden
            temp_ptr=curr_ptr;
            prev_ptr->next=curr_ptr->next; //peka föregående nod till nästa nod, hoppa förbi current.
            destroy_node(temp_ptr); //ta bort noden, frigör minne, sätt pekare till NULL.
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

//Function enqueue för att lägga till ett element i kön
int enqueue(int data)
{
    node *new_node, *last_node;
    int result = 0;
    new_node = create_node(data); //Skapa en ny nod med funktionen create_node
    if (new_node == 0) {
        printf("Finns inget minne att lägga till denna nod!\n");
        return 0; //Avbryt här, det gick inte att lägga till noden, inte tillräckligt med minne.
    }

    //pekare till föregående nod i kön
    last_node=queueref.last;

    if (queueref.first==NULL) {  //om första pekaren==NULL så är kön tom, det finns inget att peka på

        queueref.first=new_node; //sätt både första och sista elementet till den nyköade noden
        queueref.last=new_node;  //den är ju både först och sist eftersom kön var tom innan.
    }
    else {
        last_node->next=new_node; //pekaren i föregående nod sätts att peka på den nyköade noden
        queueref.last=new_node;   //Även queref skall peka på sista noden, den nyköade.
    }
    return 1;
}

//Skapar en ny nod i kön, lägger in data och sätter next-pekaren till 0
//(Detta är ju ett nyskapat element, alltså sist i kön)
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
    if (queueref.first == NULL) { //Kön är tom?
        return 0;
    }
    first_node = queueref.first; //peka på första noden i kön
    queueref.first = first_node->next;  //sätt queueref.first att peka på nästa nod, som skall bli först
    *data = destroy_node(first_node); //Ta sedan bort den nod som first_node pekar på. Data returneras.
    if (queueref.first == NULL) {  //Det fanns bara en nod i kön, och den togs bort nu
        queueref.last=NULL; //sätter last till NULL också, nu är både first och last NULL, dvs. kön är tom.
    }
    return 1;
}


static int destroy_node(node *node_ref)
{
    int data;
    data=node_ref->data;  //Kopiera data till utparametern
    free(node_ref);     //"frigör" minnet
    node_ref=NULL;      //Nolla pekaren node_ref
    return data;
}


void print_queue()
{
    int node_counter = 1;
    printf(("\nSkriv ut kön.\n\n"));
    node *curr_ptr = queueref.first;
    if (queueref.first == NULL) {
        printf("Kön är tom, inget att skriva ut\n");
    }
    while (curr_ptr != NULL) {
        printf("Data i nod nummer %d är:%d\n", node_counter, curr_ptr->data);
        curr_ptr=curr_ptr->next;
        node_counter++;

    }
}


