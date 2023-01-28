class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Approach - 1 O(n) - TC
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN);
        int res=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
                res=i-1;
                break;
            }
        }
        return res;
        // Approach - 2 Binary Search type approach 
        // Do not add INT_MIN as there is a test case where INT_MIN is the value in he array. So specially checking it.
        // nums.insert(nums.begin(),INT_MIN);
        // nums.push_back(INT_MIN);
        int s=nums.size();
        int res=0;
        int l=0;int r=nums.size();
        if(nums.size()==1)
        return 0;
        if(nums[0]>nums[1])
        return 0;
        if(nums[s-1]>nums[s-2])
        return s-1;
        while(l<=r){
            int m=(l+r)/2;
            if(m-1>=0&&m+1<s&&nums[m]>nums[m-1]&&nums[m]>nums[m+1]){
                res=m;
                break;
            }else if(m-1>=0&&m+1<s&&nums[m]<nums[m+1]&&nums[m]>nums[m-1]){
                l=m;
            }else{
                r=m;
            }
        }
        return res;
    }
};
