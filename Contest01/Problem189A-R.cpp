#include <iostream>

using namespace std;

// int f(int n) = 1 + max(f(n - a),  
// 			   f(n - b),  
//                f(n - c)); 

int F(int n, int a, int b, int c){
   if (n = 0)
        return 0;

   return( 1 + max( max((F(n-a, a, b, c), F(n-b, a, b, c))), F(n-c, a, b, c)));
}

int main(){

    int n, a, b, c; 
    
    cin >> n >> a >> b >> c;

    F(n, a, b, c);

}