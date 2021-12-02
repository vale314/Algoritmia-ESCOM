#include <iostream>
#include <vector>
#include <stack>

#define io_ ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){
    io_

    string s;
    

    int i = 1;
    
    while(true){
        
        cin >> s;
        
        if(s == "end")
            return 0;

        vector <stack <char> > vectores;
        
        for(char c: s){
            
            bool find = false;

            // for(auto v: vectores){
            for(int i = 0; i < vectores.size(); i++){
                if(c == vectores[i].top()){
                    
                    find = true;

                    break;
                }

                if(c < vectores[i].top()){
                    // cout << c << " " << vectores[i].top() << endl;
                    
                    vectores[i].push(c);
                    find = true;
                    break;
                }
            }

            if(!find){
                
                stack <char> aux;
                
                aux.push(c);
                vectores.push_back(aux);
            }
            
        }

        cout << "Case " << i << ": "  << vectores.size() << endl;
        
        i++;
    }
    
}