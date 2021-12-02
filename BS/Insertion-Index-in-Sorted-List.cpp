/*
    https://binarysearch.com/problems/Insertion-Index-in-Sorted-List
*/

int solve(vector<int>& nums, int target) {
    int l = 0; // al inicio del arreglo
    int r = nums.size() - 1; // al final del arreglo

    int position = nums.size();   

    // en el momento que l sea mayor o igual a r se acaba
    while(l <= r){

        int m = (r - l) / 2 + l; 
        
        // formula para enconrtrar el medio

        if(nums[m] > target){
            
            position = m;
            // guardamos la ultima poscion valida

            r = m - 1;
        } else {

            l = m + 1;

        }
    }

    return position;
}