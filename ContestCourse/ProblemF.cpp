#include <iostream>

// 266.B.

// Valentin Ruiz

using namespace std;

int main(){
    string x;

    int n, t;

    cin >> n >> t;
    
    cin.ignore();
    getline(cin, x);

    // Mientras exista un iteracion
    while(t){

        //recorrer todo el string - 1 length
        for(int i=0; i<x.length()-1; i++){

            // si actual es 'B' y el siguiente es 'G' swap(B,G);
            if(x[i] == 'B' && x[i+1] == 'G'){
                int aux = x[i];
                x[i+1] = 'B';
                x[i] = 'G';

                //recorremos uno para que ya no lo cuente
                i++;
            }
        }
        t--;
    }

    cout << x << endl;
}