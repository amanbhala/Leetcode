class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 2-pass hash table
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()&&(i!=m[target-nums[i]])){
                result.push_back(i);
                result.push_back(m[target-nums[i]]);
                break;
            }
        }
        return result;
        // 1-pass hash table
        map<int,int>m;
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()&&(i!=m[target-nums[i]])){
                result.push_back(i);
                result.push_back(m[target-nums[i]]);
                break;
            }else {
                m[nums[i]]=i;
            }
        }
        return result;
    }
};