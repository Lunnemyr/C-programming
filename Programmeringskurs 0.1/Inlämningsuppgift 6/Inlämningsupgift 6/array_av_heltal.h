//Inl�mningsuppgift 6
//Henrik Axelsson, 750328-4999

#ifndef ARRAY_AV_HELTAL_H
#define ARRAY_AV_HELTAL_H
#include "heltals_klass.h"
#define DEFAULT_SIZE 20  //f�r defaultkonstruktor

class array_av_heltal
{
    public:
        array_av_heltal(int = DEFAULT_SIZE);              //Defaultkonstruktor
        virtual ~array_av_heltal();     //Destruktor
        void array_print();                  //Metod som skriver ut inneh�llet i en array
        void array_rnd_create(int max_tal, int min_tal); //Metod som fyller arrayen med slumpm�ssiga nummer mellan tv� angivna tal, max oxh min
        void sortera_array(); //publik metod f�r att sortera arrayen, beh�ver ej veta storlek

    private:
        int size;
        heltals_klass * heltals_array_pekare;
        void array_quick_sort(int first, int last);
        int random_in_range (int min, int max);          //Hj�lpfunktion f�r att f� ett random nummer "in range".
};

#endif // ARRAY_AV_HELTAL_H
