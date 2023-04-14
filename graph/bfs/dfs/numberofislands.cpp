class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        set<pair<int,int>>s;
        int result=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'&&(s.find({i,j})==s.end())){
                    dfs(grid,s,i,j,row,col);
                    result+=1;
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char>>& grid, set<pair<int,int>>& s,int row,int col,int gridrow, int gridcol){
        if(row<0||row>=gridrow||col<0||col>=gridcol){
            return ;
        }
        if(grid[row][col]=='1'&&s.find({row,col})==s.end()){
            s.insert({row,col});
            dfs(grid,s,row+1,col,gridrow,gridcol);
            dfs(grid,s,row-1,col,gridrow,gridcol);
            dfs(grid,s,row,col+1,gridrow,gridcol);
            dfs(grid,s,row,col-1,gridrow,gridcol);
        }
    }
};
