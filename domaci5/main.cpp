#include <iostream>
#include <cmath>
using namespace std;

class jednakokrakiTrougao{
    private:
        double a;
        double b;
        double c;

    public:

        Trougao()

        Trougao(double aa, double bb, double cc){
            a=aa;
            b=bb;
            c=cc;
        }



        void setA(double aa) {a = aa;}
        void setB(double bb) {b = bb;}
        void setC(double cc) {c = cc;}

        double getA() {return a;}
        double getB() {return b;}
        double getC() {return c;}

        double getO() const{return a+b+c;}
        double getP() const
        {
            double s = (a+b+c)/ 2;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }

};

int main()
{
    Trougao t1;
    Trougao t2(3,5,5);

    cout << t1.getA() << endl;
    t1.setA(2);
    cout << t1.getA() << endl;






    cout << "duzina stranice a: " << t1.getA() << endl;
    cout << "duzina stranice b: " << t1.getB() << endl;
    cout << "duzina stranice c: " << t1.getC() << endl;
    cout << "obim: " << t1.getO() << endl;
    cout << "povrsina: " << t1.getP() << endl << endl;

    t1.setA(6);
    t1.setB(9);
    t1.setC(9);

    cout << "duzina stranice a: " << t1.getA() << endl;
    cout << "duzina stranice b: " << t1.getB() << endl;
    cout << "duzina stranice c: " << t1.getC() << endl;
    cout << "obim: " << t1.getO() << endl;
    cout << "povrsina: " << t1.getP() << endl;


    return 0;
}
