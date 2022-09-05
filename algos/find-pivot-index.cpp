class Solution {
public:
    int pivotIndex(vector<int>& nums) {
//       For this case: [0]
        if(nums.size()==1&&nums[0]==0)
            return 0;
        if(nums.size()<2){
            return -1;
        }
//    For cases like these: [1,0] and [0,1], where there is one 0 and length is 2 
        if(nums.size()==2){
           if(nums[0]==0)
               return 1;
           else if(nums[1]==0)
               return 0;
           else
               return -1;
        }
        int left=0;
        int right=0;
        for(int i=0;i<nums.size();i++){
            right+=nums[i];
        }
        if((right-nums[0])==0){
           return 0; 
        }
        right-=nums[0];
        for(int i=1;i<nums.size();i++){
            left+=nums[i-1];
            right-=nums[i];
            if(left==right){
                return i;
            }
        }
        return -1;
    }
};
