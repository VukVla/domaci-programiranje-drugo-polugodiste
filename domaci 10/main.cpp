#include <iostream>

using namespace std;

class Kamera
{
public:
    int megaPikseli;
    int freeSpace;
    static int photoCounter;
    Kamera()
    {
        megaPikseli = 7;
        freeSpace = 30;
    }
    Kamera(int m, int f)
    {
        megaPikseli = mp;
        freeSpace = fs;

    }
    Kamera(const Kamera &k)
    {
        megaPikseli = k.megaPikseli;
        freeSpace = k.freeSpace;

    }
    int getMegaPikseli()const
    {
        return megaPikseli;
    }
    int getFreeSpace()const
    {
        return freeSpace;
    }
    int getPhotoCounter()const
    {
        return photoCounter;
    }
    bool slikajSliku()
    {
        if(freeSpace - megaPikseli > 0)
        {
            freeSpace -= megaPikseli;
            Kamera::photoCounter++;
            return true;
        }
        return false;
    }
};

class videoKamera: public Kamera
{
public:
    static int videocounter;

    videoKamera(): Kamera()
    {
        videoCounter = 10;
    }
    videoKamera(int m, int f): Kamera(m,f)
    {

    }
    videoKamera (const Kamera & k): Kamera(k){}
    int getVideoCounter()const
    {
        return videoCounter;
    }

    bool snimaj(int sekunde)
    {
        if(freeSpace - megaPikseli * sekunde > 0)
        {
            freeSpace -= megaPikseli * sekunde;
            videoCounter++;
            return true;
        }
        return false;
    }
};

class Telefon
{
    public:
        string broj;
        Telefon()
        {
            broj="100";
        }
        Telefon(string b)
        {
            broj = b;
        }
        bool pozovi(string b)
        {
            if(broj != b)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class telefonGen2: public Telefon
{
    public:
        Kamera k;
        telefonGen2(): Telefon(), k() {}
        telefonGen2 (string b, int m, int f):Telefon(b), k(m,f) {}
        telefonGen2 (string b, const Kamera& kk):Telefon(b), k(kk) {}
        bool slikajSliku()
        {
            return k.slikaj();
        }
};

class telefonGen3: public Telefon
{
public:
    videoKamera vd;

    telefonGen3():vd(), Telefon() {}
    telefonGen3 (int m, int f, string b):vd(m, f), Telefon(b){}
    telefonGen3 (string b, const Kamera & k): Telefon(b), vd(k) {}
    bool snimiVideo(int sec)
    {
        return vd.snimaj(sec);
    }
};

int Kamera::photoCounter = 0;
int videoKamera::videoCounter = 0;
int main()
{

    telefonGen2 tel("0621838410", 7, 30);
    if(tel.pozovi("0621838410"))
    {
        printf("Uspesno!\n");
    }
    else
    {
        printf("Neuspesno\n");
    }
/// nisam znao kako ostatak test programa
    return 0;
}
