#include <iostream>
#include <iomanip>
#include "math.h"
using namespace std;

int main()
{

    float rez=0, a;
    int i;
    cout << "uneti a" << endl;
    cin >> a;
    for (i = 1; i <= a; i++)
        rez += sqrt(i);
    cout << fixed;
    cout << setprecision(2) << rez;
    return 0;
}
