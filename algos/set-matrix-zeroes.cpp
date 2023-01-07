class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // First Solution TC: O(mn) , SC: O(m+n)
        // set<int>row;
        // set<int>col;
        // int r=matrix.size();
        // int c=matrix[0].size();
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         if(matrix[i][j]==0){
        //             row.insert(i);
        //             col.insert(j);
        //         }
        //     }
        // }
        // for(auto it=row.begin();it!=row.end();it++){
        //     for(int i=0;i<c;i++){
        //         matrix[*it][i]=0;
        //     }
        // }
        // for(auto it=col.begin();it!=col.end();it++){
        //     for(int i=0;i<r;i++){
        //         matrix[i][*it]=0;
        //     }
        // }
        
        // Second Solution TC: O(mn) , SC: O(1)
        bool first_row_has_zeros=false;
        bool first_col_has_zeros=false;
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<c;i++){
            if(matrix[0][i]==0){
                first_row_has_zeros=true;
                break;
            }
        }
        for(int i=0;i<r;i++){
            if(matrix[i][0]==0){
                first_col_has_zeros=true;
                break;
            }
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        // for(int i=0;i<r;i++){
        //     if(matrix[i][0]==0){
        //         for(int j=1;j<c;j++){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }
        // for(int i=0;i<c;i++){
        //     if(matrix[0][i]==0){
        //         for(int j=1;j<r;j++){
        //             matrix[j][i]=0;
        //         }
        //     }
        // }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(first_row_has_zeros){
            for(int i=0;i<c;i++){
                matrix[0][i]=0;
            }
        }
        if(first_col_has_zeros){
            for(int i=0;i<r;i++){
                matrix[i][0]=0;
            }
        }
    }
};
