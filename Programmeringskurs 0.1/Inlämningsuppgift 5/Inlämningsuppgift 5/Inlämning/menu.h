//Inl�mningsuppgift 5
//Henrik Axelsson, 750328-4999

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//Visa menyn
void show_menu();

//L�s in anv�ndarens val
int get_selection ();

//Exekvera anv�ndarens val
void run_selection(int selection);

//Pause, v�nta p� input
int pause();

#endif // MENU_H_INCLUDED
