#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    float pow[] = {2.5, 1, 3};
    polynomial p1(2, pow);
    p1.Insert(3, 4);
    polynomial p2(2, pow);
    polynomial p3 = p1+p2;
    return 0;
}
