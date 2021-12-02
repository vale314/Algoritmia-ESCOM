#include <bits/stdc++.h>

using namespace std;

bool used[27 + 13];

void solve(vector<string>& permutations, const string s, string& temp, int i){
    if(i == s.size()){
        permutations.push_back(temp);
        return; 
    }
    for(int j = 0 ; j < s.size(); j ++){
        if(used[s[j]-'a']) continue;
        used[s[j]-'a']=true;
        temp.push_back(s[j]);
        solve(permutations, s, temp, i+1);
        temp.pop_back();
        used[s[j]-'a']=false;
    }
    return;
}
int main(){
    string s;
    cin >> s;
    vector<string> permutations;
    string temp = "";
    memset(used, false, sizeof(used));
    solve(permutations, s, temp, 0);
    for(int i = 0; i < permutations.size(); i++){
        cout << permutations[i] << "\n";
    }
}