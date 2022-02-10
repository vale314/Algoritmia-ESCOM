#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > respuestas;
vector<int> v;

// El Algortim fue explicado en un tuto, me fue imposible realizarlo con mi conocimiento.

void solve(int k, int m)
{
    //desde el numero que vamos actual hasta que sea menor al numero dividido i/n
    for(int i = k; i * i <= m; i++)

        // si es divisible el numero m entre actual
        if(m % i == 0) {

            //agregamos v al vector
            v.push_back(i);

            //llamamos recursivamente con los nuevos valores
            solve(i, m / i);

            //elmiminamos el ultimo elmento
            v.pop_back();
        }
    
    // Agregamos el valor buscado a v
    v.push_back(m);

    // Agregamos los resultados ha respuestas
    respuestas.push_back(v);

    // Eliminamos el ultimo valor en V
    v.pop_back();
}

int main()
{
    int n;

    // mientras sea diferente de 0
    while(cin >> n, n != 0) {

        //limpiamos el vector
        respuestas.clear();

        //iniciamos en 2 porque 1 esta excluido. hasta el numero
        for(int i = 2; i * i <= n; i++)

            // si el numero busacado es divisible entre el numero actual
            if(n % i == 0) {
                
                //agregamos el numero al vector
                v.push_back(i);

                // enviamos el numero actual, y n/i
                solve(i, n / i);
                v.pop_back();
            }

        cout << respuestas.size() << '\n';

        //para cada una de las resupuestas
        for(auto a : respuestas) {
            
            // para cada respuesta tenemos el tamaño
            int sz = a.size();

            //Para cada una de los numeros de la respuesta
            for(int i = 0; i < sz; i++){
                cout << a[i];

                if(i == sz - 1)
                    cout << '\n';
                else
                    cout << ' ';
            }
        }
    }

    return 0;
}
