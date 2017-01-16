
/* doschars.c */
/* prints all the chars in the dos window and their oktal numbers */

#include <stdio.h>
#include <stdlib.h>

int chars (int argc, char *argv[])
{
  int i;
  for(i=1;i<=255;i++)
   {
     printf("tal (oktalt): %o  tecken:  %c\n", i, i);
   }

/* Wait here to see output from program before the window closes. */
printf("\nPress enter to exit!");
char ch; scanf("%c",&ch);
return 0;

}
// Svenska tecken i DOS-fönstret
// å \206, Å \217, ä \204, Ä \216, ö \224, Ö \231

