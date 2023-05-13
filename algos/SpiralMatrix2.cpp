class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0)
        return {{}};
        vector<vector<int>> result(n,vector<int>(n,1));
        int left=0;int right=n;int top=0;int bottom=n;
        int num=1;
        while(left<right&&top<bottom){
            for(int i=left;i<right;i++){
                result[top][i]=num++;
            }
            top++;
            for(int i=top;i<bottom;i++){
                result[i][right-1]=num++;
            }
            right--;
            if(left>right||top>bottom)
            break;
            for(int i=right-1;i>=left;i--){
                result[bottom-1][i]=num++;
            }
            bottom--;
            for(int i=bottom-1;i>=top;i--){
                result[i][left]=num++;
            }
            left++;
        }
        return result;
    }
};