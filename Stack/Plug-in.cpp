#include <iostream>
#include <stack>

using namespace std;

int main(){

    string s;
    stack <char> c;

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        
        if(c.empty()){
            c.push(s[i]);
            continue;
        }
        
        if(c.top() == s[i]){
            c.pop();
            continue;
        }

        c.push(s[i]);
    }

    stack <char> i;

    while(!c.empty()){
        i.push(c.top());
        c.pop();
    }

    while(!i.empty()){
       cout << i.top();
       i.pop();
    }

    cout << "\n";

    return 0;
}