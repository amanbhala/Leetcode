class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        int row=edges.size();
        for(int i=0;i<row;i++){
            visited[edges[i][1]]=1;
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            if(visited[i]==0)
            result.push_back(i);
        }
        return result;
    }
};