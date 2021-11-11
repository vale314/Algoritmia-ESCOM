#include <queue>
#include <iostream>

using namespace std;

int main() {
	int n, x;
	queue<int> cartasM;

	while (true){
	    
	    cin >> n;
	    
	    // si es 0 se acaba
	    if(!n)
	        return 0;
	   
	   //inicilizamos las cartas en secuencia hasta n.
		for (int i = 1; i <= n; i++) {
			cartasM.push(i);
		}
        
        //imprimimos como quedaron
		cout << "Discarded cards:";
		
		//realizamos la iteracion hasta que solo nos quede una carta o mientras tengamos mas de una
		while (cartasM.size() > 1) {
		    
		    //imprimimos la del frente
		    cout << " " << cartasM.front();
			
			//eliminamos el frente y la segunda la eliminamos y la mandamos al fondo
			cartasM.pop();
			x = cartasM.front();
			cartasM.pop();
			
			//si el mazo no esta vacio imprimimos la coma
			if (!cartasM.empty())
				cout << ",";
			
			// lo de la linea 32
			cartasM.push(x);
		}
		
		//imprimimos la carta que nos quedo y eliminamos la carta para la nueva iteracion
		cout << '\n' << "Remaining card: " << cartasM.front() << '\n';
		cartasM.pop();
	}

	return 0;
}