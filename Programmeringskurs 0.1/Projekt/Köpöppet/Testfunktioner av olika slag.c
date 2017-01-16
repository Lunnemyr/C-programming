void testa_slumptals_generatorn()
{
    printf("Ange hur många gånger vi skall köra: ");
    int tarningssida;               //vilken sida på tärningen som kommer upp
    int antal_kast;                 //antal gånger tärningen skall kastas
    int kast_nr;                    //nummer för det aktuella kastet

    int antal_ettor = 0; //Dessa variabler är för att räkna antalet träffar
    int antal_tvaor = 0; //på respektive tärningssida
    int antal_treor = 0;
    int antal_fyror = 0;

    scanf("%d", &antal_kast);       //be användare mata in hur många kast som skall göras
    srand(time(0));                 //frö till rand

    // Kasta antal_kast gånger
    for(kast_nr=1; kast_nr<=antal_kast; ++kast_nr) {

    tarningssida = (IntervallRandNumber() + 1);   //kasta tärningen

    switch (tarningssida) {         //kolla vilken sida som kom upp,
        case 1 :                    //och räkna upp antalet på respektive sida
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

    //Skriv ut resultatet i numerärer
    printf("\n\nResultatet av %d kast:\n", antal_kast);//skriv ut resultatet i kolumner
    printf("Ettor:%8s%-d\n","", antal_ettor); //gör först en kolumn för att sedan
    printf("Tvåor:%8s%-d\n", "", antal_tvaor);//vänsterjuster i andra kolumnen
    printf("Treor:%8s%-d\n", "",antal_treor);
    printf("Fyror:%8s%-d\n", "", antal_fyror);

    //Skriv ut resultatet i frekvens i procent.
    printf("\nFrekvens i procent:\n");
    printf("Ettor:%8s%-.1f%%\n", "", (double) antal_ettor/antal_kast*100);
    printf("Tvåor:%8s%-.1f%%\n", "", (double) antal_tvaor/antal_kast*100);
    printf("Treor:%8s%-.1f%%\n", "", (double) antal_treor/antal_kast*100);
    printf("Fyror:%8s%-.1f%%\n", "", (double) antal_fyror/antal_kast*100);
}
//end kasta tarning
