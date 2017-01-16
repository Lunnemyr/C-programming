//Inl�mningsuppgift 6
//Henrik Axelsson, 750328-4999

#ifndef MENU_H
#define MENU_H


class menu
{
    public:
            menu();
            virtual ~menu();
            void show_menu();                       //Visa menyn
            int get_selection ();                   //L�s in anv�ndarens val
            void run_selection(int selection);      //Exekvera anv�ndarens val
            int pause();                            //Pause, v�nta p� input

    private:
            void run_menyval_1();
            void run_menyval_2();
            void run_menyval_3();
            void run_menyval_4();

};

#endif // MENU_H
