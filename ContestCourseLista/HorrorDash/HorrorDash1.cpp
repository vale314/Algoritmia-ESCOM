#include <iostream>
#define io_ ios_base :: sync_with_stdio(0);cin.tie(0);

// Valentin Ruiz

using namespace std;

int main() {

	// No se como jala pero MegaCharles Dijo XD
	
	io_ 

	int t, n, Case = 0;
	
	//Casos De Prueba
	cin >> t;

	while(t) {

		// Numero De Criaturas Feas XD
		cin >> n;
		int max = 0, speed;
		while(n) {
			
			// Velocidades de cada uno
			cin >> speed;
			if(max < speed)
				max = speed;
			
			n--;
		}
		
		Case++;

		cout <<"Case " << Case << ": " << max << "\n";
		
		t--;
	}
    return 0;
}