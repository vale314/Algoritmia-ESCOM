#include <bits/stdc++.h>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */

//Function Realizada Valentin

long largestRectangle(vector<int> h) {
    int n = h.size();
        vector<int> sLeft(n, 0);
        vector<int> sRight(n, 0);
        
        
        sLeft[0] = -1, sRight[n-1] = n;
        
        //recorrer todos los edificios
        for(int i = 1; i < n; ++i){
            
            //el edificio anterior
            int idx = i-1;
            
            //mientras sea mayor a 0 y el edificio anterior sea mayor
            while(idx >= 0 && h[idx] >= h[i])
                idx = sLeft[idx];
            // idx se queda con el edificio en idx
            
            // si no guardamos en la poscion i el id del edificio
            sLeft[i] = idx;
        }
        
        //es la funcion de arriba invertida
        
        //para todos los edificios desde el final -2
        for(int i = n-2; i >= 0; --i){
            int idx = i+1;
            
            // nos quedamos con el pentultimo 
            
            while(idx < n && h[idx] >= h[i])
                idx = sRight[idx];
            sRight[i] = idx;
        }
        
        //ocupamos revisar en ambos lados IZQ -> <- DER
        // Mi algortimo inicial solo lo hacia en un sentido de ahi el error que daba unos correctos y unos incorrectos.
        
        int result = 0;
        
        // para todos los edificios desde el inicio
        for(int i = 0; i < n; ++i)
            result = max(result, h[i]*(sRight[i] - sLeft[i] - 1));
        // el resultado es el maximo de el maximo actual y la multiplicacion de la altura * el incio y fin de ese rectangulo
        return result;
};

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

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
