#include <iostream>
using namespace std;

int main() {
    long long entradas, numChoco, numero;
    unsigned ninotriste = 0;
    
    char signo = ' ';

    // Leer numero de entradas y numero de chocolates 
    // al inicio de la reparticion de bob & eve
    cin >> entradas >> numChoco;

    // Leer todas las entradas
    for (int i = 0; i < entradas; i++) {
        // Leer el signo y numero para saber si son ninos o donador
        cin >> signo >> numero;

        // Si es donador
        if (signo == '+') {
            // Aumentamos el almacen o numero de chocolates
            numChoco += numero;
            
            // Si no pues es un nino ya no validamos el sigo '-'
            // Que el numero en almacen sea mayor a numero de choco pedidos
        } else if (numero <= numChoco) {
            numChoco -= numero;
            // Le quitamos a nuestro almacen el numero pedido de Chocolates
        } else {
            // Si no se dio lo anterior pues el nino quedo triste :(
            // Aumentamos el contador de los tristes :( (Pobresitos Jeje)
            ninotriste++;
        }
    }

    //Imprimimos el numero de los chocolates1
    cout << numChoco << " " << ninotriste;
}