// TLE
class Solution {
    int bfs(int row,int col,vector<vector<int>>& matrix,int c){
        queue<pair<int,int>>q;
        set<pair<int,int>>s;
        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        if(matrix[0][c]!=1){
            q.push({0,c});
            s.insert({0,c});
        }else{
            return -1;
        }
        while(!q.empty()){
            int toprow=q.front().first;
            int topcol=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int finalrow=toprow+dir[i].first;
                int finalcol=topcol+dir[i].second;
                if(finalrow>=0&&finalrow<row&&finalcol>=0&&finalcol<col&&matrix[finalrow][finalcol]==0&&s.find({finalrow,finalcol})==s.end()){
                    if(finalrow==(row-1)&&matrix[finalrow][finalcol]==0){
                        return 1;
                    }else{
                        q.push({finalrow,finalcol});
                        s.insert({finalrow,finalcol});
                    }
                }
            }
        }
        return -1;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int days=0;
        vector<vector<int>> matrix(row,vector<int>(col,0));
        bool sol=false;
        for(int i=0;i<cells.size();i++){
            matrix[cells[i][0]-1][cells[i][1]-1]=1;
            for(int i=0;i<col;i++){
                if(matrix[0][i]==0){
                    if(bfs(row,col,matrix,i)==1){
                        days++;
                        sol=true;
                        break;
                    }
                }
            }
            if(!sol){
                break;
            }
            sol=false;
        }
        return days;
    }
};
// Using Binary Search
class Solution {
    bool canCross(int row,int col,vector<vector<int>>& cells,int mid){
        queue<pair<int,int>>q;
        set<pair<int,int>>s;
        vector<vector<int>> matrix(row,vector<int>(col,0));
        for(int i=0;i<mid;i++){
            matrix[cells[i][0]-1][cells[i][1]-1]=1;
        }
        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0){
                q.push({0,i});
                s.insert({0,i});
            }
        }
        while(!q.empty()){
            int toprow=q.front().first;
            int topcol=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int finalrow=toprow+dir[i].first;
                int finalcol=topcol+dir[i].second;
                if(finalrow>=0&&finalrow<row&&finalcol>=0&&finalcol<col&&matrix[finalrow][finalcol]==0&&s.find({finalrow,finalcol})==s.end()){
                    if(finalrow==(row-1)){
                        return true;
                    }else{
                        q.push({finalrow,finalcol});
                        s.insert({finalrow,finalcol});
                    }
                }
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1;
        int right = row * col;
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (canCross(row, col, cells, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};