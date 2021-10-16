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

stack < pair <int long long,int long long> > edificios_Algortihm;
vector<int long long> numerosInt;

int long long m = -1;

// int menor(){

// }

void algor(){

            // El n_Aux de momento es igual al tope de la pila 
            int long long n_aux = edificios_Algortihm.top().first;
            int long long first = edificios_Algortihm.top().first;
            int long long second = edificios_Algortihm.top().second;

            //Este se va a remplazar por la busqueda binaria
            int long long tam_aux = edificios_Algortihm.size();
            
            // int long long tam_aux = edificios_Algortihm.top().second;
            
            cout<<"first: "<<first<<" second: "<<second<<endl;
            while(!edificios_Algortihm.empty()){
                

                //Este se va a remplazar por la busqueda binaria
                    
                    // Todos los anteioires a el multiplicados por su altura + 1 para que no de 0
                    n_aux = first * (tam_aux - edificios_Algortihm.size() + 1);
                    // n_aux = 

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


    edificios_Algortihm.push(make_pair(numerosInt[0], 0));

    for(int i = 1; i < numerosInt.size(); i++ ){
        
        // si esta vacia metemos el primero
        // if(edificios_Algortihm.empty())
        //     edificios_Algortihm.push(make_pair(numerosInt[i], i));

        
        //Si el nuevo a meter es mayor a el tope + + + Push nuevo elemento 
        if(numerosInt[i] > edificios_Algortihm.top().first || i ==  numerosInt.size()-1){
            
            if(i ==  numerosInt.size()-1){
                
                if(numerosInt[i] > edificios_Algortihm.top().first)
                    edificios_Algortihm.push(make_pair(numerosInt[i],i ));
                algor();
                break;
            }
            
            edificios_Algortihm.push(make_pair(numerosInt[i],i ));

        }
        else{
            cout<< edificios_Algortihm.top().first  << ' ' << numerosInt[i] << endl;
            algor();
            edificios_Algortihm.push(make_pair(numerosInt[i], i));
            cout<< edificios_Algortihm.top().first <<endl;
            continue;
        }

    }

    cout << m << endl;
}

