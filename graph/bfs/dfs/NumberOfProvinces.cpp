class Solution {
    void dfs(int src,set<int>&s,vector<vector<int>>& isConnected ){
        s.insert(src);
        for(int i=0;i<isConnected[src].size();i++){
            if(isConnected[src][i]&&(s.find(i)==s.end())){
                dfs(i,s,isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        set<int>s;
        for(int i=0;i<n;i++){
            if(s.find(i)==s.end()){
                dfs(i,s,isConnected);
                count++;
            }
        }
        return count;
    }
};