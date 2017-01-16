//Inlämningsuppgift 6
//Henrik Axelsson, 750328-4999

#include "test_program.h"
#include "menu.h"
#include <iostream>
#include "heltals_klass.h"

using namespace std;

test_program::test_program()
{
    //ctor
}

test_program::~test_program()
{
    //dtor
}

void test_program::run()
{
    menu the_menu;  //Skapa ett menyobjekt som kan köra igång menyn

    do{
        the_menu.show_menu();
        the_menu.run_selection(the_menu.get_selection());
    } while(the_menu.pause());

}

int ett_tal;
    int ett_tal_till;

    cout << "Testprogram för heltalsklass, skriv in ett tal:";
    cin >> ett_tal;
    cout << endl;
    heltals_klass *heltals_objekt;
    heltals_objekt = new heltals_klass(ett_tal);

    cout << "Skriv in ett andra tal:";
    cin >> ett_tal_till;
    cout << endl;
    heltals_klass *heltals_objekt2;
    heltals_objekt2 = new heltals_klass(ett_tal_till);

    cout << "Jämförelse av objektens tal. Första talet är "<< heltals_objekt->get_heltal()
    << " och andra objektets tal är " << heltals_objekt2->get_heltal() << "." << endl << endl;

    cout << "Talens sammanlagda värde är: " << (*heltals_objekt + *heltals_objekt2) << endl;
    if (*heltals_objekt < *heltals_objekt2) {
        cout << "Första talet är mindre än andra talet." << endl;
    }
    else if (*heltals_objekt > *heltals_objekt2){
        cout << "Första talet är större än andra talet" << endl << endl;
    }
    else {
        cout << "Första talet är lika med andra talet." << endl;
    }

    cout << "Testprogram: tar bort objekten dynamiskt" << endl;

    delete heltals_objekt;
    delete heltals_objekt2;
