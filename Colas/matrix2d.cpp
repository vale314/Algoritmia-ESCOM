#include <iostream>

using namespace std;

char big[1000][1000];

char little[1000][1000];

int findSquare(int N, int n) {

    int yes = 0;

    int i, j, k, l;

    
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {

            // si la pos en fila y columa es menor al grande sumando lo ancho
            // y largo para saber si aun cabe.
            if(i+n <= N && j+n <= N) {
                int contador = 0;

                for(k = 0; k < n; k++) {
                    for(l = 0; l < n; l++) {

                        // Ahora comprobamos si cada cuadrito del little
                        // Es igual a la posicion del grande y incrementamos
                        if(big[i+k][j+l] == little[k][l])
                            contador++;
                    }
                }

                // el contador debe de ser igual a todos los cuadros
                if(contador == n*n)
                    yes++;
            }
        }
    }
    return yes;
}

void rotateSquare(int n) {

    char tmp[n][n];
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)

            // en temporal guaramos a little pero iteramos en little
            tmp[i][j] = little[n-j-1][i];
    }

    // solo cambiamos los valores en little
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
           little[i][j] = tmp[i][j];
    }
}

int main(){

    int N, n;

    cin >> N >> n;

    // string s= "";

    while(N != 0 && n != 0){
        // while(N--){
            
            // cin.ignore();
            // getline(cin, s);

            for(int i = 0; i<N; i++){
                for(int j = 0; j<N; j++){
                    cin >> big[i][j];
                }
            }
        // }

        // while(n--){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cin >> little[i][j];
                }
            }
        // }

        for(int i = 0; i < 4; i++) {
            if(i != 0)
                cout << ' ';
            
            cout << findSquare(N, n);

            rotateSquare(n);
        }
        
        cout << '\n';
        
        cin >> N >> n;
    }

    return 0;
}