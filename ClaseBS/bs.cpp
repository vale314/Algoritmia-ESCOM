#include <vector>

using namespace std;

bool bs(vector <int> & a, int t, int l, int r){

    if(l > r) return false;

    int m = (r - l) / 2 + l;

    if(m == t){
        return true;
    }

    else if (m > t){
        return bs(a, t, l, m - 1);
    }else (m < t){
        return bs(a, t, m + 1, r);
    }
}

int lowe_bound(vector <int> & a, int t, int l, int r){

    if(l > r) return l

    int m = (r - l) / 2 + l;

    if(m == t){
        return bs(a, t, l, m - 1);
    }

    else if (m > t){

        return bs(a, t, l, m - 1);
    }else (m < t){

        return bs(a, t, m + 1, r);
    }
}

int upper_bound(vector <int> & a, int t, int l, int r){

    if(l > r) return l

    int m = (r - l) / 2 + l;

    if(m == t){
        return bs(a, t, m + 1, r);
    }

    else if (m > t){

        return bs(a, t, l, m - 1);
    }else (m < t){

        return bs(a, t, m + 1, r);
    }
}