#include "polynomial.h"
#include <algorithm>
#include <stdexcept>

polynomial::polynomial(){
    first_ = NULL;
    last_ = NULL;
    degree_ = -1;
}

polynomial::polynomial(int degree) : polynomial(){
    if(degree < 0){
        std::cout<<"Incorrect degree";
        exit(1);
    }
    for(int index=0; index<=degree; ++index)
        Insert(index, 0);
}

polynomial::polynomial(int degree, float coefValues[]) : polynomial(){
    for(int index=0; index<=degree; ++index)
        Insert(index, coefValues[index]);
}

polynomial::polynomial(const polynomial& copyPoly) : polynomial(){
    for(int index=0; index<=copyPoly.degree_; ++index)
        Insert(index, copyPoly[index]);
}

void polynomial::Insert(unsigned int exponent, float coefValue){
    if(first_ == NULL){
        first_ = last_ = new term(exponent, coefValue);
        ++degree_;
        return;
    }
    term *newTerm = new term(exponent, coefValue);
    last_->next_ = newTerm;
    last_ = newTerm;
    ++degree_;
}

void polynomial::Clear(){
        if(first_ != NULL){
        term* aux1 = first_;
        term* aux2;
        for(int index=0; index<=degree_; ++index){
            aux2 = aux1 -> next_;
            delete aux1;
            aux1 = aux2;
        }
        first_ = last_ = NULL;
        degree_ = -1;
    }
}

int polynomial::GetDegree() const{
    return degree_;
}

float polynomial::Calculate(float value) const{
    float finalSum = 0;
    for(term *aux = first_; aux; aux=aux->next_){
        float valueToExp = 1;
        for(unsigned int index = 1; index <= aux->exponent_; ++index)
            valueToExp *= value;
        finalSum += (valueToExp * aux->coefficient_);
    }
    return finalSum;
}

polynomial polynomial::operator+(const polynomial& polyObj) const{
    int maxDegree = std::max(degree_, polyObj.degree_);
    if(degree_ == polyObj.degree_)
        while(this->operator[](maxDegree) == -polyObj[maxDegree])
            --maxDegree;
    polynomial returnPoly(maxDegree);
    int index = 0;
    int minDegree = std::min(degree_, polyObj.degree_);
    if(minDegree > maxDegree)
        while(index <= maxDegree)
            returnPoly[index]=this->operator[](index)+polyObj[index++];
    else{
        while(index <= minDegree)
            returnPoly[index]=this->operator[](index)+polyObj[index++];
        while(index <= degree_)
            returnPoly[index]=this->operator[](index++);
        while(index <= polyObj.degree_)
            returnPoly[index]=polyObj[index++];
    }
    return returnPoly;
}

polynomial polynomial::operator*(const polynomial& polyObj) const{
    polynomial returnPoly(degree_+polyObj.degree_);
    for(int indexThis=0; indexThis<=degree_; ++indexThis)
        for(int indexPolyObj=0; indexPolyObj<=polyObj.degree_; ++indexPolyObj)
            returnPoly[indexThis+indexPolyObj] += this->operator[](indexThis) * polyObj[indexPolyObj];
    return returnPoly;
}

polynomial operator*(const float multValue, const polynomial& polyObj){
    polynomial returnPoly(polyObj.degree_);
    for(int index=0; index<=polyObj.degree_; ++index)
        returnPoly[index] = polyObj[index] * multValue;
    return returnPoly;
}

polynomial operator*(const polynomial& polyObj, const float multValue){
    return multValue * polyObj;
}

polynomial polynomial::operator/(const polynomial& polyDivisor) const{
    try{
        if(polyDivisor.degree_<0 || polyDivisor.degree_>degree_)
            throw std::out_of_range("incorrectDivisor");
    }catch(std::out_of_range){
        std::cout<<"Out of range Divisor";
    }
    int quotientCurrentTermDegree = degree_ - polyDivisor.degree_;
    float quotientCurrentTermCoefficient;
    polynomial dividentAtEachStep = *this;
    polynomial quotientPolynomial(quotientCurrentTermDegree);
    polynomial* substractAtEachStep;
    while(dividentAtEachStep.degree_ >= polyDivisor.degree_){
        quotientCurrentTermDegree = dividentAtEachStep.degree_-polyDivisor.degree_;
        quotientCurrentTermCoefficient = dividentAtEachStep[dividentAtEachStep.degree_] / polyDivisor[polyDivisor.degree_];
        quotientPolynomial[quotientCurrentTermDegree] = quotientCurrentTermCoefficient;
        substractAtEachStep = new polynomial(dividentAtEachStep.degree_);
        substractAtEachStep->operator[](dividentAtEachStep.degree_)= -dividentAtEachStep[dividentAtEachStep.degree_];
        dividentAtEachStep = dividentAtEachStep + *substractAtEachStep;
    }
    ///Reminder is left in dividentAtEachStep -> for future use
    return quotientPolynomial;
}

float& polynomial::operator[](const int index){
    try{
        if(index > degree_ || index < 0)
            throw std::out_of_range("indexError");
    }catch(std::out_of_range){
        std::cout<<"Polynomial index out of bounds\nTerminating...";
        exit(0);
    }
    term *aux = first_;
    for(int i=0; i<index; i++)
        aux = aux->next_;
    return aux->coefficient_;
}

const float& polynomial::operator[](const int index) const{
    try{
        if(index > degree_ || index < 0)
            throw std::out_of_range("indexError");
    }catch(std::out_of_range){
        std::cout<<"Polynomial index out of bounds\nTerminating...";
        exit(0);
    }
    term *aux = first_;
    for(int i=0; i<index; i++)
        aux = aux->next_;
    return aux->coefficient_;
}

polynomial& polynomial::operator=(const polynomial& polyObj){
    if(&polyObj != this){
        this->Clear();
        for(int index=0; index<=polyObj.degree_; ++index)
            Insert(index, polyObj[index]);
    }
    degree_ = polyObj.degree_;
    return *this;
}

std::ostream& operator<<(std::ostream& output, const polynomial& polyObj){
    std::string outPlus = "";
    if(polyObj.degree_ >= 0){
        for(int index=polyObj.degree_; index>=0; index--)
            if(polyObj[index] != 0){
                if(polyObj[index] > 0)
                    output << outPlus;
                if(polyObj[index] == -1)
                    output << "-";
                if(polyObj[index] != 1 && polyObj[index] != -1 || index==0)
                    output <<polyObj[index];
                if(index > 0)
                    output<<"X";
                if(index > 1)
                    output << "^" <<index;
                outPlus = " + ";
            }
        output<<" = 0";
    }
    return output;
}

std::istream& operator>>(std::istream& input, polynomial& polyObj){
    polyObj.Clear();
    int polySize;
    float coefficient;
    input >> polySize;
    for(int index=0; index<=polySize; ++index){
        input >> coefficient;
        polyObj.Insert(index, coefficient);
    }
    return input;
}

polynomial::~polynomial(){
    Clear();
}
