#include <iostream>
#include <iomanip>
#include "math.h"
using namespace std;

int main()
{
    int i;
    int j;
    for (i=100; i<=999; i++)
    {
        int rez=0;
        int c[3];
        c[0] = pow((i %10), 3);
        c[1] = pow(((i/10) %10), 3);
        c[2] = pow(((i/100) %10), 3);
        for (j=0; j<3; j++)
            rez+=c[j];
        if (rez==i)
            cout << i << endl;
    }
    return 0;
}
