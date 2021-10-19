#include <iostream>
#include <vector>
#include <algorithm>


int main(){

    // short x[5];

    std:: vector<short> x (5, 0);

    short i = 1, j;
    
    while(true){
        std::cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
        
        // if(x[0] == 1 || x[1] == 1 || x[2] == 1 || x[3] == 1 || x[4] == 1){
        //     break;
        // }

        std::vector<short>::iterator itr = std::find(x.begin(), x.end(), 1);

        if (itr != x.cend()){

            // std::cout<< i << "-" <<std::distance(x.begin(), itr)+1<<std::endl
            
            j = std::distance(x.begin(), itr)+1;
            
            break;
        }

        i++;
    }

    std::cout << abs(i - 3) + abs(j -3) << std::endl;

    return (0);

}