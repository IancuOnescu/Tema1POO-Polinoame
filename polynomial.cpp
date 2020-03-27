#include "polynomial.h"
#include <algorithm>

polynomial::polynomial(){
    first_ = NULL;
    last_ = NULL;
    degree_ = -1;
}

polynomial::polynomial(int degree, float coefValues[]={0}) : polynomial(){
    for(int index=0; index<=degree; ++index)
        Insert(index, coefValues[index]);
}

void polynomial::Insert(unsigned int exponent, float coefValue){
    if(first_ == NULL){
        first_ = last_ = new term(exponent, coefValue);
        return;
    }
    term *newTerm = new term(exponent, coefValue);
    last_->next_ = newTerm;
    last_ = newTerm;
    ++degree_;
}

int polynomial::GetDegree(polynomial polyObj) const{
    return polyObj.degree_;
}

float polynomial::Calculate(float value){
    float finalSum = 0;
    for(term *aux = first_; aux; aux=aux->next_){
        float valueToExp = 1;
        for(int index = 1; index <= aux->exponent_; ++index)
            valueToExp *= value;
        finalSum += (valueToExp * aux->coefficient_);
    }
    return finalSum;
}

polynomial polynomial::operator+(polynomial& polyObj){
    polynomial returnPoly(std::max(degree_, polyObj.degree_));
    int index = 0;
    int minimumDegree = std::min(degree_, polyObj.degree_);
    while(index <= minimumDegree)
        returnPoly[index]=this->operator[](index)+polyObj[index++];
    while(index <= degree_)
        returnPoly[index]=this->operator[](index++);
    while(index <= polyObj.degree_)
        returnPoly[index]=polyObj[index++];
    return returnPoly;
}

float& polynomial::operator[](const int index){
    term *aux = first_;
    for(int i=0; i<index; i++)
        aux = aux->next_;
    return aux->coefficient_;
}

polynomial::~polynomial(){
    if(first_ == NULL)
        return;
    term* aux1 = first_;
    term* aux2 = last_;
    while(aux1 != NULL){
        aux2 = aux1->next_;
        delete aux1;
        aux1 = aux2;
    }
}
