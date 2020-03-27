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
        polynomial(int, float[]);
        void Insert(unsigned int, float);
        float Calculate(float);
        ~polynomial();
        int GetDegree(polynomial) const;
        polynomial operator+(polynomial&);
        float& operator[](const int);
};

#endif // POLYNOMIAL_H
