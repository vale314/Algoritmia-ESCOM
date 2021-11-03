class Solution {
public:
    
//Stack, guardamos Valor, Poscicion de vector
stack < pair <int ,int> > edificios_Algortihm;
vector<int> numerosInt;
// int numerosInt[9999999];

int m = -1;

int menor(int j, int actual){
    
    //Regrersamos cantidad de numeros menores contiguos

    int k = 0;

    for(int i = j; i >= 0 ; i--){
        // cout<<i << " ";
        if(numerosInt[i] >= actual)
            k++;
        else
            break;
    }
    
    // cout<< "k: "<< k << '\n';
    return k;
}

void drop(){

    //eliminar todos los elementos
    while(!edificios_Algortihm.empty()){
        edificios_Algortihm.pop();
        
    }
}

void algor(){
    
    int n_aux = edificios_Algortihm.top().first;
    int first = edificios_Algortihm.top().first;
    int second = edificios_Algortihm.top().second;

    while(!edificios_Algortihm.empty()){
        n_aux = edificios_Algortihm.top().first;
        
        first = edificios_Algortihm.top().first;
        // second = edificios_Algortihm.top().second;

        int mult = 0;

            //si la pila tiene mas de 1 elem. nos quedamos con el valor anterior y posicion actual

            if(edificios_Algortihm.size()>1){
                edificios_Algortihm.pop();
                first = edificios_Algortihm.top().first;
            }
        
            // multiplicamos elemento actual * cantidad de veces encontrados menores o igual contiguos.
            
            mult = first * menor(second, first);

            //si la multiplicacion es mayor al edificio actual cambiamos
            if(mult > n_aux)
                n_aux = mult;
            
            //si aux es mayor a el maximo de ataque 
            if(n_aux > m)
                m = n_aux;
        
        // drop();
        edificios_Algortihm.pop();
    }

}
    
int largestRectangleArea(vector<int>& heights) {
    
    

    //Agregamos un elemento extra para comprobar el ultimo elemento
    int prev = heights[heights.size()-1];
    if(prev)
        heights.push_back(0);
    
    edificios_Algortihm.push(make_pair(heights[0], 0));
    
    numerosInt = heights;
    
     for(int i = 1; i < heights.size(); i++ ){
         
         //si el nuevo a meter es menor al tope
         if(heights[i] < edificios_Algortihm.top().first ){
            
             algor();
         }
         
        // if(i < heights.size()-1)
            edificios_Algortihm.push(make_pair(heights[i], i));
     }

    // cout << m << endl;
        
    return m == -1 ? 0 : m;
    }
};