#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <list>

using namespace std;

// #include <bits/stdc++.h>

stack < pair <int long long,int long long> > edificios_Algortihm;

int long long m = -1;



void algor(){
    cout << endl << "Eliminar todos " << endl;
            // El n_Aux de momento es igual al tope de la pila 
            int long long n_aux = edificios_Algortihm.top().first;
            int long long first = edificios_Algortihm.top().first;
            int long long second = edificios_Algortihm.top().second;

            //Este se va a remplazar por la busqueda binaria
            int long long tam_aux = edificios_Algortihm.size();

            while(!edificios_Algortihm.empty()){


                //Este se va a remplazar por la busqueda binaria
                    
                    // Todos los anteioires a el multiplicados por su altura + 1 para que no de 0
                    n_aux = first * (tam_aux - edificios_Algortihm.size() + 1);

                edificios_Algortihm.pop();

                //si el mayor actual es mayor al total, guardamos actual
                if(n_aux > m)
                    m = n_aux;

                if(!edificios_Algortihm.empty()){
                    first = edificios_Algortihm.top().first;
                    second = edificios_Algortihm.top().second;
                }
                
            }
        }


int main(){
    vector<int long long> numerosInt;

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

    // numerosInt.push_back(0);

    // stack < pair <int long long,int long long> > edificios_Algortihm;

    for(int i = 0; i < numerosInt.size() ; i++ ){
        
        // si esta vacia metemos el primero
        if(edificios_Algortihm.empty()){
            edificios_Algortihm.push(make_pair(numerosInt[0], 1));
            // cout << "empty" << endl;
            // cout << edificios_Algortihm.top().first << endl;
        }
        
        // cout << "i: " << i+1 << endl;

        // cout << "numSize: " << numerosInt.size() << endl;

        // cout << "Boolean: " << ( (i + 1) == numerosInt.size()) <<endl;


        // cout << edificios_Algortihm.top().first << " - " << numerosInt[i] << endl;
        //Si el nuevo a meter es mayor a el tope + + + Push nuevo elemento 
        if(numerosInt[i] > edificios_Algortihm.top().first || i + 1 ==  numerosInt.size()){
            edificios_Algortihm.push(make_pair(numerosInt[i],1));
            // cout << edificios_Algortihm.top().first << " - ";
            // continue;
        }else{
            // cout<<"entra" << endl;
            algor();
            continue;
        }

        if((i + 1) == numerosInt.size()){
            // cout<<"entro" << endl;
            algor();
        }
    }

    cout << "M" << endl;
    cout << m << endl;
}

