#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.h"

class polynomial
{
    int degree_;
    term* first_;
    term* last_;
    public:
        polynomial();
        polynomial(int);
        polynomial(int, float[]);
        polynomial(polynomial&);
        void Insert(unsigned int, float);
        float Calculate(float);
        ~polynomial();
        int GetDegree() const;
        polynomial& operator+(polynomial&);
        float& operator[](const int);
};

#endif // POLYNOMIAL_H
