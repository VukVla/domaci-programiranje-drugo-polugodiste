#include <iostream>

using namespace std;

int main()
{
    int a;
    int rez;
    int i;
    cout << "uneti a:" << endl;
    cin >> a;
    for (i = 1; i <= a; i++)
    rez *= i;
    cout << rez;
    return 0;
}
