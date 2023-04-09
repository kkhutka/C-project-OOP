#pragma once
#include "Auto.h"


class Truck: public Auto
{
private:
    float tonnage;
public:
    Truck();
    Truck(float tonnage, string brand,unsigned int mileage,int age, float weight,float engineCap,int n,previous *arr);
    float getTon() const;
    float servicePrice() const;
    Auto& operator=(const Auto& oth);
    void input(istream& is);
    void print(ostream& os) const;
    void print() const;
    ~Truck();

};

