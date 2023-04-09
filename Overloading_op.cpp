#include"Auto.h"
#include<iostream>
#include<fstream>

using namespace std;

void SortArr(Auto *&arr, int n);
void PrintArr(Auto *arr, int n);
Auto * FindObj(Auto *arr, Auto a, Auto b, int n, int &j);

int main()
{
    Auto *cararr= new Auto[5];
    Auto A=cararr[0]=cararr[1]=cararr[2];
    // cout << A << cararr[0] << cararr[1] << cararr[2];
    A=A;
    Auto B=A;
    cout << A;
    ifstream file;
    file.open("AutoIN.txt");
    for (int i=0; i<5; i++){   
        file >> cararr[i];
    }
    file.close();
    cout << "Unsorted array" << endl;
    PrintArr(cararr,5);

    cout << "Bugatti==Bugatti ? " << endl;
    if(cararr[0]==cararr[0]){
        cout << "YES"<< endl;;
    }

    cout << "GMC!=Mercedes?" << endl;
    if(cararr[1]!=cararr[2]){
        cout << "YES" << endl;
    }

    cout << "Audi < Bugatti ?" << endl;
    if (cararr[3]<cararr[4])
    {
        cout << "YES" << endl;
    }

    cout << "Audi > Bugatti ?" << endl;
    if (cararr[3]>cararr[4])
    {
        cout << "NO" << endl;
    }
    
    cout << "Mercedes == Mercedes?" << endl;
    cararr[1]=cararr[2];
     if(cararr[1]==cararr[2]){
        cout << "YES" << endl;
    }else{
        cout <<"NO" << endl;
    }
    
    // cout << "Before increment" << endl;
    // cout << cararr[0].getMileage() << endl;
    // cout<< cararr[0];
    // Auto C=cararr[0]++;
    // cout << C << cararr[0];
    // cout << endl;
    // cout<< cararr[1];
    // Auto D=++cararr[1];
    // cout << D << cararr[1];
    // cout << "After increment" << endl;
    // cout << cararr[0].getMileage() << endl;

    SortArr(cararr,5);
    cout << "Sorted array" << endl;
    PrintArr(cararr,5);

    cout << "Find objects" << endl;
    Auto * FoundCars;
    int j=0;
    FoundCars=FindObj(cararr,cararr[0],cararr[4],5,j);
    PrintArr(FoundCars,j);
    
    cout << "String Object" << endl;
    cout << string(cararr[0]);
    delete [] cararr;
}


void SortArr(Auto *&arr, int n)
{
    for (int i=0; i<n-1; i++) {
        int min=i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[min]){min = j;}
        }
        swap(arr[min], arr[i]);
    }
}

void PrintArr(Auto *arr, int n)
{
    for (int i=0; i<n; i++){
        cout << arr[i] << endl;
        cout << endl;
    }
}

Auto * FindObj(Auto *arr, Auto a, Auto b, int n, int &j)
{
    Auto *array=new Auto[n-2];
    Auto min,max;
    if(a>b){max=a; min=b;}
    else if(a<b){max=b; min=a;}
    for (int i=0; i<n; i++){
        if(arr[i]>min && arr[i]<max){
            array[j]=arr[i];
            j++;
        }
    }
    return array;
}

// g++ -o Overloading_op.exe Overloading_op.cpp Auto.cpp && ./Overloading_op.exe
