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
        polynomial(const polynomial&);
        ~polynomial();
        void Insert(unsigned int, float);
        float Calculate(float) const;
        int GetDegree() const;
        polynomial operator+(const polynomial&) const;
        polynomial operator*(const polynomial&) const;
        friend polynomial operator*(const float, const polynomial&);
        friend polynomial operator*(const polynomial&, const float);
        polynomial operator/(const polynomial&) const;
        float& operator[](const int);
        const float& operator[](const int) const;
        polynomial& operator=(const polynomial&);
        friend std::ostream& operator<<(std::ostream&, const polynomial&);
        friend std::istream& operator>>(std::istream&, polynomial&);
};

#endif // POLYNOMIAL_H
