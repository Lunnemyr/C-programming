//Inlämningsuppgift 6
//Henrik Axelsson, 750328-4999

#ifndef ARRAY_AV_HELTAL_H
#define ARRAY_AV_HELTAL_H
#include "heltals_klass.h"
#define DEFAULT_SIZE 20  //för defaultkonstruktor

class array_av_heltal
{
    public:
        array_av_heltal(int = DEFAULT_SIZE);              //Defaultkonstruktor
        virtual ~array_av_heltal();     //Destruktor
        void array_print();                  //Metod som skriver ut innehållet i en array
        void array_rnd_create(int max_tal, int min_tal); //Metod som fyller arrayen med slumpmässiga nummer mellan två angivna tal, max oxh min
        void sortera_array(); //publik metod för att sortera arrayen, behöver ej veta storlek

    private:
        int size;
        heltals_klass * heltals_array_pekare;
        void array_quick_sort(int first, int last);
        int random_in_range (int min, int max);          //Hjälpfunktion för att få ett random nummer "in range".
};

#endif // ARRAY_AV_HELTAL_H
