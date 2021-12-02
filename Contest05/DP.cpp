#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector <int> monedas;

int main(){

    int numMax = 0;

    cin >> numMax;

    monedas.push_back(1);
    monedas.push_back(5);
    monedas.push_back(10);
    monedas.push_back(20);
    monedas.push_back(100);

    long n=monedas.size();
    long arr[n+1][numMax+1];

    for(long i=0;i<=n;i++)
        {
            for(long j=0;j<=numMax;j++)
            {
                if(i==0)
                    arr[i][j]=LONG_MAX-1;
                else if(j==0)
                    arr[i][j]=0;
            }
        }
        for(long j=1;j<=numMax;j++)
        {
            if(j%monedas[0]==0)
            {
                long k=j/monedas[0];
                arr[1][j]=k;
            }
            else
                arr[1][j]=LONG_MAX-1;
        }
        for(long i=1;i<=n;i++)
        {
            for(long j=1;j<=numMax;j++)
            {
               if(monedas[i-1]<=j)
               {
                   arr[i][j]=min((1+arr[i][j-monedas[i-1]]),arr[i-1][j]);
               }
                else
                    arr[i][j]=arr[i-1][j];
            }
        }
        if(arr[n][numMax]==LONG_MAX-1)
            return -1;
        else{
            
            cout << arr[n][numMax] << endl;

            return 0;
        }

}