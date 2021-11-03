// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector <int> num;

class BST{

    private:

        struct Node{

            int data;
            
            Node * left;
            Node * right;

            //Constructor
            Node(){
                this->data = data;
                this->left = nullptr;
                this->right = nullptr;
            }
        };

        Node * root;
    
    public:


        BST(){
            this->root = nullptr;
        }

        //getRoot();
        Node * obtenRaiz(){
            return this->root;
        }

        Node * buscaValor (Node * raiz, int valor){

            if(raiz == nullptr) return nullptr;
            if(raiz->left == nullptr && raiz->right == nullptr) return raiz;

            if(raiz->data > valor){
                if(raiz->left == nullptr) return raiz;
                buscaValor(raiz->left, valor);
            }else if(raiz->data < valor){
                if(raiz->right == nullptr) return raiz;
                buscaValor(raiz->right, valor);
            }else{
                return raiz;
            }
            
            //return raiz; //no funcion como quiero 
        }

        // insertaValor
        void inserta (int valor){


            Node * posiblePadre = buscaValor(this->root, valor);

            Node * nuevoNodo = new Node();
            nuevoNodo->data = valor;
            

            if(posiblePadre == nullptr){
                this->root = nuevoNodo;
            }else{
                
                if(posiblePadre->data > valor){
                    posiblePadre->left = nuevoNodo;
                }else if(posiblePadre->data < valor){
                    posiblePadre->right = nuevoNodo;
                }

            }
            return;
        }

    void alt(Node* root, int peso){
        if(root == nullptr){
            num.push_back(peso);
            cout<< root->data <<endl;
            return;
        }
        alt(root->left, peso++);

        alt(root->right, peso++);
    }

    int height(Node* root) {

        cout << "hola" << endl;
        cout << root->data << endl;
        cout << root->right->data << endl;
        cout << root->left->data << endl;

        alt(root,-1);

        auto it = max_element(std::begin(num), std::end(num));

        return *it;
    }

    void preOrden (Node * raiz){
            if(raiz == nullptr) return;
            cout << raiz->data<<" ";
            preOrden(raiz->left);
            preOrden(raiz->right);
        }
};


int main(){

    BST arbolPrueba;

    arbolPrueba.inserta(4);
    arbolPrueba.inserta(2);
    arbolPrueba.inserta(6);
    arbolPrueba.inserta(1);
    arbolPrueba.inserta(3);
    arbolPrueba.inserta(5);
    arbolPrueba.inserta(7);

    arbolPrueba.preOrden(arbolPrueba.obtenRaiz());
    // cout<<arbolPrueba.height(arbolPrueba.obtenRaiz())<<endl;

    return 0;
}