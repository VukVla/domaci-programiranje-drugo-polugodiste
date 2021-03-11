#include <iostream>
using namespace std;

enum tipPreliva {COKOLADNI, COKOLADNI_SA_SLAGOM};
class preliv
{
    private:
        tipPreliva tip;

    public:
        preliv()
        {
            tip = COKOLADNI;
        }

        preliv(tipPreliva t)
        {
            tip = t;
        }

        preliv(const preliv &p)
        {
            tip = p.tip;
        }

        bool dodajSlag()
        {
            if(tip == COKOLADNI_SA_SLAGOM)
                {
                return false;
                }
            else
            {
                tip = COKOLADNI_SA_SLAGOM;
                return true;
            }
        }

        bool ukloniSlag()
        {
            if(tip == COKOLADNI)
            {
                return false;
            }
            else
            {
                tip = COKOLADNI;
                return true;
            }
        }

        tipPreliva getTip() const
        {
            return tip;
        }
    };

void ispisiPreliv(const preliv &p)
{
    if(p.getTip()==COKOLADNI)
    {
        cout << "cokoladni" << endl;
    }
    else
    {
        cout << "cokoladni sa slagom" << endl;
    }
}

enum kolacStanje {U_PRIPREMI, PECE_SE, ZAGOREO, PRIPREMLJEN};

class kolac
{
    private:
        kolacStanje stanje;
        int temp;
        preliv* preliv;

    public:
        kolac()
        {
            preliv = new preliv();
            temp = 20;
            stanje = U_PRIPREMI;
        }

        kolac(const kolac & k)
        {
            stanje = k.stanje;
            temperatura = k.temperatura;
            preliv = new Preliv(*k.getPreliv());
        }

        bool staviDaSePece()
        {
            if(preliv->getTip() == COKOLADNI_SA_SLAGOM)
            {
                return false;
            }
            else
            {
                stanje = PECE_SE;
                temp += 1;
                return true;
            }
        }

        bool ispeciKolac()
        {
            if(stanje != PECE_SE)
                {
                    return false;
                }
            else
            {
            stanje = U_PRIPREMI;
            temp = 20;
            return true;
            }
        }

        bool zavrsiKolac()
        {
            if(stanje != U_PRIPREMI)
            {
                return false;
            }
            else
            {
                stanje = PRIPREMLJEN;
                return true;
            }
        }

        bool povecajTemp()
        {
            if(stanje != PECE_SE)
            {
                return false;
            }
            if(temperatura += 1 > 100)
            {
                stanje = ZAGOREO;
                temperatura = 20;
                return true;
            }
            temperatura += 1;
            return true;
        }

        bool smanjiTemp()
        {
            if(stanje != PECE_SE)
            {
                return false;
            }
            if(temperatura -= 1 < 40)
            {
                return false;
            }
            temperatura -= 1;
            return true;
        }

        bool dodajSlag()
        {
            if(stanje != U_PRIPREMI)
            {
                return false;
            }
            else
            {
                return preliv->dodajSlag();
            }
        }

        bool ukloniSlag()
        {
            if(stanje!=U_PRIPREMI)
            {
                return false;
            }
            else
            {
                return preliv->ukloniSlag();
            }
        }

        kolacStanje getStanje() const
        {
            return stanje;
        }

        int getTemp() const
        {
            return temp;
        }

        preliv* getPreliv() const
        {
            return preliv;
        }
};

void ispisiKolac(const kolac& k)
{
    cout << "Stanje: ";

    if(k.getStanje() == U_PRIPREMI)
    {
        cout << "U PRIPREMI";
    }

    if(k.getStanje() == PECE_SE)
    {
        cout << "PECE SE";
    }

    if(k.getStanje() == ZAGOREO)
    {
        cout << "Zagoreo";
    }

    if(k.getStanje() == PRIPREMLJEN)
    {
        cout << "PRIPREMLJEN";
    }

    cout << endl;
    cout << "Temperatura: " << k.getTemperatura() << endl;
    cout << "Preliv: ";
    ispisiPreliv();
}

void meni()
{
    kolac k;
    int i = 0;
    while(i!=9)
    {

        printf("1. stavi da se pece\n");
        printf("2. ispeci kolac\n");
        printf("3. zavrsi kolac\n");
        printf("4. povecaj temperaturu\n");
        printf("5. smanji temperaturu\n");
        printf("6. dodaj slag\n");
        printf("7. ukloni slag\n");
        printf("8. ispisi kolac\n");
        printf("9. kraj\n");
        scanf("%i", &i);
        getchar();

        if(i==1)
        {
            if(k.staviDaSePece())
            {
                printf("uspesno\n");
            }
            else
            {
                printf("greska\n");
            }
        }

        if(i == 2)
        {
            if(k.ispeciKolac())
            {
                printf("uspesno\n");
            }
            else
            {
                printf("greska\n");
            }
        }

        if(i == 3)
        {
            if(k.zavrsiKolac())
            {
                printf("uspesno\n");
            }
            else
            {
                printf("greska\n");

            }
        }

        if(i == 4)
        {
            if(k.povecajTemperaturu())
            {
                printf("uspesno\n");

            }
            else
            {
                printf("greska\n");
            }
        }

        if(i == 5)
        {
            if(k.smanjiTemperaturu())
            {
                printf("uspesno\n");
            }
            else
            {
                printf("greska\n");
            }
        }

        if(i == 6)
        {
            if(k.dodajSlag())
            {
                printf("uspesno\n");
            }
            else
            {
                printf("greska\n");
            }
        }

        if(i == 7)
        {
            if(k.ukloniSlag())
            {
                printf("uspesno\n");
            }
            else
            {
                printf("greska\n");
            }
        }

        if(i == 8)
        {
            ispisiKolac(k);
        }

    }
}


int main()
{
    meni();
    return 0;
}
