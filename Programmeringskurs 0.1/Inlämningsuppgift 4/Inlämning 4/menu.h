//Inlämningsuppgift 4
//Henrik Axelsson, 750328-4999

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//Visa menyn
void show_menu();

//Läs in användarens val
int get_selection ();

//Exekvera användarens val
void run_selection(int selection);

//Pause, vänta på input
int pause();

#endif // MENU_H_INCLUDED
