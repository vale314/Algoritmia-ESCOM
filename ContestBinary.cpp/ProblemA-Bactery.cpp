#include<iostream>

using namespace std;

int main()
{
    long bactBuscadas;
    
    long bacterias=0;
    
    cin>>bactBuscadas;

    // Mientras las bactBuscadas al divirse entre 2 sea diferente de 0
    while(bactBuscadas/2 !=0)
    {
        // si las bacterias buscadas son impares
        if(bactBuscadas%2)
            bacterias++;    // agregamos uno porque no puede multiplicarse x 2 y obtener ese numero

        bactBuscadas = bactBuscadas/2;  // Guardamos o actualizamos bacteriasBuscadas con /= 2
    }

    cout<<bacterias+1;

    return 0;
}