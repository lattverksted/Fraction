#include <array>
#include <iostream>
#include <vector>
#include "ZFraction.h"
using namespace std;

// static array  
double moyenne1(double const static_arrray[], int len)
{
    double moy = 0;

        for (int i = 0; i < len; i++)
        {
            moy += static_arrray[i];
        }
    moy /= len;
    return moy;
}
// static array using pointer
double moyenne2(double *p, int len)
{
    double moy = 0;

    for (int i = 0; i < len; i++)
    {
        moy += *p;
        //cout << *p << endl;
        p++;
    }
    moy /= len;
    return moy;
}


// vector using reference ; const = function wil not modifier variable
double moyenne3(vector <double> const & dynamic_array)
{
    double moy = 0;
    size_t len = dynamic_array.size();

    for (int i = 0; i < len; i++)
    {
        moy += dynamic_array[i];
        //cout << *p << endl;
    }
    moy /= len;
    return moy;
}
int main()
{

    /*double static_arrray[40] = {0,0,30,30};
    vector <double> dynamic_array ;
    double input=0;
    
    for (int i = 0; i < 5; i++)
    {
        cout << "enter a number" << endl;
        cin >> input;
        dynamic_array.push_back(input);
    }

    cout <<"moyenne "<<moyenne3(dynamic_array) << endl;*/

    ZFraction f0(2,10);
    cout << "f0 " <<f0 << endl;

    ZFraction f1();
    cout << "f1 "<< f1 << endl;


    ZFraction f2(4,5);
    ZFraction f3(9, 10);
    cout << "f2 " <<f2 << endl;

	cout << f0 << "+" << f2 <<"="<< f0 + f2 << endl;
    cout << f0 << "-" << f2 <<"="<< f0 - f2 << endl;
    cout << f0 << "*" << f2 << "=" << f0 * f2 << endl;
   
    if(f3>f2) 
    {
        cout << f3 << ">" << f2 << endl;
    }
    else 
    {
        cout << f3 << "<=" << f2 << endl;
    }


}