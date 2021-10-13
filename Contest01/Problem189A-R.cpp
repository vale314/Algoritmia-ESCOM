#include <iostream>

// using namespace std;

// using namespace std;

// int f(int n) = 1 + max(f(n - a),  
// 			   f(n - b),  
//                f(n - c)); 

// template <class T>
// T max(T& t1, T& t2)
// {
//     return t1 < t2 ? t2 : t1;
// }

int F(int n, int a, int b, int c){
   if (n == 0)
        return 0;
    if(n < 0)
        return INT_MIN;

    int min1 = F(n-a, a, b, c);
    int min2 = F(n-b, a, b, c);
    int min3 = F(n-c, a, b, c);

   return 1 + std::max( std::max(min1,min2), min3);
}

int main(){

    int n, a, b, c; 
    
    std::cin >> n >> a >> b >> c;

    std::cout << F(n, a, b, c) << std::endl;

}