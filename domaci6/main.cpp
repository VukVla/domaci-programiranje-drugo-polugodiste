#include <iostream>
#include <cmath>

using namespace std;

class stepen
{
private:
    double x;
    int y;

public:
    stepen(){
        x=1;
        y=1;
    }
    stepen(double xx, int yy){
        x = xx;
        y = yy;
    }
    void setX(double xx){
        x = xx;
    }
    void setY(int yy){
        y = yy;
    }
    void setX_Y(double xx, int yy){
        x = xx;
        y = yy;
    }

    double getX() const{
        return x;
    }
    int getY() const{
        return y;
    }
    double getXnaY() const{
        return pow(x, y);
    }
};

int main()
{
    stepen p1;
    stepen p2(5, 6);

    cout << "test:" << endl;
    cout << "x:" << p1.getX() << endl;
    cout << "y:" << p1.getY() << endl;
    cout << "x^y:" << p1.getXnaY() << endl;
    return 0;
}
