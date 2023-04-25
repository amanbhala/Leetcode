class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'&&s.find(board[i][j])!=s.end()){
                    return false;
                }else if(board[i][j]!='.'){
                    s.insert(board[i][j]);
                }
            }
            for(auto it=s.begin();it!=s.end();it++){
                cout<<*it<<" ";
            }
            cout<<"\n";
            s.clear();
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'&&s.find(board[j][i])!=s.end()){
                    return false;
                }else if(board[j][i]!='.'){
                    s.insert(board[j][i]);
                }
            }
            for(auto it=s.begin();it!=s.end();it++){
                cout<<*it<<" ";
            }
            cout<<"\n";
            s.clear();
        }
        int row=0;
        int col=0;
        int num=0;
        int count=3;
        while(count--){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(board[row+j][k+col]!='.'&&s.find(board[row+j][k+col])!=s.end()){
                        return false;
                    }else if(board[row+j][k+col]!='.'){
                        s.insert(board[row+j][k+col]);
                    }
                }
            }
            row+=3;
            for(auto it=s.begin();it!=s.end();it++){
                cout<<*it<<" ";
            }
            cout<<"\n";
            s.clear();
        }
        col=3;
        row=0;
        count=3;
        while(count--){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(board[row+j][k+col]!='.'&&s.find(board[row+j][k+col])!=s.end()){
                        return false;
                    }else if(board[j+row][k+col]!='.'){
                        s.insert(board[row+j][k+col]);
                    }
                }
            }
            row+=3;
            for(auto it=s.begin();it!=s.end();it++){
                cout<<*it<<" ";
            }
            cout<<"\n";
            s.clear();
        }
        col=6;
        row=0;
        count=3;
        while(count--){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(board[row+j][k+col]!='.'&&s.find(board[row+j][k+col])!=s.end()){
                        return false;
                    }else if(board[j+row][k+col]!='.'){
                        s.insert(board[row+j][k+col]);
                    }
                }
            }
            row+=3;
            for(auto it=s.begin();it!=s.end();it++){
                cout<<*it<<" ";
            }
            cout<<"\n";
            s.clear();
        }
        return true;
    }
};