class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int result=0;
        for(int i=0;i<row;i++){
            result+=mat[i][i];
        }
        for(int i=0;i<row;i++){
            result+=mat[i][row-i-1];
        }
        if(row%2){
            result-=mat[row/2][col/2];
        }
        return result;
    }
};