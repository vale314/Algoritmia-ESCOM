#include <iostream>
#include <string>
#include <vector>
#include <sstream>


// https://leetcode.com/problems/sliding-window-maximum/

using namespace std;

int main(){
    vector<int> numerosInt;

    string s;

    getline(cin, s);

    stringstream stream( s );

    int number;
    
    while ( stream >> number )
        numerosInt.push_back( number );

    int k = 0;

    

    for (int i = 0; i<numerosInt.size(); i++){
        if()
    }

    // for(int i = 0; i<numerosInt.size(); i++){
    //     cout << numerosInt[i] << endl;
    // }
}