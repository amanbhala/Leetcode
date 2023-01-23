class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Approach -1 - Sort O(nlogn)
        sort(nums.begin(),nums.end());
        return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
        // Approach - 2 - Loop through the array O(n)
        int seclar=0;int lar=0;
        if(nums[0]>=nums[1]){
            lar=nums[0];
            seclar=nums[1];
        }else{
            lar=nums[1];
            seclar=nums[0];
        }
        for(int i=2;i<nums.size();i++){
            if(nums[i]>=lar){
                seclar=lar;
                lar=nums[i];
            }else if(nums[i]>seclar&&nums[i]<lar){
                seclar=nums[i];
            }
        }
        return (seclar-1)*(lar-1);
    }
};
