//Inlämningsuppgift 5
//Henrik Axelsson, 750328-4999


#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
//Huvudprogram enligt inlämningsuppgift 4


int main()
{
    do{
    show_menu();
    run_selection(get_selection());
    } while(pause());
   return 0;
} //end main
