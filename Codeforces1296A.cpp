#include <iostream>

using namespace std;

int main (){
    int t;
    cin>>t;
    
    int n;

    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n];

        int numPares = 0;
        int numImpares = 0;
        int unos = 0;
        int suma = 0;

        for(int j=0; j<n; j++){
            cin>>arr[j];

            if(arr[j]%2 == 0){
                numPares++;
            }else{
                if(arr[j] == 1){
                    unos++;
                }else{
                    numImpares++;
                }
            }

            suma += arr[j];
        }

        if(unos > 0){
            if(unos%2 == 0){
                numPares++;
            }else{
                numImpares++;
            }
        }

        // if((numImpares == 1 && numPares == 1) && ((arr[0] + arr[1]) == 5)){
        if(suma%2 != 0 || suma == 1){
            cout<<"YES"<<endl;
            continue;
        }

        // if( (numImpares>numPares) && (numImpares%2 != 0)){
        if(numImpares && numPares){
            cout<<"YES"<<endl;
            continue;
        }

        cout<<"NO"<<endl;

    }
}