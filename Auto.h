#pragma once
#include<iostream>
#include<string>

using namespace std;

struct previous{
        string name;
        int year;
    };

class Auto
{
private:
    string brand;
    unsigned int mileage;
    int age;
    float weight;
    float engineCap;
    int n;
    previous *arr;

public:
    Auto();
    Auto(string brand, unsigned int mileage, int age, float weight, float engineCap, int n, previous *__arr);
    Auto(const Auto &otc);
    virtual ~Auto();
    void setBrand(string brand);
    void setMileage(unsigned int mileage);
    void setAge(int age);
    void setWeight(float weight);
    void setEngineCap(float engineCap);
    void setOwners(int q);
    string getBrand() const;
    unsigned int getMileage() const;
    int getAge() const;
    float getWeight() const;
    float getEngineCap() const;
    int getN() const;
    previous* getOwners() const;
    virtual float servicePrice() const;
    int serviceTimes() const;
    void input(); 
    // virtual void print() const;
    virtual void input(istream& is);
    virtual void print(ostream& os) const;
    friend ostream& operator << (ostream& os, const Auto& Car1);
    friend istream& operator >> (istream& is, Auto& Car2);
    friend bool operator < (Auto& Car1,Auto& Car2);
    friend bool operator > (Auto& Car1,Auto& Car2);
    friend bool operator == (const Auto& Car1,const Auto& Car2);
    friend bool operator != (Auto& Car1,Auto& Car2);
    virtual Auto& operator = ( const Auto&  Car2);
    // virtual Auto* operator ++ ();
    // virtual Auto* operator ++ (int);
    operator string ();
    
};