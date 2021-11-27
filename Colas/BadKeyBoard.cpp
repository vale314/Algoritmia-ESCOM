#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int main(){
    
    string line;

    while(getline(std::cin, line) && line.length()){

        list<char> l;

        auto x = l.begin();

        for(int i = 0; i < line.size(); i++){
            if(line[i] == '[')
                x = l.begin(); //para que concatene al inicio
            else if(line[i] == ']')
                x = l.end(); //para que concatene al final
            else{
                x = l.insert(x,line[i]); //Concatenamos desde x hasta line[i]
                //realmente solo pasamos letra por letra
                x++; // avanzamos para que el inicio se mueva y no sobreescr.
            }
        }

        // line.erase(remove(line.begin(), line.end(), '['), line.end());
        // line.erase(remove(line.begin(), line.end(), ']'), line.end());

        // line.erase(remove(line.begin(), line.end(), 'Beiju'), line.end());

        for( char x1 : l){
            cout << x1;
        }

        cout << '\n';

    }

    return 0;
}