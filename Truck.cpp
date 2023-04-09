#include "Truck.h"

Truck::Truck()
{
   tonnage=2.9;
   setBrand("KOLP");
}

Truck::Truck(float tonnage, string brand,unsigned int mileage,int age, float weight,float engineCap,int n,previous *arr):Auto(brand,  mileage, age,  weight, engineCap,n,arr),tonnage(tonnage)
{
}

float Truck::getTon() const
{
    return tonnage;
}
float Truck::servicePrice() const
{
    float price;
    price=Auto::servicePrice()+Auto::servicePrice()*0.05*int(tonnage);
    return price;
}

Auto& Truck::operator=(const Auto& oth)
{
    if(const Truck*derived=dynamic_cast<const Truck*>(&oth)){
        if(this!=*&derived){
            Auto::operator=(oth);
            tonnage=derived->tonnage;
        }
    }
    return *this;
}

void Truck::input(istream& is)
{
    is >> tonnage;
    Auto::input(is);
    // getline(is ,brand);
    // is >> mileage;
    // is >> age;
    // is >> weight;
    // is >> engineCap;
    // is >> n;
    // arr=new previous[n]; 
    // for(int j=0;j<n; j++){
    //     if(j==0){
    //          is.ignore(numeric_limits<streamsize>::max(), '\n');
    //     }     
    //     is >> arr[j].name;
    //     is >> arr[j].year;
    //     is.ignore(numeric_limits<streamsize>::max(), '\n');
    // }

}

void Truck::print(ostream& os) const
{
    // os << endl;
    // os << "TRUCK PRINT FUNC" << endl;
    // os << "Tonnage: " << tonnage << endl;
    //  os << "Brand: "<< getBrand() << endl;
    // os << "Mileage: " <<getMileage() << endl;
    // os << "Age: "  << getAge() << endl;
    // os << "Weight: " << getWeight()<< endl;
    // os << "Engine capacity: " << getEngineCap()<< endl;
    // previous * arrOfOwners;
    // arrOfOwners= this->getOwners();
    // for (int i=0; i<getN(); i++){
    //     os << arrOfOwners[i].name << endl;
    //     os << arrOfOwners[i].year << endl;
    // }
    // delete [] arrOfOwners;
    os  << tonnage << " ";
    Auto::print(os);
}

// Truck& Truck:operator = (const Truck& Car2)
// {
//     if(this!=&Car2){
//         tonnage=car2.tonnage;
//         Auto::ope
//     }
   
//     return *this;
// }


Truck::~Truck()
{

}

void Truck::print () const
{
    cout << "Truckkkkkkk" << endl;
}