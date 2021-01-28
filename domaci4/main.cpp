#include <iostream>

using namespace std;

int main()
{
    int g;
    cout << "uneti godinu" << endl;
    cin >> g;
    if (g%4==0)
    {
        if ((g%100==0 && g%400!=0))
            cout << "Ne";
        else
            cout << "Da";
    }
    else
        cout << "Ne";
    return 0;
    /*
    izvanjavam se na terminu slanja,
    zaboravio sam da se salje u 8,
    a ne u 12 ko kod drugih profesora
    */
}
