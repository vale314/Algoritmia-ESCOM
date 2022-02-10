// https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
//         root, suma y pathsum
        dfs(root,sum,0);
        return sum;
    }
    
    void dfs(TreeNode* current, int &sum, int pathSum){
        // si es nulo acutal se retorna
        if(!current){
            return;
        }
        
        // el pathsum se multiplica por 10 mas el valor actual
        pathSum = pathSum * 10 + current->val;
        
        // si no hay hijos somos la hoja
        if(!current->left and !current->right){
            //Nuestra sum toma el valor de pathSum actual
            sum+=pathSum;
            return;
        }
        
        //recorremos el hijo izq y der
        dfs(current->left, sum, pathSum);
        dfs(current->right, sum, pathSum);
    }
};