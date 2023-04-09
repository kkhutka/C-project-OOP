#include "AutoService.h"
#include"Auto.h"
#include"Truck.h"
#include"PasCar.h"
#include<iostream>
#include<fstream>

using namespace std;

AutoService::AutoService()
{
    ASName="MOTO SERVICE";
    CurN=2;
    MaxN=2;
    service=new Auto*[MaxN];
    service[0]=new PasCar();
    service[1]=new Truck();
}


float AutoService::PriceOfAll()
{
    float price=0;
    for (int i=0; i<CurN; i++){
        price+=service[i]->servicePrice();
    }
    return price;
}

Auto* AutoService::ExpCar()
{
    float maxP=0;
    int in=0;
    for (int i=0; i<CurN; i++){
        if(service[i]->servicePrice()>maxP){
            maxP=service[i]->servicePrice();
            in=i;
        }
    }
    return service[in];
}

Auto* AutoService::NewestCar()
{
    int minAge=1000;
    int in=0;
    for (int i=0; i<CurN; i++){
        if(service[i]->getAge()<minAge){
            minAge=service[i]->getAge();
            in=i;
        }
    }
    return service[in]; 
}

void AutoService::AllBrands()
{
    int *num=new int [CurN];
    int all=0;
    string * brands=new string[CurN];
    int carBrand=0;
    for (int i=0; i<CurN; i++){
        bool flag=false;
        for (int j=0; j<CurN; j++){
            if(service[i]->getBrand()==brands[j]){
                num[j]++;
                flag=true;
            }
        }
        if(flag==false){
            brands[carBrand]=service[i]->getBrand();
            num[carBrand]=1;
            carBrand++;
        }
    }
    for (int i=0; i<carBrand; i++){
        cout << brands[i] << " : " << num[i] << endl;
    }
}

string AutoService::getASName() const
{
    return ASName;
}

int AutoService::getCurN() const
{
    return CurN;
}

int AutoService::getMaxN() const
{
    return MaxN;
}

Auto** AutoService::getservice() 
{
   Auto** copyarr=new Auto*[MaxN];
   for (int i=0; i<CurN; i++){
        NewMemory(copyarr[i],service[i]);
        *copyarr[i]=*service[i];
   } 
   return copyarr;
}
void AutoService::setASName(string ASName)
{
    this->ASName=ASName;
}
void AutoService::setCurN(int CurN)
{
    this->CurN=CurN;
}
void AutoService::setMaxN(int MaxN)
{
    this->MaxN=MaxN;
}

void AutoService::setservice(Auto** service,int n)
{
    delete [] service;
    service=new Auto*[n];
    for (int i=0; i<n; i++){
        NewMemory(this->service[i],service[i]);
        this->service[i]=service[i];
    }
}
void AutoService::AddCar(Auto * A)
{
    if (CurN==MaxN){
        MaxN=MaxN*2;
        Auto ** NewArr=new Auto * [MaxN];
        copyArr(service,NewArr,MaxN);
        delete [] service;
        service=new Auto * [MaxN];
        copyArr(NewArr,service,MaxN);
        delete [] NewArr;
    }
    if(dynamic_cast<PasCar*>(A))
    {
        service[CurN]=new PasCar;
    }else{
        service[CurN]=new Truck;
    }
    *service[CurN]=*A;
    CurN++;
}
void AutoService::DeleteCar(int index)
{
    for (int j=index; j<CurN-1; j++){
        service[j]=service[j+1];
    }
    CurN--;
}
void AutoService::ReadFromFile(fstream& file)
{
    delete [] service;
    int index=0;
    MaxN=1;
    CurN=0;
    service=new Auto*[MaxN];
    file>>index;
    while (!file.eof()){
        if(!index){
            break;
        }
        if(index==1){
            Auto * pointer1=new PasCar;
            pointer1->input(file);
            AddCar(pointer1);
            delete pointer1;
        }
        if(index==2){
            Auto * pointer=new Truck;
            pointer->input(file);
            AddCar(pointer);
            delete pointer;
        }
        file>>index;
    }

        
}
void AutoService::WriteInFile(fstream& file) const
{
    int k=1;
    int k2=2;
    for (int i=0; i<CurN; i++){
        if(dynamic_cast<PasCar*>(service[i])){
            file << k <<' ';
        }else{
            file << k2 << ' ';
        }
        service[i]->print(file);
    }
}

void AutoService::print(ostream& os) const
{
    os << ASName << endl;
    os << CurN << endl;
    os << MaxN << endl;
    for (int i=0; i<CurN; i++){
        service[i]->print(os);
        
    }
}

void AutoService::print2(ostream& os) const
{
    os << ASName << endl;
    os << CurN << endl;
    os << MaxN << endl;
    for (int i=0; i<CurN; i++){
        os << service[i]->getBrand();
        os << endl;
    }
}

void AutoService::copyArr(Auto ** arr, Auto** arr2, int n)
{
    for (int i=0; i<n; i++){
        arr2[i]=arr[i];
    }

}



void AutoService::SortByBrand()
{
    for (int i1=0; i1<CurN-1; i1++){
        for (int i=0; i<CurN-1; i++){
            if (service[i]->getBrand()>service[i+1]->getBrand()){
                swap(service[i], service[i+1]);
            }
        }
    } 
}
void AutoService::SortByMileAge()
{
    for (int i1=0; i1<CurN-1; i1++){
        for (int i=0; i<CurN-1; i++){
            if (service[i]->getMileage()>service[i+1]->getMileage()){
                swap(service[i], service[i+1]);
            }
        }
    } 
}
void AutoService::SortByAge()
{
    for (int i1=0; i1<CurN-1; i1++){
        for (int i=0; i<CurN-1; i++){
            if (service[i]->getAge()>service[i+1]->getAge()){
                swap(service[i], service[i+1]);
            }
        }
    } 
}
void AutoService::SortByWeight()
{
    for (int i1=0; i1<CurN-1; i1++){
        for (int i=0; i<CurN-1; i++){
            if (service[i]->getWeight()>service[i+1]->getWeight()){
                swap(service[i], service[i+1]);
            }
        }
    } 
}
void AutoService::SortByEngineCap()
{
    for (int i1=0; i1<CurN-1; i1++){
        for (int i=0; i<CurN-1; i++){
            if (service[i]->getEngineCap()>service[i+1]->getEngineCap()){
                swap(service[i], service[i+1]);
            }
        }
    } 
}
void AutoService::SortByNumOfOwners()
{
    for (int i1=0; i1<CurN-1; i1++){
        for (int i=0; i<CurN-1; i++){
            if (service[i]->getN()>service[i+1]->getN()){
                swap(service[i], service[i+1]);
            }
        }
    } 
}

void AutoService::TwoArrays(PasCar ** PasArr, Truck ** TruckArr, int &pas, int &tr)
{
    for (int i=0; i<CurN; i++){
        if(dynamic_cast<PasCar*>(service[i]))
        {
            PasArr[pas]= new PasCar;
           *PasArr[pas]=*service[i];
           pas++;
        }
        if(dynamic_cast<Truck*>(service[i]))
        {
            TruckArr[tr]=new Truck;
           *TruckArr[tr]=*service[i];
           tr++;
        }
    }
}

void AutoService::NewMemory(Auto*& a, Auto*& b)
{
    if(dynamic_cast<PasCar*>(b)){
        a=new PasCar;
    }else if(dynamic_cast<Truck*>(b)){
        a=new Truck;
    }
}


AutoService::~AutoService()
{
    delete [] service;
}