#ifndef TERM_H
#define TERM_H

#include <iostream>

class polynomial;

class term
{
    unsigned int exponent_;
    float coefficient_;
    term *next_;
    public:
        term(unsigned int, float);
        friend class polynomial;
        ~term();
};

inline term::term(unsigned int exponent, float coefficient) : exponent_(exponent), coefficient_(coefficient), next_(NULL){}


#endif // TERM_H
