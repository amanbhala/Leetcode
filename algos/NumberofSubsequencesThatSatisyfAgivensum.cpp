class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        long long result=0;
        int mod = 1e9 + 7;
        sort(nums.begin(),nums.end());
        int l=0;int r=nums.size()-1;
        vector<int>power(nums.size());
        power[0]=1;
        for(int i=1;i<nums.size();i++){
            power[i]=(power[i-1]*2)%mod;
        }
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                result=result%mod+power[r-l]%mod;
                l++;
            }else{
                r--;
            }
        }
        return result;
    }
};