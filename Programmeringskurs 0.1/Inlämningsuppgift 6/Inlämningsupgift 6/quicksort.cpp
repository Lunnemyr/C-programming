#include <iostream>
#include "Heltal.h"

using namespace std;

void quicksort(int a[], int first, int last);


int main()
{
    cout << "Testprogram:" << endl;
    Heltal heltal1;
    heltal1.SetTal(5);
    cout << "Talet i Heltal �r: " << heltal1.GetTal() << endl;
    return 0;
}


void quicksort(int a[], int first, int last)
{
    int low = first;
    int high = last;
    int x = a[(first+last)/2];          // V�lj mittv�rdet som pivotelement

do {

    // G� fr�n b�rjan och s�k f�rsta v�rdet som �r st�rre �n x
    while(a[low] < x) {
    low++;
    }

    // G� fr�n slutet och s�k f�rsta v�rdet som �r mindre �n x
    while(a[high] > x) {
    high--;
    }

    if(low<=high) {
        swap(a[low],a[high]);
        low++;
        high--;
    }

} while(low <= high); // Loopa genom vektorn medan low <= high

// Rekursion
// "Sortera" v�nster halva om high inte n�tt vektorns f�rsta element
if(first < high)
    quicksort(a,first,high);

// "Sortera" h�ger halva om low inte n�tt vektorns sista element
if(low < last)
    quicksort(a,low,last);
}
