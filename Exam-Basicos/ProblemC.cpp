#include <iostream>

using namespace std;

int main()
{   
    // La explicacion esta en mi hojita :D

    int n;
    cin >> n;
    
    // Si es modulo 2, 0 o mejor dicho numero par
    if (n % 2 == 0){
        // si un numero mayor a 2, porque si es 1 no se puede
        if( n > 2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}