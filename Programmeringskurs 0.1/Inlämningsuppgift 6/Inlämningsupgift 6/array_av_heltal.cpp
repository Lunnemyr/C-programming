//Inlämningsuppgift 6
//Henrik Axelsson, 750328-4999

#include "array_av_heltal.h"
#include "heltals_klass.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

array_av_heltal::array_av_heltal(int storlek)      //Konstruktor
{
        //cout << "array_av_heltal med storlek (konstruktor)!" << storlek << endl;
        size = storlek;
        //cout << "Storlek på arrayen enligt size: " << size << endl;
        heltals_array_pekare = new heltals_klass [size];  //Skapa dynamiskt antal
        for (int i = 0; i < size; i++) {
            heltals_array_pekare[i].set_heltal(0);
        }
}

array_av_heltal::~array_av_heltal()
{
    //cout << "Array deconstructor!" << endl;
    delete [] heltals_array_pekare;
}


//Fyller arrayen med slumpmässiga nummer.
void array_av_heltal::array_rnd_create(int max_tal, int min_tal)
{
        for (int i = 0; i < size; i++) {
            int rnd_nr = random_in_range(min_tal, max_tal);         //Skapa ett slumptal
            heltals_array_pekare[i].set_heltal(rnd_nr);
        }
}

//Hjälpfunktion för att skapa slumptal, lånad från internet...
int array_av_heltal::random_in_range (int min, int max)
{
  int base_random = rand(); /* in [0, RAND_MAX] */
  if (RAND_MAX == base_random) return random_in_range(min, max);

  /* now guaranteed to be in [0, RAND_MAX) */
  int range       = max - min,
      remainder   = RAND_MAX % range,
      bucket      = RAND_MAX / range;

  /* There are range buckets, plus one smaller interval
     within remainder of RAND_MAX */
  if (base_random < RAND_MAX - remainder) {
    return min + base_random/bucket;
  }
  else {
    return random_in_range (min, max);
  }
}

void array_av_heltal::sortera_array()
{
    array_quick_sort(0, (size-1));  //Sortera hela arrayen från element 0 till size-1
}

void array_av_heltal::array_quick_sort(int first, int last)
{
    int low = first;
    int high = last;
    int z = heltals_array_pekare[(first+last)/2].get_heltal();  // Välj mittvärdet som pivotelement
    heltals_klass *x = new heltals_klass(z);
do {

    // Gå från början och sök första värdet som är större än x
    while(heltals_array_pekare[low] < *x) {
    low++;
    }

    // Gå från slutet och sök första värdet som är mindre än x
    while(heltals_array_pekare[high] > *x) {
    high--;
    }

    if(low<=high) {
        swap(heltals_array_pekare[low], heltals_array_pekare[high]);
        low++;
        high--;
    }

} while(low <= high); // Loopa genom vektorn medan low <= high

// Rekursion
// "Sortera" vänster halva om high inte nått vektorns första element
if(first < high)
    array_quick_sort(first,high);

// "Sortera" höger halva om low inte nått vektorns sista element
if(low < last)
    array_quick_sort(low,last);
}
//Slut på array_quick_sort



//Utskrift av arrayen
void array_av_heltal::array_print()
{
    //cout << "Arrayen blir:" << endl;


    //skriv ut arrayen, loopa igenom elementen
    for (int i = 0; i < size; i++) {
        cout << heltals_array_pekare[i].get_heltal() << " " ;
    }
    cout << endl;
}
//Slut utskrift
