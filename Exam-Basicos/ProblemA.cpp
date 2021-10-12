#include <iostream>
#include <algorithm>

using namespace std;

int main (){
    int n, k, ml, l, r, g , x, y, x1, x2, x3, min1;

    cin >> n >> k >> ml >> l >> r >> g >> x >> y;

    x1 = (k * ml) / x;

    x2 = (l * r);

    x3 = (g/y);

    min1 = min(x1,x2);

    min1 = min(min1, x3);

    cout << min1/n <<endl;

    return 0;
}