#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    float pow[] = {2, 1, 3};
    polynomial p1(2, pow);
    p1.Insert(3, 4);
    polynomial p2(2, pow);
    polynomial p3;
    p3 = p1+p2;
    /*cout<<p3[0]<<"\n";
    polynomial p4(p2);
    cout << p3 << endl;
    polynomial p5;
    cout << p5 << endl;
    p5[3] = 4;
    cout<< p5 << endl;
    cout<<p4[-2];
    polynomial p6 = p1*p2;
    cout<<p6<<endl;
    p6 = p6*2;
    cout<<p6;*/
    polynomial p4 = p2;
    p4[2] = -3;
    p4 = p4+p2;
    cout<<p4<<endl;
    p4 = p1 / p4;
    cout<<p4;
    return 0;
}
