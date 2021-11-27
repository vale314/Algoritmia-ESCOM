#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){


    int n, k, m, valor;

    char c;
    
    // vector< pair <char, int> > v;

    // vector <string> v3;

    string s;

    int chars[255];

    int cc[255];

    cin >> n;

    while(n--){

        cin >> k;

        for(int i=0; i<255; i++){
            chars[i]=0;
            cc[i]=0;
        }

        while(k--){
            cin >> c >> valor;

            // v.push_back(make_pair(c, valor));

            chars[(int)c] = valor;
        }

        cin >> m;

        cin.ignore();
        while(m--){
            
            getline(cin, s);

            for(int i = 0; i < s.size(); i++)
                cc[(int)s[i]]++;
            

            // v3.push_back(s);

        }
        int suma = 0;
         
        for(int i=0;i<255;i++){
            suma+=chars[i]*cc[i];
        }
        double su = suma;
        double pre = 0;

        pre = su/100;


        printf("%0.2f$\n",pre);

        //algoritmo
    }



    return 0;
}