#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#define io_ ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){
    
    io_
    
    int n;

    cin>> n;

    vector<int> numerosInt;
    
    int i = 0;
    
    while(n){
        string s;
        
        cin.ignore();
        getline(cin,s);

        stringstream stream( s );

        int number = 0;
        int max = 0;

        while ( stream >> number ){
            // numerosInt.push_back( number );
            if (i>=1 && max < number){
                max = number; 
            }
            // cout << number << " ";
            i++;
        }

        // cout << *max_element(numerosInt.begin(), numerosInt.end()) << "\n";

        cout << max << '\n';

        // numerosInt.clear();

        n--;
    }

}