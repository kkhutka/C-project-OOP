#pragma once
#include"Auto.h"
#include"Truck.h"
#include"PasCar.h"

using namespace std;


class AutoService 
{
private:
    string ASName;
    int CurN;
    int MaxN;
    Auto **service;
public:
    AutoService();
    ~AutoService();
    float PriceOfAll();
    Auto* ExpCar();
    Auto* NewestCar();
    void setASName(string ASName);
    void setCurN(int CurN);
    void setMaxN(int MaxN);
    void setservice(Auto**service,int n);
    string getASName() const;
    int getCurN() const;
    int getMaxN() const;
    Auto ** getservice();
    void copyArr(Auto ** arr,Auto ** arr2, int n);
    void AllBrands();
    void AddCar(Auto * A);
    void DeleteCar(int index);
    void SortByBrand();
    void SortByMileAge();
    void SortByAge();
    void SortByWeight();
    void SortByEngineCap();
    void SortByNumOfOwners();
    void TwoArrays(PasCar ** PasArr, Truck ** TruckArr, int &pas, int &tr);
    void ReadFromFile(fstream& file);
    void WriteInFile(fstream& file) const;
    void print(ostream& os) const;
    void print2(ostream& os) const;
    void NewMemory(Auto*& a, Auto*& b);

};