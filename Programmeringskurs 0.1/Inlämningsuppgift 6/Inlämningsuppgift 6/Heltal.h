#ifndef HELTAL_H
#define HELTAL_H


class Heltal
{
    public:

        Heltal();
        ~Heltal();
        int GetTal();
        void SetTal(int val);
        bool operator> (Heltal &);
        bool operator< (Heltal &);

    private:
        int tal;
};

#endif // HELTAL_H
