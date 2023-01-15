class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        if(row==0||col==0||row==1||col==1||row==2||col==2){
            return ;
        }
        for(int i=0;i<row;i++){
            dfs(board,i,0);
        }
        for(int i=0;i<row;i++){
            dfs(board,i,col-1);
        }
        for(int i=0;i<col;i++){
            dfs(board,0,i);
        }
        for(int i=0;i<col;i++){
            dfs(board,row-1,i);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O')
                board[i][j]='X';
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='T')
                board[i][j]='O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int row, int col){
        if(row<0||row>=board.size()||col<0||col>=board[0].size()||board[row][col]!='O')
        return ;
        board[row][col]='T';
        dfs(board,row-1,col);
        dfs(board,row+1,col);
        dfs(board,row,col+1);
        dfs(board,row,col-1);
    }
};
