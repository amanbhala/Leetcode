class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v(101);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
        }
        vector<int> res;
        vector<int> store(101);
        store[0]=0;
        for(int i=1;i<=100;i++){
            store[i]=store[i-1]+v[i-1];
        }
        for(int i=0;i<nums.size();i++){
            res.push_back(store[nums[i]]);
        }
        return res;
    }
};