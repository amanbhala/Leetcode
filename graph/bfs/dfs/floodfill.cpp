class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        if(sr>=row||sc>=col||image[sr][sc]==color)
        return image;
        int startcolor=image[sr][sc];
        dfs(image,sr,sc,color,row,col,startcolor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr,int sc,int color, int row,int col,int startcolor){
        if(image[sr][sc]==startcolor){
            image[sr][sc]=color;
            if(sr+1<row){
                dfs(image,sr+1,sc,color,row,col,startcolor);
            }
            if(sc+1<col){
                dfs(image,sr,sc+1,color,row,col,startcolor);
            }
            if(sr-1>=0){
                dfs(image,sr-1,sc,color,row,col,startcolor);
            }
            if(sc-1>=0){
                dfs(image,sr,sc-1,color,row,col,startcolor);
            }
        }
    }
};