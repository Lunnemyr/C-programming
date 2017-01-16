#ifndef SIMULATOR_HELPER_FUNCTIONS_H_INCLUDED
#define SIMULATOR_HELPER_FUNCTIONS_H_INCLUDED

int IntervallRandNumber();                                  //beräknar ett slumptal utifrån fördelningen (0.1..) osv.
int RandomInRange(int min, int max);                        //Beräknar ett rektangelfördelat slumptal mellan min och max.
int Pause(int isStepSimulation, int iTimeToRunSimulation, int iPauseTime);
void GetSelection(int * iSelection, char cText [], int iMin, int iMax);

#endif // SIMULATOR_HELPER_FUNCTIONS_H_INCLUDED
