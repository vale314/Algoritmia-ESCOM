#include <iostream>

// 266.A.

// Valentin Ruiz

using namespace std;

int main(){
    string x;

    short n;

    cin >> n;
    
    cin.ignore();
    getline(cin, x);


    short aux = 0;

        //recorrer todo el string - 1 length
        for(short i=0; i<x.length()-1; i++){

            // si actual es IGUAL y al siguiente sumamos 1.
            if(x[i] == x[i+1])
                aux++;
            
        }


    cout << aux << endl;
}