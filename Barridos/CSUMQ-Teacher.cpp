#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, q, x;
    
    cin >> n;
    
    vector <int> arr(0);

    for(int i=0; i<n; i++){
        cin >> x;

        arr.push_back(x);
    }

    vector <int> prefixSum(n+1, 0);

    for(int i=1; i<n; i++){
        prefixSum[i] = arr[i-1]+prefixSum[i-2]; 
    }

    for(int i=1; i<n; i++){
        cout << prefixSum[i] << " - ";
    }

    cout << '\n';

    cin >> q;
    int i, j;

    while(q--){
        cin >> i >> j;
        cout << (prefixSum[j] - prefixSum[i-1])<<'\n';
    }

    return 0;
}