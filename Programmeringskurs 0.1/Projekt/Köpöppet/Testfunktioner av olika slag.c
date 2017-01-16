void testa_slumptals_generatorn()
{
    printf("Ange hur m�nga g�nger vi skall k�ra: ");
    int tarningssida;               //vilken sida p� t�rningen som kommer upp
    int antal_kast;                 //antal g�nger t�rningen skall kastas
    int kast_nr;                    //nummer f�r det aktuella kastet

    int antal_ettor = 0; //Dessa variabler �r f�r att r�kna antalet tr�ffar
    int antal_tvaor = 0; //p� respektive t�rningssida
    int antal_treor = 0;
    int antal_fyror = 0;

    scanf("%d", &antal_kast);       //be anv�ndare mata in hur m�nga kast som skall g�ras
    srand(time(0));                 //fr� till rand

    // Kasta antal_kast g�nger
    for(kast_nr=1; kast_nr<=antal_kast; ++kast_nr) {

    tarningssida = (IntervallRandNumber() + 1);   //kasta t�rningen

    switch (tarningssida) {         //kolla vilken sida som kom upp,
        case 1 :                    //och r�kna upp antalet p� respektive sida
            antal_ettor++;
            break;

        case 2 :
            antal_tvaor++;
            break;

        case 3 :
            antal_treor++;
            break;

        case 4 :
            antal_fyror++;
            break;
        } //end switch..case
    } //end for-loop

    //Skriv ut resultatet i numer�rer
    printf("\n\nResultatet av %d kast:\n", antal_kast);//skriv ut resultatet i kolumner
    printf("Ettor:%8s%-d\n","", antal_ettor); //g�r f�rst en kolumn f�r att sedan
    printf("Tv�or:%8s%-d\n", "", antal_tvaor);//v�nsterjuster i andra kolumnen
    printf("Treor:%8s%-d\n", "",antal_treor);
    printf("Fyror:%8s%-d\n", "", antal_fyror);

    //Skriv ut resultatet i frekvens i procent.
    printf("\nFrekvens i procent:\n");
    printf("Ettor:%8s%-.1f%%\n", "", (double) antal_ettor/antal_kast*100);
    printf("Tv�or:%8s%-.1f%%\n", "", (double) antal_tvaor/antal_kast*100);
    printf("Treor:%8s%-.1f%%\n", "", (double) antal_treor/antal_kast*100);
    printf("Fyror:%8s%-.1f%%\n", "", (double) antal_fyror/antal_kast*100);
}
//end kasta tarning
