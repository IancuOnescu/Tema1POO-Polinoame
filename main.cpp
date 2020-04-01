#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    float pow[] = {2, 1, 3};
    polynomial p1(2, pow);
    p1.Insert(3, 4);
    polynomial p2(2, pow);

    ///test for calculate
    cout<<p2<<endl;
    cout<<p2.Calculate(5)<<endl;

    polynomial p3;
    ///test for + and = overload
    p3 = p1+p2;
    cout<<p3[0]<<"\n";
    p3[0] = 120;
    cout<<p3[0]<<"\n";
    cin>>p3;
    cout<<p3<<endl;

    ///test for copy ctor
    polynomial p4(p2);
    cout << p4 << endl;


    ///prints nothing if the poly is empty
    polynomial p5;
    cout << p5 << endl;
    ///out of bounds error
    /*p5[3] = 4;*/

    ///test for * overload;
    cout<<p1<<endl<<p2<<endl;
    cout<<p1*p2<<endl;
    return 0;
}
