class Solution {
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& t){
        vector<pair<int,int>>d={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        vector<vector<bool>> vis(row , vector<bool> (col, false));
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            pair<int,int>temp=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int r=temp.first+d[i].first;
                int c=temp.second+d[i].second;
                if(r>=0&&r<row&&c>=0&&c<col&&grid[r][c]==0&&vis[r][c]==false){
                    t[r][c]=t[temp.first][temp.second]+1;
                    q.push({r,c});
                    vis[r][c]=true;
                }
            }
        }
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int len=-1;
        int row=grid.size();
        int col=row;
        vector<vector<int>> temp( row , vector<int> (col, 0));
        if(row==1&&col==1&&grid[0][0]==0)
        return 1;
        if(grid[0][0]==1)
        return -1;
        bfs(row,col,grid,temp);
        if(temp[row-1][col-1]==0)
        return -1;
        return temp[row-1][col-1]+1;
    }
};