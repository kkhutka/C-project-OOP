#include "PasCar.h"

PasCar::PasCar()
{
    places=6;
}

PasCar::PasCar(int places, string brand,unsigned int mileage,int age, float weight,float engineCap,int n,previous *arr):Auto(brand,  mileage, age,  weight, engineCap,n,arr),places(places)
{
}

string PasCar::TypeOfPasCar() const
{
    string type;
    float e=getEngineCap();
    if(e<2){
        type="Malolitr";
    }else if(e>=2 && e<4){
        type="Seredlitr";
    }else{
        type="Bagatolitr";
    }
    return type;
}

float PasCar::servicePrice() const
{
    float price;
    price=Auto::servicePrice()+Auto::servicePrice()*0.02*places;
    return price;
}

Auto& PasCar::operator=(const Auto& oth)
{
    if(const PasCar*derived=dynamic_cast<const PasCar*>(&oth)){
        if(this!=*&derived){
            Auto::operator=(oth);
            places=derived->places;
        }
    }
    return *this;
}

void PasCar::input(istream& is)
{
    is >> places;
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

void PasCar::print(ostream& os) const
{
    // os << endl;
    // os << "PAS CAR PRINT FUNC" << endl;
    // os << "Places: " << places << endl;
    // os << "Brand: "<< getBrand() << endl;
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

    os  << places << " ";
    Auto::print(os);
}



PasCar::~PasCar()
{
}

void PasCar::print () const
{
    cout << "PasCCCCCar" << endl;
}