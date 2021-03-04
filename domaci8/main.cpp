#include <iostream>

using namespace std;

#define MIN_KANAL 1
#define MAX_KANAL 5
#define KORAK 1
#define MIN_ZVUK 0
#define MAX_ZVUK 20

enum Stanje{on = 1,off ,pokv};

class Televizor{
    private:
        Stanje stanje;
        int kanal;
        int zvuk;
    public:
        Televizor(){stanje = off; zvuk = 0; kanal = 1;};
        Televizor(Televizor &t){stanje = t.stanje; kanal = t.kanal; zvuk = t.zvuk;};

        bool ukljuci()
        {
            bool uspeh = false;
            if(stanje == off)
            {
                stanje = on;
                uspeh = true;
            }
            return uspesno;
        };

        bool iskljuci()
        {
            bool uspeh = false;
            if(stanje == on)
            {
                stanje = off;
                zvuk = 0;
                kanal = 1;
                uspeh = true;
            }
            return uspeh;
        };

        bool pokvari()
        {
            bool uspeh = false;
            if(stanje != pokv)
            {
                stanje = pokv;
                zvuk = 0;
                kanal = 1;
                uspeh = true;
            }
            return uspeh;
        };

        bool popravi()
        {
            bool uspeh = false;
            if(stanje == pokv)
            {
                stanje = off;
                uspeh = true;
            }
            return uspeh;
        };


        bool kanalnapred()
        {
            bool uspeh = false;
            if(stanje == on && kanal + KORAK <= MAX_KANAL)
            {
                kanal += KORAK;
                uspeh = true;
            }
            return uspeh;
        };

        bool kanalnazad()
        {
            bool uspeh = false;
            if(stanje == on && kanal - KORAK >= MIN_KANAL)
            {
                kanal -= KORAK;
                uspeh = true;
            }
            return uspeh;
        };

        bool pojacaj()
        {
            bool uspeh = false;
            if(stanje == on && zvuk + KORAK <= MAX_ZVUK)
            {
                zvuk += KORAK;
                uspeh = true;
            }
            return uspeh;
        };

        bool smanji()
        {
            bool uspeh = false;
            if(stanje == on && zvuk - KORAK >= MIN_ZVUK)
            {
                zvuk -= KORAK;
                uspeh = true;
            }
            return uspeh;
        };

        Stanje getStanje() const
        {
            return stanje;
        }

        int getZvuk() const
        {
            return zvuk;
        };

        int getKanal() const
        {
            return kanal;
        };
};

void ispis(const Televizor &t)
{
    string privremeni;
    switch(t.getStanje())
    {
        case off:
            temp = "iskljucen";
            break;
        case on:
            temp = "ukljucen";
            break;
        case pokv:
            temp = "pokvaren";
            break;
    }
    cout << "stanje televizora: " << privremeni << endl;
    cout << "jacina zvuka: " << t.getZvuk() << endl;
    cout << "kanal: " << t.getKanal() << endl;
}
