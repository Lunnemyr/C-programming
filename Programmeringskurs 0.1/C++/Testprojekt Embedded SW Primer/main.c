#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool runTask(int iTaskNumber); //protot

int main(void)
{
    int iRundaNummer;
    for(iRundaNummer=1; iRundaNummer<=10; ++iRundaNummer) {
    printf("Round Robin - Maaaaan!\n");

    bool bResultat = false;

    printf("\n\nRunda nr: %d\n", iRundaNummer);

    bResultat = runTask(1);
    if (bResultat) {
        printf ("Körde task nr 1 med resultat: %s\n", bResultat ? "true" : "false");
    }
    bResultat = runTask(2);
    printf ("Körde task nr 2 med resultat: %s\n", bResultat ? "true" : "false");

    bResultat = runTask(3);
    printf ("Körde task nr 3 med resultat: %s\n", bResultat ? "true" : "false");

    }
    return 0;
}

bool runTask(int iTaskNumber)
{
    switch (iTaskNumber) {
    case 1:
        return 1;
    case 2:
        return 0;
    case 3:
        return 1;
    }
//Should not get here
printf("Något gick helt åt h-vete");
    }
