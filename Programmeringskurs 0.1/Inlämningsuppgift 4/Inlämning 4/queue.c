//Inlämningsuppgift 4
//Henrik Axelsson, 750328-4999

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#define QUEUE_MAX_SIZE 10

static person_type queue[QUEUE_MAX_SIZE];
static int head = 0, tail = 0, nbr_elem = 0;


//Function enqueue, tar indata en variabel av typen person_type
void enqueue (person_type person)
{
    //Kopiera över personens uppgifter till kön
    strcpy(queue[tail].firstName, person.firstName);
    strcpy(queue[tail].surName, person.surName);
    strcpy(queue[tail].persNbr, person.persNbr);

    nbr_elem++; //öka antalet fyllda element i kön
    tail = (tail + 1) % QUEUE_MAX_SIZE; //använder modulus för att få cirkulärt.
    //OBS att jag låter tail peka på nästa tomma element redan i detta läge.

    printf("Personen är tillagd\n\n");
}

//Function dequeue, tar en pekare till ett personelement som argument, raderar
//elementet på positionen head och skriver data till pekaren/argumentet
void dequeue(person_type_ref person)
{
    //Kopiera över personens data till personvariebeln från kön
    strcpy(person->firstName, queue[head].firstName);
    strcpy(person->surName, queue[head].surName);
    strcpy(person->persNbr, queue[head].persNbr);

    //Mnska antalet element samt ändra parametern head
    //om head +1 är = max storlek => det börjar om på 0
    nbr_elem--;
    head = (head + 1) % QUEUE_MAX_SIZE;
}

//Function get_person, hämtar personuppgifter på en position i kön och
//kopierar dessa till personbvariebeln
void get_person(person_type_ref person, int position)
{
    //Kolla först så att man inte kommer utanför arrayen
    //Dra bort QUEUE_MAX_SIZE om så är fallet för att hamna inom rätt
    //område.
    if ((head + position) >= QUEUE_MAX_SIZE) {
        position = (head + position - QUEUE_MAX_SIZE); //Sätt ny position
    } // end if
    else {
        position = (head + position);
    } //end else

    //Kopiera över personens data till personvariebeln för begärd position
    strcpy(person->firstName, queue[position].firstName);
    strcpy(person->surName, queue[position].surName);
    strcpy(person->persNbr, queue[position].persNbr);
} //end get_person

//Function get_number_of_pers, returnerar värdet på nbr_element
int get_number_of_pers()
{
    return nbr_elem;
} // end get_number

//Function is_empty, kollar om kön är tom och returnerar 1 om tom, annars 0
int is_empty()
{
    return (nbr_elem == 0); //((abs(tail-head))+1) == 0);
} //end is_empty

//Function is_full, returnerar 1 om kön är full, annars 0
int is_full()
{
    return (nbr_elem >= QUEUE_MAX_SIZE);
} //end is_full

//Hjälpfunktion för att skriva ut respektive person.
void print_name(person_type_ref person)
{
    printf("%s %s\n%s\n", person->firstName, person->surName, person->persNbr);
} //end print_name
