#include"Auto.h"
#include"Truck.h"
#include"PasCar.h"
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    PasCar car=PasCar();
    cout << "Type of passanger car: " << car.TypeOfPasCar()<<endl;
    cout << "Service price of the passanger car (PasCar Class method): " << car.servicePrice() << endl;
    cout << "Service price of the passanger car (Auto Class method): " << car.Auto::servicePrice() << endl;
    Truck truck=Truck();
    cout << "Service price of the truck: " <<truck.servicePrice() << endl;

    cout << "PRINTING OBJECTS"  << endl;
    car.print(cout);
    truck.print(cout);

    //FILES
    fstream file;
    file.open("InheritanceTest.txt", ios::in);
    car.input(file);
    file.close();
    cout << car;    
    file.open("InheritanceTest.txt", ios::app);
    car.print(file);
    file.close();

    fstream file2;
    file2.open("InheritanceTest2.txt",ios::in);
    file2 >> truck;
    file2.close();
    cout << truck;
    file2.open("InheritanceTest2.txt",ios::app);
    truck.print(file2);
    file2.close();


    // cout << endl;
    // cout << "VIRTUAL" << endl;
    // Auto autom=Auto();
    // Auto *a;
    // a=&truck;
    // a->print(cout) ;
    // cout << endl;
    // a=&autom;
    // a->print(cout);

}

//g++ -o InheritanceTest.exe InheritanceTest.cpp Auto.cpp PasCar.cpp Truck.cpp && ./InheritanceTest.exe