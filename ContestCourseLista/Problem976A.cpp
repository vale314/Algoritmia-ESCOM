#include <iostream>
#include <algorithm>

using namespace std;

int main (){
    int n;

    string bin;

    cin >> n;

    cin.ignore();
    getline(cin, bin);

    size_t nU = bin.find('1');
    size_t nC = count(bin.begin(), bin.end(), '0');

    string c = "";

    if(!nU)
        cout << "1";
    

    for(int i = 0; i < nC; i++){
        cout << "0";
    }

}