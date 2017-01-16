//Inlämningsuppgift 4
//Henrik Axelsson, 750328-4999

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct
{
    char firstName [20];
    char surName [20];
    char persNbr [20];
}person_type; //end typedef för en person-struct.

typedef person_type *person_type_ref; //typedef för en pekare till typen person_type

//Function enqueue, tar indata en variabel av typen person_type
void enqueue (person_type person);

//Function dequeue, tar en pekare till ett personelement som argument, raderar
//elementet på positionen head och skriver data till pekaren/argumentet
void dequeue(person_type_ref person);

//Function get_person, hämtar personuppgifter på en position i kön och
//kopierar dessa till personbvariebeln
void get_person(person_type_ref person, int position);

//Function get_number_of_pers, returnerar värdet på nbr_element
int get_number_of_pers();

//Function is_empty, kollar om kön är tom och returnerar 1 om tom, annars 0
int is_empty();

//Function is_full, returnerar 1 om kön är full, annars 0
int is_full();

//Skriv ut en person
void print_name(person_type_ref person);

//Slut på deklarationer

#endif // QUEUE_H_INCLUDED
