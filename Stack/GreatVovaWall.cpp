#include <iostream>
#include <stack>

using namespace std;
 
int N;
stack<int> s;
 
int main() {

    cin >> N;

    for(int i = 0; i < N; i ++) {
        int x;

        cin >> x;

        //metemos el nuevo elemento a la pila si esta vacia
        if(s.empty())
            s.push(x);
        else {
            //  Si el valor absoluto del tope de la pila su vecino tiene una
            // Diferencia s - x par
            if(abs(s.top() - x) % 2)
                s.push(x);
            
            // De lo contrario eleminamos el primero
            else s.pop();
        }
    }
 
    if(s.size() > 1) 
        cout << "NO" << "\n";
    else 
        cout << "YES" << "\n";

    return 0;
}