#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    stack<int> pila1 ,pila2;
    int Q;
    
    cin >> Q;
    
    while(Q--){
        
        int x1, x2;
        
        cin >> x1;
        
        if(x1 == 1)
        {
            //Encolar el elemento
            cin >> x2;
            pila2.push(x2);
        }else{
            
            // Si es otra operacion difenete a insertar 
            // Enviamos todo la pila1 y queda lista en pues
            // Aunque metamos mas elementos a pila2 no se modifica el orden de pila1
            
            if(pila1.empty()){ 
               
               while(!pila2.empty())
               {
                   pila1.push(pila2.top());
                   pila2.pop();
               }   
            }
            
            if(!pila1.empty()){
                if(x1 == 2) pila1.pop();
                if(x1 == 3) cout << pila1.top() << endl;
            }    
        }
    }
    
    return 0;
}


// https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
// Valentin Ruiz

