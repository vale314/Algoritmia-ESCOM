#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> v;

void switchCase(string s){
    if (s.compare("..") == 0 && !s.empty()){
        v.pop_back();
        return;
    }
    // cout<<s<<"\n";
    v.push_back(s);

    return;

}

void tokenize(string s, string del = " ")
{
    int start = 0;
    int end = s.find(del);
    string aux = "";
    while (end != -1) {
        aux = s.substr(start, end - start);
        switchCase(aux);
        // cout << aux << "\n";
        start = end + del.size();
        end = s.find(del, start);
    }
    
    aux = s.substr(start, end - start);
    switchCase(aux);
    // cout << aux << "\n";
}

int main(){
    int n;
    string ini;

    cin>>n;
    cin.ignore();

    for(int i = 0 ; i < n; i++){
        
        getline(cin,ini);


        if (ini.compare("pwd") == 0)
        {
            
            cout << "/";

            for (int j = 0; j < v.size(); ++j)
            {  
               cout << v[j] << "/"; 
            }
            cout << endl;
            continue;
        }
        else{
            if(ini[3] == '/'){
                v.clear();
                tokenize(ini.substr(4,ini.size()), "/");
            }else
                tokenize(ini.substr(3,ini.size()), "/");
            
        }
    }




    return 0;
}