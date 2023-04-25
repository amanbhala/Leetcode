class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]={i};
            }else{
                count+=m[nums[i]].size();
                m[nums[i]].push_back(i);
            }
        }
        return count;
    }
};