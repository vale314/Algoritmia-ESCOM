#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <list>
#define io_ ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

// #include <bits/stdc++.h>

//Stack, guardamos Valor, Poscicion de vector
stack < pair <int long long,int long long> > edificios_Algortihm;
vector<int long long> numerosInt;

int long long m = -1;

int long long menor(int long long j, int long long actual){
    
    //Regrersamos cantidad de numeros menores contiguos

    int long long k = 0;

    for(int long long i = j-1; i >= 0 ; i--){

        if(numerosInt[i] >= actual)
            k++;
        else
            break;
    }
    return k+1;
}

void drop(){

    //eliminar todos los elementos
    while(!edificios_Algortihm.empty()){
        edificios_Algortihm.pop();
    }
}

int algor(){
    
    int long long n_aux = edificios_Algortihm.top().first;
    int long long first = edificios_Algortihm.top().first;
    int long long second = edificios_Algortihm.top().second;

    while(!edificios_Algortihm.empty()){
        n_aux = edificios_Algortihm.top().first;
        
        first = edificios_Algortihm.top().first;
        second = edificios_Algortihm.top().second;

        /**
         *  Pruebas
         *  **/
            int long long mult = 0;

            //si la pila tiene mas de 1 elem. nos quedamos con el valor anterior y posicion actual
            // cout<<"first: "<<first<<" second: "<<second<<endl;
            if(edificios_Algortihm.size()>1){
                edificios_Algortihm.pop();
                first = edificios_Algortihm.top().first;
            }
            // cout<<"menores a: "<< first << " Cantidad: " << menor(second, first)<<endl;
            
            // multiplicamos elemento actual * cantidad de veces encontrados menores o igual contiguos.
            mult = first * menor(second, first);

            //si la multiplicacion es mayor al edificio actual cambiamos
            if(mult > n_aux)
                n_aux = mult;
            
            //si aux es mayor a el maximo de ataque 
            if(n_aux > m)
                m = n_aux;

        /**
         * Fin-Pruebas
         * **/

        // cout<<"first: "<<first<<" second: "<<second<<endl;
        // cout<<"menores a: "<< first << " Cantidad: " << menor(second, first)<<endl;

        drop();
    }
    return 0;
}

int main(){
    io_

    string s= "";

    int long long n;

    cin >> n;

    cin.ignore();

    getline(cin, s);

    stringstream stream( s );

    int long long number;
    
    while ( stream >> number )
        numerosInt.push_back( number );
    
    if(!numerosInt.size()){
        cout << "0" << endl;
        return 0;
    }

    //Agregamos un elemento extra para comprobar el ultimo elemento
    numerosInt.push_back(0);
    edificios_Algortihm.push(make_pair(numerosInt[0], 0));

     for(int long long i = 1; i < numerosInt.size(); i++ ){
         
         //si el nuevo a meter es menor al tope
         if(numerosInt[i] < edificios_Algortihm.top().first ){
            //  cout<< edificios_Algortihm.top().first  << ' ' << numerosInt[i] << endl;
             algor();
         }
        if(numerosInt[i] != 0)
            edificios_Algortihm.push(make_pair(numerosInt[i], i));
     }

    //  cout<<endl<<endl<<m<<endl;

    cout << m << endl;
}