#include <bits/stdc++.h>
#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY queries
 */

vector<int> solve(vector<int> arr, vector<int> queries) {
    
    vector <int> all;
    
    for(int q:queries){
        
        int a = 0;
        int b = 0;
        
        b=a+q;
        multiset <int, greater <int> > multis;       
        
        multiset <int, greater <int> > multismenor; 
        
        // multiset <int, greater <int> > :: iterator itr;
        
        for(int i=a; i < b; i++){
            multis.insert(arr[i]);
        }
        
        // cout << "q: " << q << "\n";
        
        // cout << *multis.begin() << "\n";
        
        multismenor.insert(*multis.begin());
        
        b--;
        while(b < arr.size()-1){
            a++;
            b++;
            
            // cout << arr[b] << " - ";
            
            int search = arr[a-1];
            
            const bool is_in = multis.find(search) != multis.end();
            
            if(is_in){
                auto it = multis.find(search);
                // cout << "Find: " << *it << "\n";
                multis.erase(it);
            }
            
            if(q == 1)
                multis.insert(arr[a]);
            else{
                // cout << "b: " << b << " bpush: " << arr[b] << "\n";
                multis.insert(arr[b]);
            }
            // cout << *multis.begin() << "\n";
            multismenor.insert(*multis.begin());
        }
        // cout << "\n";
        
        // cout << "resultados: " << *multismenor.rbegin() << "\n";
        all.push_back(*multismenor.rbegin());
    }
    
    
    
    return all;
}

int main()
{
    _io
    
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = solve(arr, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
