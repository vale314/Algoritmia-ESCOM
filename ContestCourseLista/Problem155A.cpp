#include <iostream>
#include <sstream>
#include <vector>

// Valentin Ruiz

// Problem 155.A.

using namespace std;

int main(){
    // vector<short> numerosshort;
    string s;
    short n;
    short i = 0;
    short increible = 0;

    short minimo ,maximo;

    cin >> n;
    
    cin.ignore();
    getline(cin, s);

    stringstream stream( s );

    short number;

    // Lo hacemos al insertar para no guardar nada.

    //capturamos los numeros del stream a number
    while ( stream >> number ){
       // Solo para el inicio guardamos el numero en ambos pues no hay menor ni mayor, lo comenta el mismo problema
        if(i==0){
            minimo = number;
            maximo = number;
        }
        
        // si es menor el nuevo al menor guardado - aumentamos y cambiamos
        if(number < minimo){
            minimo = number;
            increible++;
        }

        // si es menor el nuevo al mayor a guardado - aumentamos y cambiamos
        if(number > maximo){
            maximo = number;
            increible++;
        }
        
        // numerosshort.push_back( number );
        i++;
    }

    // for(short i = 0; i<n; i++){
    //     cout<<numerosshort[i]<< " ";
    // }

    cout<<increible<<endl;
}