#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(vector<int>& nums, int k) {
    
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }

    cout << '\n';

    return nums;
}

int main(){

    vector <int> nums;

    int k, n, aux;

    cin >> n;

    while(n--){
        cin >> aux;

        nums.push_back(aux);
    }

    cin >> k;

    solve(nums, k);

    return 0;
}