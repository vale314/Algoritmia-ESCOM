#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'downToZero' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
 
 // Declaramos un vector de tam Max + 6 por si acaso
 // y todos lo valores con -1
vector <int> dp(1000006, -1);

int downToZero(int n) {
    
    return dp[n];
    
    return 0;
}

void preload(){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    // EL max de (a, b) siempre va a ser i porque es el que va adelante
    
    for(int i = 0; i < 1000006; i++){
        
        // si la dp en la pos i es -1 o dp en la pos anterior + 1 es mayor a la pos act
        if(dp[i] == -1 || dp[i-1] + 1 < dp[i])
            dp[i] = dp[i - 1] + 1; // Actualizamos
        
        for(int j = 1; (j <= i) && (j * i < 1000006); j++){
            
            // si no ha sido visitado o dp[i] (el max de (a, b)) + 1 es menor dp [i * j]
            if(dp[j * i] == -1 || dp[i] + 1 < dp[i * j])
                dp[i * j] = dp[i] + 1;
        }
    }
    
}

int main()
{
    
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));
    
    preload();

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = downToZero(n);

        fout << result << "\n";
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
