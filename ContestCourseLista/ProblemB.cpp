#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//Regresar * es regresar el primer elemento del array
int * reverseArray(string s){
    vector<int> numerosInt;

    stringstream stream( s );

    int number;
    
    while ( stream >> number )
        numerosInt.push_back( number );

    // for(int i = 0; i<s.length(); i++){
    //     chars.push_back(s[i]);
    //     cout << s[i] << endl;
    // }

    vector<int>::iterator it = numerosInt.end();  

    it--;

    int n = numerosInt[0];

    int reverse[n];
    int i = 0;

    for (; it != numerosInt.begin(); it--){
        reverse[i] = *it;
        // cout << ' ' << *it;
        i++;
    }
    
    // cout<<endl;

    // for(int i = 0; i < n; i++ )
    //     cout << ' ' << reverse[i];

    return reverse;
}

int main (){

    string s;
    // vector<char> chars;
    
    getline(cin, s);

    int * reverse = reverseArray(s);

    cout << ' ' << reverse;
    reverse++;
    cout << ' ' << *reverse;
}