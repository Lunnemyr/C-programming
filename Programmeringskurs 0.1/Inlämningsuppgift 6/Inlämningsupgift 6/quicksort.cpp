#include <iostream>
#include "Heltal.h"

using namespace std;

void quicksort(int a[], int first, int last);


int main()
{
    cout << "Testprogram:" << endl;
    Heltal heltal1;
    heltal1.SetTal(5);
    cout << "Talet i Heltal är: " << heltal1.GetTal() << endl;
    return 0;
}


void quicksort(int a[], int first, int last)
{
    int low = first;
    int high = last;
    int x = a[(first+last)/2];          // Välj mittvärdet som pivotelement

do {

    // Gå från början och sök första värdet som är större än x
    while(a[low] < x) {
    low++;
    }

    // Gå från slutet och sök första värdet som är mindre än x
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
// "Sortera" vänster halva om high inte nått vektorns första element
if(first < high)
    quicksort(a,first,high);

// "Sortera" höger halva om low inte nått vektorns sista element
if(low < last)
    quicksort(a,low,last);
}
