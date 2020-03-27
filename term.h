#ifndef TERM_H
#define TERM_H

#include <iostream>

class polynomial;

class term
{
    float coefficient_;
    unsigned int exponent_;
    term *next_;
    public:
        term(unsigned int, float, term*);
        friend class polynomial;
        ~term();
};

inline term::term(unsigned int exponent, float coefficient, term* next= NULL) : exponent_(exponent), coefficient_(coefficient), next_(next){}


#endif // TERM_H
