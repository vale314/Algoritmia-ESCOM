#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING expression as parameter.
 */

// https://www.hackerrank.com/challenges/ctci-balanced-brackets/problem

string isBalanced(string expression) {
    
    stack <char> br;
    
    for(int i = 0; i<expression.size(); i++){
        
        char actual = expression[i];
        
        if(actual == '{' || actual == '[' || actual == '('){
            br.push(actual);
            // cout << actual << endl;
            continue;
        }
        
        if(br.empty())
            return ("NO");
        char top = br.top();
        
        // cout << actual << " " << top << endl; 
        if(actual == ')' && top == '('){
            br.pop();
            continue;
        }
        
        if(actual == ']' && top == '['){
            br.pop();
            continue;
        }
        
        if(actual == '}' && top == '{'){
            br.pop();
            continue;
        }
        
        return ("NO");
    }
    
    if(br.empty())
        return("YES");
    else
        return ("NO");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);

        string res = isBalanced(expression);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
