#include <iostream>

using namespace std;

#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define endl "\n"

void solve(){
    int l = 0, r = 0, lim, res = 1;
    int prefSum;
    cin>>lim;
    while (r != lim) {
        prefSum = ((r*(r+1))-(l*(l-1)))/2;
        if (prefSum == lim) { 
           res++;
           r++;
       } else if (prefSum < lim)
           r++;
       else 
           l++;
    }
    cout<<res<<endl;

}

int main() { _io
    solve();
    return 0;
}