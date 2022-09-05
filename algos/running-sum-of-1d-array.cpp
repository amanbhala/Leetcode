class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // This solution uses O(n) space
        vector<int> result;
        int i=0;
        int ans=0;
        result.push_back(nums[0]);
        for(i=1;i<nums.size();i++){
            result.push_back(nums[i]+result[i-1]);
        }
        return result;
        
        // The below solution uses O(1) space
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        return nums;
    }
};
