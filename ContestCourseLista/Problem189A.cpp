#include <iostream>

using namespace std;

int main(){

    int n, a, b, c; 
    
    cin >> n >> a >> b >> c;

    int dp[n+1];

    for(int i = 0 ; i <= n; i++){
        dp[i] = -1;
    }

    dp[0] = 0;

    for(int i=1; i<=n; i++){
        
        int case1, case2, case3;

        case1 =  case2 = case3 = INT_MIN; // Con -999 no pasa. INT_MIN el menor numero permitido para INT.

        // cout << case1 << case2 << case3 <<endl;
    
        // Si el trozo de hilo de tam: i (en ese momento), puede ser cortado en a
        if(i >= a)
            case1 = dp[i-a]; 
        if(i >= b)
            case2 = dp[i-b];
        if(i >= c)
            case3 = dp[i-c];

        // Si cae en el caso que nuestro trozo sea mas grande que nuestros posibles cortes
        // nos vamos a tamano actual - tamano de corte y obtenemos la cantidad de
        // cortes en dicha posicion

        dp[i] = 1 + max(case1,max(case2,case3));
    }
    
    if(dp[n] != -1)
        cout << dp[n] << endl;

}