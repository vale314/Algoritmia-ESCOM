using namespace std;
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class BST{

    private:

        struct miNodo{

            int valor;
            
            miNodo * izquierda;
            miNodo * derecha;

            //Constructor
            miNodo(){
                this->valor = valor;
                this->izquierda = nullptr;
                this->derecha = nullptr;
            }
        };

        miNodo * raiz;
    
    public:


        BST(){
            this->raiz = nullptr;
        }

        //getRoot();
        miNodo * obtenRaiz(){
            return this->raiz;
        }

        miNodo * buscaValor (miNodo * raiz, int valor){

            if(raiz == nullptr) return nullptr;
            if(raiz->izquierda == nullptr && raiz->derecha == nullptr) return raiz;

            if(raiz->valor > valor){
                if(raiz->izquierda == nullptr) return raiz;
                buscaValor(raiz->izquierda, valor);
            }else if(raiz->valor < valor){
                if(raiz->derecha == nullptr) return raiz;
                buscaValor(raiz->derecha, valor);
            }else{
                return raiz;
            }
            
            //return raiz; //no funcion como quiero 
        }

        // insertaValor
        void inserta (int valor){


            miNodo * posiblePadre = buscaValor(this->raiz, valor);

            miNodo * nuevoNodo = new miNodo();
            nuevoNodo->valor = valor;
            

            if(posiblePadre == nullptr){
                this->raiz = nuevoNodo;
            }else{
                
                if(posiblePadre->valor > valor){
                    posiblePadre->izquierda = nuevoNodo;
                }else if(posiblePadre->valor < valor){
                    posiblePadre->derecha = nuevoNodo;
                }

            }
            return;
        }

        void preOrden (miNodo * raiz){
            if(raiz == nullptr) return;
            cout << raiz->valor<<" ";
            preOrden(raiz->izquierda);
            preOrden(raiz->derecha);
        }
};


int main(){

    BST arbolPrueba;

    arbolPrueba.inserta(21);
    arbolPrueba.inserta(13);
    arbolPrueba.inserta(18);
    arbolPrueba.inserta(10);
    arbolPrueba.inserta(33);
    arbolPrueba.inserta(25);
    arbolPrueba.inserta(40);
    //arbolPrueba.inserta();

    arbolPrueba.preOrden(arbolPrueba.obtenRaiz());
    cout <<"\n";

    return 0;
}