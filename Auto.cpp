#include"Auto.h"
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;

Auto::Auto()
{
    brand="Honda";
    mileage=10000;
    age=3;
    weight=1480;
    engineCap=2;
    n=2;
    arr=new previous [n];
    arr[0].name.assign("jack");
    arr[0].year=2019;
    arr[1].name="emma";
    arr[1].year=2021;
    
}

Auto::Auto(string brand, unsigned int mileage, int age, float weight, float engineCap, int n, previous *__arr)
{
    this->brand=brand;
    this->mileage=mileage;
    this->age=age;
    this->weight=weight;
    this->engineCap=engineCap;
    this->n=n;
    arr=new previous [n];
    for (int i=0; i<n; i++){ 
        arr[i].name=__arr[i].name;
        arr[i].year=__arr[i].year;
    }
}

Auto::Auto(const Auto &otc)
{
    brand=otc.brand;
    mileage=otc.mileage;
    age=otc.age;
    weight=otc.weight;
    engineCap=otc.engineCap;
    n=otc.n;
    arr=new previous [n];
    for (int i=0; i<n; i++){
        arr[i].name=otc.arr[i].name;
        arr[i].year=otc.arr[i].year;
    }
}

void Auto::setBrand(string brand)
{
    this->brand=brand;
}

void Auto::setMileage(unsigned int  mileage)
{
    this->mileage=mileage;
}

void Auto::setAge(int age)
{
    this->age=age;
}

void Auto::setWeight(float weight)
{
    this->weight=weight;
}

void Auto::setEngineCap(float engineCap)
{
    this->engineCap=engineCap;
}

void Auto::setOwners(int q)
{
    delete [] arr;
    arr=new previous[q];
    for(int i=0; i<q; i++){
        cout << "Name: ";
        cin >>  arr[i].name;
        cout << "Year:";
        cin>> arr[i].year;
    }
    n=q;
}


string Auto:: getBrand() const
{
    return brand;
}

unsigned int Auto:: getMileage() const
{
    return mileage;
}

int Auto:: getAge() const
{
    return age;
}

float Auto:: getWeight() const
{
    return weight;
}

float Auto:: getEngineCap() const
{
    return engineCap;
}
int Auto:: getN() const
{
    return n;
}

previous *Auto:: getOwners() const
{
    previous *copyarr=new previous[n];
    for (int i=0; i<n; i++){
        copyarr[i].name=arr[i].name;
        copyarr[i].year=arr[i].year;
    }
    return copyarr;
}

float Auto::servicePrice() const
{
    int price;
    if(brand=="BMW" || brand=="Mercedes" || brand=="Audi" || brand=="Bugatti divo" || brand=="Ferrari"){
        if(age<=5){
            price=10000;
        }else{
            price=6500;
        }
    }else{
        if(age<=5){
            price=5000;
        }else{
            price=3400;
        }
    }
    return price;
}

int Auto::serviceTimes() const
{
    int timesa=age/2;
    int timesm=mileage/10000;
    return timesa+timesm;
}

void Auto::input()
{
    cout << "Brand: "; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,brand);
    cout << "Mileage: "; cin >> mileage;
    cout << "Age: "; cin >> age;
    cout << "Weight: ";  cin >> weight;
    cout << "Engine capacity: "; cin >>engineCap;
    cout << "Number of previous owners: "; cin >> n;
    arr=new previous[n];
    for(int i=0; i<n; i++){
        cout << "Name: "; cin >>  arr[i].name;
        cout << "Year:"; cin>> arr[i].year;
    }
}

void Auto::input(istream &is)
{
    // is.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(is ,brand, ',');
    if(brand[0]==' ') {
        brand.erase(0,1);
    }
    is >> mileage;
    is >> age;
    is >> weight;
    is >> engineCap;
    is >> n;
    arr=new previous[n]; 
    for(int j=0;j<n; j++){
        if(j==0){
            //  is.ignore(numeric_limits<streamsize>::max(), '\n');
        }     
        getline(is,arr[j].name, ',');
        is >> arr[j].year;
        // is.ignore(numeric_limits<streamsize>::max(), '\n');
    }    
}


// void Auto::print() const
// {
//     cout << "Brand: " << brand<< endl;
//     cout << "Mileage: " << mileage << endl;
//     cout << "Age: "  << age << endl;
//     cout << "Weight: " << weight<< endl;
//     cout << "Engine capacity: " << engineCap<< endl;
//     for (int i=0; i<n; i++){
//         cout << "Owner name: " << arr[i].name << endl;
//         cout << "Owner year: " << arr[i].year << endl;
//     }
// }

void Auto::print(ostream &os) const
{
    os << getBrand() << ", " << getMileage() << " " << getAge() << " " << getWeight() << " " << getEngineCap() << " " << getN() << " ";
    previous * arrOfOwners;
    arrOfOwners= this->getOwners();
    for (int i=0; i<getN(); i++){
        os << arrOfOwners[i].name << ", "<< arrOfOwners[i].year << " ";
    }
    // os << endl;
    delete [] arrOfOwners;
}

ostream& operator << (ostream& os, const Auto& Car1)
{
    Car1.print(os);
    return os;
}

istream& operator >> (istream& is, Auto& Car2)
{
    Car2.input(is);
    return is;
}

bool operator < (Auto& Car1,Auto& Car2)
{
    return Car1.brand<Car2.brand;
}

bool operator > (Auto& Car1,Auto& Car2)
{
    return Car1.brand>Car2.brand;
}

bool operator == (const Auto& Car1,const Auto& Car2)
{
    if(Car1.brand!=Car2.brand){
        return false;
    }
    if(Car1.mileage!=Car2.mileage){
        return false;
    }
    if(Car1.age!=Car2.age){
        return false;
    }
    if(Car1.weight!=Car2.weight){
        return false;
    }
    if(Car1.engineCap!=Car2.engineCap){
        return false;
    }
    if(Car1.n!=Car2.n){
        return false;
    }
    for(int i=0; i<Car1.n; i++){
        if (Car1.arr[i].name!=Car2.arr[i].name){
            return false;
        }
        if (Car1.arr[i].year!=Car2.arr[i].year){
            return false;
        }
    }
    return true;

}

bool operator != (Auto& Car1,Auto& Car2)
{
    return Car1.brand!=Car2.brand;
}

Auto& Auto::operator = (const Auto& Car2)
{
    if(this!=&Car2){
        brand.assign(Car2.brand);
        mileage=Car2.mileage;
        age=Car2.age;
        weight=Car2.weight;
        engineCap=Car2.engineCap;
        n=Car2.n;
        arr=new previous [n];
        for (int i=0; i<n; i++){
                arr[i].name.assign(Car2.arr[i].name);
                arr[i].year=Car2.arr[i].year;
        }
    }
   
    return *this;
}

// Auto* Auto::operator++ ()
// {
//     this->mileage+=1000;
//     Auto *temp;
//     Auto *temp1=this;
//     allocate_mem(temp,temp1);
//     *temp=*this;
//     return this;
// }

// Auto* Auto:: operator++(int)
// {
//     Auto *temp;
//     Auto *temp1=this;
//     allocate_mem(temp,temp1);
//     *temp=*this;
//     this->mileage+=1000;
//     return temp;
// }

Auto::operator string()
{
    string str;
    str=str+"\nBrand: "+brand+"\nMileage: "+to_string(mileage)+"\nAge: "+to_string(age);
    str=str+"\nWeight: "+to_string(weight)+"\nEngine capacity: "+to_string(engineCap);
    for (int i=0; i<n; i++){
        str=str+"\nName: "+arr[i].name;
        str=str+"\nAge: "+to_string(arr[i].year);
    }
    return str;
}

Auto::~Auto()
{
    delete [] arr;

}

