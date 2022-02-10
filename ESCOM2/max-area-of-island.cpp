class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0; i<grid.size() ;i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea,maxAreaOfIslandDFS(grid,i,j));
                }
            }
        }
        return maxArea;
    }
    
    int maxAreaOfIslandDFS(vector<vector<int>>& grid,int x, int y){
        if(x<0 or y<0 or x==grid.size() or y==grid[0].size()){
            return 0;
        }
        if(grid[x][y]==0){
            return 0;
        }
        
        grid[x][y]=0;
        
        return 1 + maxAreaOfIslandDFS(grid,x+1,y) + maxAreaOfIslandDFS(grid,x-1,y) + maxAreaOfIslandDFS(grid,x,y+1) + maxAreaOfIslandDFS(grid,x,y-1); 
    }
};

//Time O(n*m); Space O(L)