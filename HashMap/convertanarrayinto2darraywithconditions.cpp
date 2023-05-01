class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // vector<int>count(200);
        unordered_map<int,int>map;
        int maximum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            map[nums[i]-1]++;
            maximum=max(maximum,map[nums[i]-1]);
        }
        vector<vector<int>>res(maximum);
        for(auto it=map.begin();it!=map.end();it++){
            int temp=it->second;
            for(int j=0;j<temp;j++){
                res[j].push_back(it->first+1);
            }
        }
        return res;
    }
};