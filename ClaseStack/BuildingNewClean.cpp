#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <list>

// #include <bits/stdc++.h>
#define io_ ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

//Stack, guardamos Valor, Poscicion de vector
stack < pair <long long int ,long long int> > edificios_Algortihm;
vector<long long int> numerosInt;
// long long int numerosInt[9999999];

long long int m = -1;

long long int menor(long long int j, long long int actual){
    
    //Regrersamos cantidad de numeros menores contiguos

    long long int k = 0;

    for(long long int i = j; i >= 0 ; i--){

        if(numerosInt[i] >= actual)
            k++;
        else
            break;
    }
    return k;
}

void drop(){

    //eliminar todos los elementos
    while(!edificios_Algortihm.empty()){
        edificios_Algortihm.pop();
    }
}

void algor(){
    
    long long int n_aux = edificios_Algortihm.top().first;
    long long int first = edificios_Algortihm.top().first;
    long long int second = edificios_Algortihm.top().second;

    while(!edificios_Algortihm.empty()){
        n_aux = edificios_Algortihm.top().first;
        
        first = edificios_Algortihm.top().first;
        second = edificios_Algortihm.top().second;

            long long int mult = 0;

            //si la pila tiene mas de 1 elem. nos quedamos con el valor anterior y posicion actual

            if(edificios_Algortihm.size()>1){
                edificios_Algortihm.pop();
                first = edificios_Algortihm.top().first;
            }
            
            // multiplicamos elemento actual * cantidad de veces encontrados menores o igual contiguos.
            mult = first * menor(second, first);

            //si la multiplicacion es mayor al edificio actual cambiamos
            if(mult > n_aux)
                n_aux = mult;
            
            //si aux es mayor a el maximo de ataque 
            if(n_aux > m)
                m = n_aux;

        drop();
    }

}

int main(){
    io_

    string s= "";

    long long int n;

    cin >> n;

    cin.ignore();

    getline(cin, s);

    stringstream stream( s );

    long long int number;
    
    while ( stream >> number )
        numerosInt.push_back( number );
    
    if(!numerosInt.size()){
        cout << "0" << endl;
        return 0;
    }

    //Agregamos un elemento extra para comprobar el ultimo elemento
    numerosInt.push_back(0);
    edificios_Algortihm.push(make_pair(numerosInt[0], 0));

     for(long long int i = 1; i < numerosInt.size(); i++ ){
         
         //si el nuevo a meter es menor al tope
         if(numerosInt[i] < edificios_Algortihm.top().first ){
            
             algor();
         }
        if(numerosInt[i] != 0)
            edificios_Algortihm.push(make_pair(numerosInt[i], i));
     }

    cout << m << endl;
}