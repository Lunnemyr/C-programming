//Inlämningsuppgift 5
//Henrik Axelsson, 750328-4999

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

//header enligt kod-skalet från inlämningsuppgiften
int enqueue(int data);
int dequeue(int *data);
void add_to_queue();
void remove_from_queue();
void delete_from_queue();

void print_queue();
int delete(int data);

void show_menu();
int get_selection();
void run_selection(int selection);
int pause();

#endif // QUEUE_H_INCLUDED
