#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    float pow[] = {1, 0, 1};
    polynomial P(2, pow);
    P.Calculate(4.5);
    return 0;
}
