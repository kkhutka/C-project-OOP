#include"AutoService.h"
#include"Auto.h"
#include"Truck.h"
#include"PasCar.h"
#include<iostream>
#include<fstream>

using namespace std;


void PrintArr(PasCar ** PasArr, int n)
{
    for(int i=0; i<n; i++){
        PasArr[i]->print(cout);
    }
}

void PrintArr(Truck ** TruckArr, int n)
{
    for(int i=0; i<n; i++){
        TruckArr[i]->print(cout);
    }
}

int main()
{
    AutoService A=AutoService();
    int menu=-1;
    while(menu!=12){
        cout << "------------------------MENU------------------------" << endl;
        cout << "1 - Price of service for all cars\n2 - Find the most expensive car service\n3 - The newest car on service\n4 - Cars of all brands\n5 - Delete a car\n6 - Add a car\n7 - Divide into two arrays\n8 - Sort\n9 - Read from file\n10 - Write to file\n11 - Print Auto service\n12 - Exit\n";
        cout << "Menu : " ;
        cin >> menu;
        switch(menu){
            case 1:{
                cout << "Price: " << A.PriceOfAll() << endl;
            }
            break;
            case 2:{
                cout << "The most expensive car service: ";
                A.ExpCar()->print(cout);
                cout << endl;
                cout << A.ExpCar()->servicePrice();
                cout << endl;
            }
            break;
            case 3:{
                cout << "The newest car on service: ";
                A.NewestCar()->print(cout);
                cout << endl;
            }
            break;
            case 4:{
                cout << "Cars of all brands: "<< '\n';
                A.AllBrands();
                cout << endl;
            }
            break;
            case 5:{
                int index;
                cout << "Index of car to delete: ";
                cin >> index;
                A.DeleteCar(index);
            }
            break;
            case 6:{
                int car=0;
                cout << "What car would you like to add:\n1 - Passanger car\n2 - Truck\n";
                cin >> car;
                switch(car){
                    case 1:{
                        Auto * pcar=new PasCar;
                        pcar->input(cin);
                        A.AddCar(pcar);
                    }
                    break;
                    case 2:{
                        Auto * tcar=new Truck;
                        tcar->input(cin);
                        A.AddCar(tcar);
                    }
                    break;
                }

            }
            break;
            case 7:{
                PasCar ** pasarr= new PasCar * [A.getCurN()];
                Truck ** trsarr= new Truck *[A.getCurN()];
                int pas=0,tr=0;
                A.TwoArrays(pasarr, trsarr, pas,tr);
                PrintArr(pasarr,pas);
                cout << endl;
                PrintArr(trsarr,tr);
                delete [] pasarr;
                delete [] trsarr;
            }
            break;
            case 8:{
                cout << "SORTING..." << endl;
                A.SortByBrand();
                A.print(cout);
                A.SortByMileAge();
                A.print(cout);
                A.SortByAge();
                A.print(cout);
                A.SortByWeight();
                A.print(cout);
                A.SortByEngineCap();
                A.print(cout);
                A.SortByNumOfOwners();
                A.print(cout);
                A.print(cout);
            }
            break;
            case 9:{
                fstream file;
                file.open("CompTest.txt",ios::in);
                A.ReadFromFile(file);
                file.close();
                A.print(cout);
            }
            break;
            case 10:{
                fstream file2;
                file2.open("CompTest.txt",ios::app);
                A.WriteInFile(file2);
                file2.close();
            }
            break;
            case 11:{
                A.print(cout);
            }
            break;
        }
    }
      
}

// g++ -o CompositionTest.exe CompositionTest.cpp Auto.cpp PasCar.cpp Truck.cpp AutoService.cpp && ./CompositionTest.exe