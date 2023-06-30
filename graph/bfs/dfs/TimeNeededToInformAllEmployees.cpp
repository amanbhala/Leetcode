class Solution {
    int bfs(int src,vector<int> adj[],vector<int>& informTime){
        queue<pair<int,int>>q;
        q.push({src,0});       // (id , time)
        int res=INT_MIN;
        while(!q.empty()){
            int front=q.front().first;
            int value=q.front().second;
            res=max(res,value);
            q.pop();
            for(auto ele: adj[front]){
                q.push({ele,value+informTime[front]});
            }        
        }
        return res;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];     // Mgr -> [list of emps]
        for(int i=0;i<n;i++){
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        // BFS         
        return bfs(headID,adj,informTime);
    }
};