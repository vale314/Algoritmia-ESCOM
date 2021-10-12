#include <iostream>

using namespace std;

int main()
{
    int n, k, ml, l, r, g, x, y;
    cin >> n >> k >> ml >> l >> r >> g >> x >> y;
    cout << min(min(k * ml / x, l * r), g / y) / n << endl;
    return 0;
}