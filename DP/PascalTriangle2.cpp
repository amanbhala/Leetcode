class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> temp;
        vector<int>result;
        for(int i=0;i<=rowIndex;i++)
        {
            vector<int> ans(i+1,1);
            for(int j=1;j<i;j++)
            {
                ans[j]=temp[i-1][j]+temp[i-1][j-1];
            }
            if(i==rowIndex)
            {
                result=ans;
                break;
            }
            temp.push_back(ans);
        }
        return result;
    }
};