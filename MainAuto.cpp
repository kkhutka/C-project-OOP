#include"Auto.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    int numc; 
    cout << "How many cars would you like to add? ";
    cin >>numc;
    Auto *cararr= new Auto[numc];
    int m;
    cout << "1 - read from console\n3 - Demonstrate constructors\n";
    cin >> m;
    switch(m){
        case 1:{
            for (int i=0; i<numc;i++){
                cararr[i].input();
            }
        }
        break;
        case 3:{
            for(int i=0; i<numc; i++){
                cout << "Which construrctor? " << endl;
                int constructor;
                cin >> constructor;
                switch(constructor){
                    case 1:{
                        cararr[i]=Auto();
                    }
                    break;
                    case 2:{
                        previous *arrim=new  previous [1];
                        arrim[0].name="Samuel";
                        arrim[0].year=2016;
                        cararr[i]=Auto("BMW X5", 20000,6,1000,4.7,1,arrim);
                        delete [] arrim;
                    }
                    break;
                    case 3:{
                        int copyCar;
                        cout << "Which car to copy?";
                        cin >> copyCar;
                        cararr[i]=Auto(cararr[copyCar]);
                    }
                    break;
                }
            }
        }
        break;
    }
    int menu=-1;
    int carnumb=0;
    while(menu!=0){
        cout << "-------------------MENU-------------------"<< endl;
        cout << "1 - Get brand\n2 - Get mileage\n3 - Get age\n4 - Get weight\n5 - Ger engine capacity\n6 - Get previous owners\n7 - Set brand\n8 - Set mileage\n9 - Set age\n10 - Set weight\n11 - Ser engine capacity\n12 - Add previous owners\n13 - Find out the price of service\n14 - Required times of service\n15 - Choose other car\n16 - Print in console\n17 - Print in file\n0 - Exit\nChoose: ";
        cin >> menu;
        switch (menu){
        case 1:{
            cout << cararr[carnumb].getBrand()<< endl;
        }
        break;
        case 2:{
            cout << cararr[carnumb].getMileage()<< endl;
        }
        break;
        case 3:{
            cout << cararr[carnumb].getAge()<< endl;
        }
        break;
        case 4:{
            cout << cararr[carnumb].getWeight()<< endl;
        }
        break;
        case 5:{
            cout << cararr[carnumb].getEngineCap()<< endl;
        }   
        break;
        case 6:{
            previous * arrOfOwners;
            arrOfOwners=cararr[carnumb].getOwners();
            for(int i=0; i<cararr[carnumb].getN(); i++){
                    cout << "Name: " << arrOfOwners[i].name << endl;
                    cout << "Year: " << arrOfOwners[i].year << endl;
            }
        }   
        break;
        case 7:{
            string _brand;
            cout << "Enter new brand: ";
            cin >> _brand;
            cararr[carnumb].setBrand(_brand);
        }
            break;
        case 8:{
            unsigned int _mileage;
            cout << "Enter new mileage: ";
            cin >> _mileage;
            cararr[carnumb].setMileage(_mileage);
        }
        break;
        case 9:{
            int _age;
            cout << "Enter new age: ";
            cin >> _age;
            cararr[carnumb].setAge(_age);
        }
            break;
        case 10:{
            int _weight;
            cout << "Enter new weight: ";
            cin >> _weight;
            cararr[carnumb].setWeight(_weight);
        }
        break;
        case 11:{
            float _engineCap;
            cout << "Enter new engine capacity: ";
            cin >> _engineCap;
            cararr[carnumb].setEngineCap(_engineCap);
        }
        break;
        case 12:{
            int num;
            cout << "How many new owners are there? : ";
            cin >> num;
            cararr[carnumb].setOwners(num);

        }
        break;
        case 13:{
            cout << "Service price is " << cararr[carnumb].servicePrice()<< endl;
        }
        break;
        case 14:{
            cout << "Required quantity of service appointments is " << cararr[carnumb].serviceTimes()<< endl;
        }
        break;
        case 15:{
            cout << "Choose car "; cin >> carnumb;
        }
        break;
        case 16:{
            for (int i=0; i<numc; i++){
                cararr[i].print(cout);
                cout << endl;
            }
        }
        break;
        case 17:{
            ofstream file;
            file.open("AutoOUT.txt");
            for (int i=0; i<numc; i++){
                cararr[i].print(file);
                
            }
            file.close();
        }
        default:
            break;
        }
    }
    delete [] cararr;
    
}

//  g++ -o MainAuto.exe MainAuto.cpp Auto.cpp
//  ./MainAuto.exe