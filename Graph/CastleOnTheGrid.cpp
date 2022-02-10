#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */
 
vector<pair<int,int>> dir = {
    {-1, 0}, // movimiento en x hacia arriba
    {1, 0},     // movimiento en x hacia abajo
    {0, -1},    // movimiento en y hacia la izq
    {0, 1},     // movimiento en y hacia la der
};


map < pair<int, int>, pair<int, int> > mapa;

int lines, cols;

// que el movimiento sea valido y no se salga de los limites
bool isValid(pair<int,int> pos){
    if(pos.first < 0 || pos.first >= lines)
        return false;
    if(pos.second < 0 || pos.second >= cols)
        return false;
    return true;
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    lines = grid.size();
    cols = grid[0].size();
    
    // un mapa de visitados (x,y), visiatado (bool)
    map<pair<int,int>, bool> visited;
    
    //una cola con los nodos a visitar proximos
    queue<pair<int,int>> q;
    
    pair <int, int> inicio = {startX, startY};
    
    //el primer nodo es visitado y agregado a la cola
    visited[inicio] = true;
    q.push(inicio);
    
    mapa.insert({inicio,{-1,-1}});
    
    pair <int, int> destino = {goalX, goalY};
    
    // for(int i = 0; i < lines; i++){
    //     for(int j = 0; j < cols; j++)
    //         cout <<grid[i][j];
    //     cout << "\n";
    // }
    
    //mientras la cola no este vacia
    while(!q.empty()){
        
        //sacamos el primer elemento de la cola
        auto ahora = q.front();
        
        //eliminamos el primer elemento de la cola
        q.pop();
        
        
        // El nodo que se esta visitando
        // cout << ahora.first << ", " << ahora.second << endl;;
        
        if(ahora == destino){
            cout << "ya llegue!" << endl;
            break;
        }
        
        // Para cada posible movimiento 
        for(auto d:dir){
            
            // vecino toma el actual porque se movera con cada movimiento
            auto vecino = ahora;
            
            // se mueve en x y se mueve en y
            vecino.first += d.first;
            vecino.second += d.second;
            
            // preguntamos si el vecino tomo una posicion valida, si no ha sido visitado
            
            // ademas si el vecino no es un muro "#"
            if(isValid(vecino) && !visited[vecino] && grid[vecino.second][vecino.first]!= 'X'){
                //marcamos como visitado al vecino y lo encolamos
                // cout << " = " << grid[vecino.second][vecino.first] << endl;;
                
                visited[vecino] = true;
                mapa.insert({vecino, ahora});
                q.push(vecino);
            }
        }
    }
    
    
    vector < pair<int,int> > aux;
    // aux.push_back(destino);
    
    auto it = mapa.find(destino);
    
    // cout << it->first.first << "," << it->first.second << " - " << it->second.first << "," <<               it->second.second << "\n";
    
    // Si el actual es diferente al origen
    while(true){
        
        // cout << it->first.first <<" , "<< it->first.second << "\n";
        // //metelos a la arreglo el anterior o quien nos metio
        aux.push_back({it->first});
        
        // // it ahora es quien me metio
        if(it->first == inicio)
            break;
            
        it = mapa.find(it->second);
    }
    
    
    reverse(aux.begin(), aux.end());
    
    int count = 0;
    
    bool vuelta = false;
    
    for(int i = aux.size()-1; i>= 0; i--){

        if((aux[i].first == aux[i-1].first || aux[i].second == aux[i-1].second) && !false){
            count++;
            vuelta = true;
        }
        else {
            vuelta = false;
        }
        cout << aux[i].first <<" , " << aux[i].second << "\n";
    }
    
    // for(auto it = mapa.cbegin(); it != mapa.cend(); ++it)
    // {
    //     cout << it->first.first << "," << it->first.second << " - " << it->second.first << "," <<               it->second.second << "\n";
    // }
    cout << count << "\n";
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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
