#pragma once
#include "Auto.h"

class PasCar : public Auto
{
private:
    int places; 
public:
    PasCar();
    PasCar(int places, string brand,unsigned int mileage,int age, float weight,float engineCap,int n,previous *arr);
    float servicePrice() const;
    string TypeOfPasCar() const;
    Auto& operator=(const Auto& oth);
    void input(istream& is);
    void print(ostream& os) const;
    void print() const;
    ~PasCar();

};