#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n = 0;

    cin >> n;

    int x1, x2, x3;

    // creamos una priority quee min-heap // quitamos el primero y mostramos
    // luego eliminamos todo.
    priority_queue <int, vector<int>, greater<int> > v;

    for(int i = 1; i <= n; i++){
        
        cin >> x1 >> x2 >> x3;

        v.push(x1);
        v.push(x2);
        v.push(x3);

        v.pop();

        cout <<"Case " << i <<": " << v.top() << '\n';

        while( !v.empty() ){
            v.pop();
        }
    }
}