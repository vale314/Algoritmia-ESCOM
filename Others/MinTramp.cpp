#include <iostream>
#include <queue>
#define io_ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAXN = 300 + 7;

char celdas[MAXN][MAXN];
bool visitados[MAXN][MAXN];
    
int movimientos[4][2] = {{0, 1}, {0, -1}, 
                         {1, 0}, {-1, 0}};

// first = trampas
// second.first = x
// second.second = y
typedef pair<int, pair<int,int>> estado;

int BusquedaDePrioridad(int inicial_x, int inicial_y, int n, int m){
    priority_queue<estado> pq;
    pq.push({0, {inicial_x, inicial_y}});

    while(!pq.empty()){

        int trampas = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        visitados[x][y] = true;

        pq.pop();

        for(int i = 0 ; i < 4 ; i++){
            
            int movx = movimientos[i][0];
            int movy = movimientos[i][1];

            if(x+movx < 0 || x+movx >= n || y+movy < 0 || y+movy >= m ) continue;

            if(visitados[x + movx][y + movy] || celdas[x + movx][y + movy] == '#') continue;

            if(celdas[x + movx][y + movy] == 'S') return -trampas;

            if(celdas[x + movx][y + movy] == 'X'){
                pq.push({trampas - 1,{x + movx, y + movy}});
            }else{
                pq.push({trampas,{x + movx, y + movy}});
            }
        }
    }
    return -1;
}

int main (){
    io_
    // Inicio de Lectura 
    int n, m;
    cin >> n >> m;

    int inicial_x, inicial_y;
    cin >> inicial_x >> inicial_y;

    if(n == 0 || m == 0){
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            visitados[i][j] = false;
            cin >> celdas[i][j];
        }
    }
    // Fin de Lectura
    
    cout << BusquedaDePrioridad(inicial_x, inicial_y, n, m) << "\n";
    return 0;
}