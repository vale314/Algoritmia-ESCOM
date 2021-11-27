#include <iostream>

using namespace std;

int main(){

    int k = 0;

    

    k++;

    cin >> k;

    while(k){

        int x,y;
        
        cin >> x >> y;

        while(k--){

            int xk, yk;

            cin >> xk >> yk;

            int dx=xk-x; // dx  es igual a la diferencia de la posX menos la division de x

            int dy=yk-y;    // lo mismo pero para y

            //con esto sabemos donde esta si es positivo o negativo cada valor y solo
            // hacemos los casos

            if(dx>0 && dy>0)

                cout<<"NE"<<"\n";

            else if(dx<0 && dy>0)

                cout<<"NO"<<"\n";

            else if(dx<0 && dy<0)

                cout<<"SO"<<"\n";

            else if(dx>0 && dy<0)

                cout<<"SE"<<"\n";

            else

                cout<<"divisa"<<"\n";

        }

        cin >> k;
    }

    return 0;
}