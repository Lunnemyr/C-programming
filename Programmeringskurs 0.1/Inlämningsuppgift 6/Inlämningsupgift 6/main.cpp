//Inlämningsuppgift 6
//Henrik Axelsson, 750328-4999

#include <iostream>
#include "menu.h"


using namespace std;

int main()
{
    menu the_menu;  //Skapa ett menyobjekt som kan köra igång menyn

    do{
        the_menu.show_menu();
        the_menu.run_selection(the_menu.get_selection());
    } while(the_menu.pause());

    return 0;
}
