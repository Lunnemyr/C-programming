//Inlämningsuppgift 6
//Henrik Axelsson, 750328-4999

#ifndef HELTALS_KLASS_H
#define HELTALS_KLASS_H


class heltals_klass
{
    public:
            heltals_klass();                            //Defaultkonstruktor
            heltals_klass(int tal);                     //Konstruktor för att skapa och sätta heltalet
            virtual ~heltals_klass();                   //Dekonstruktor
            int get_heltal() { return heltal; }         //get-funktion med implementation
            void set_heltal(int tal) { heltal = tal;}   //set-funktion med implementation
            bool operator < (heltals_klass &obj2);
            bool operator > (heltals_klass &obj2);
            int operator+(heltals_klass & obj3);

    protected:

    private:
            int heltal;

};

#endif // HELTALS_KLASS_H
