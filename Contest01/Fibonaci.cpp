#include <iostream>

using namespace std;

int main(){
    short n = 0;

    cin >> n;

    int dp[n];

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
       dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;

}