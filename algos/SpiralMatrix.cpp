class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int m=matrix.size();
       int n=matrix[0].size();
       vector<int> result;
       int top=0;
       int bottom=m;
       int left=0;
       int right=n;
       int i=0;
       while(top<bottom&&left<right){
           for(i=left;i<right;i++){
               result.push_back(matrix[top][i]);
            //    cout<<matrix[top][i]<<" ";
           }
           top++;
           for(i=top;i<bottom;i++){
               result.push_back(matrix[i][right-1]);
            //    cout<<matrix[i][right-1]<<" ";
           }
           right--;
           if(left>=right||top>=bottom){
               break;
           }
           for(i=right-1;i>=left;i--){
                result.push_back(matrix[bottom-1][i]);
                // cout<<matrix[bottom-1][i]<<" ";
            }
            bottom--;
            for(i=bottom-1;i>top-1;i--){
                result.push_back(matrix[i][left]);
                // cout<<matrix[i][left]<<" ";
            }
            left++;
            // cout<<"Top: "<<top<<"\n";
            // cout<<"Bottom: "<<bottom<<"\n";
            // cout<<"Left: "<<left<<"\n";
            // cout<<"Right: "<<right<<"\n";
       }
       return result;
    }
};