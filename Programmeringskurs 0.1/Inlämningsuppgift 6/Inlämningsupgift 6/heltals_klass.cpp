//Inl�mningsuppgift 6
//Henrik Axelsson, 750328-4999

#include "heltals_klass.h"
#include <iostream>

using namespace std;

heltals_klass::heltals_klass()
{
    //cout << "Heltalsklass defaultconstructor!" << endl;
}

heltals_klass::heltals_klass(int tal)
{
    //cout << "Heltalsklass icke - defaultconstructor!" << endl;
    heltal = tal;
    //cout << "Heltalet som lagrades: " << heltal << endl;
}
heltals_klass::~heltals_klass()
{
    //cout << "Heltalsklass DESTRUCTOR!" << endl;
}

int heltals_klass::operator+(heltals_klass &obj3)
{
    //cout << "Addition." << endl;
    return (this->get_heltal() + obj3.get_heltal());
}

bool heltals_klass::operator<(heltals_klass &obj2)
{
    //cout << "J�mf�relse. f�rsta objektet har talet " << get_heltal() << " , andra objektet har talet " << obj2.get_heltal() << "." << endl;
    if (get_heltal() < obj2.get_heltal()) {  //testar om heltalet i objekt 1 �r mindre �n i objekt 2
        return true;                                            //objekt av klassen heltals_klass
    }
    else {
        return false;
    }
}

bool heltals_klass::operator>(heltals_klass &obj1)
{
    if (get_heltal() > obj1.get_heltal()) {  //testar om heltalet i objekt 1 �r mindre �n i objekt 2
        return true;                                            //objekt av klassen heltals_klass
    }
    else {
        return false;
    }
}
