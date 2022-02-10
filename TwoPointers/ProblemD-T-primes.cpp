#include <iostream> 
#include <cmath>
#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std; 

int main(){ 
    
    _io
    
    long long int n,a,x,i; 
    
    bool nelsonMandela = false;
    
    cin>>n; 
    
    while(n--){ 
        
        // La idea es checar si tiene solo un divisor porque el 1 y N es seguro
        // si tiene divisor entre 2 pues tendra muchos
        
        // Revisar los numeros SQRT(N) * SQRT(N) == N asi ya tenemos el 1, N y SQRT(N)
        
        //Ejemplo1: 4 = 4/1 = 4, 4/4 = 1, SQRT(4) = 2 && 4/2 = 2. COUT,,YES
        //Ejemplo2: 49 = 49/1 = 49, 49/49 = 1, SQRT(49) = 7 && 49/7 = 7. COUT,,YES.
        //Ejemplo3: 6 = 6/1 = 6, 6/6 = 1, SQRT(6) = 2.xxx (No es entero entonces no) jeje :/
        
    	cin >> a;
    	
    	nelsonMandela = false;
    	
    	x=sqrt(a); // La raiz de a
    	
        // Checamos si alguno de las raices tiene un divisor (excluyendo al 1 claro porque se cicla diciendo si)
        // && que no sea primo... si encontramos uno rompemos el ciclo
        
    	for(i=2;i*i<x;i++)
    	
    	    //si encontramos alguno
    	    if(x%i==0){	
    	        nelsonMandela = true;
        	    break;
    	}
    	
        // Si nelsonMandela es falso (ningun otro numero encontrado), que no sea 1 el numero que buscamos sino mayor
        // y que x*x la raiz buscada sea igual al numero main a.
    	if(!nelsonMandela && a>1 && x*x==a)	
    	    cout << "YES" << '\n'; 
    	
    	else
    	    cout << "NO" << '\n';
    }
    
    return 0; 
} 