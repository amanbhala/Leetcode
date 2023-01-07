class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Count how many 0,1 and 2 are there in the vector
        int countzero=0;
        int countone=0;
        int counttwo=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            countzero++;
            if(nums[i]==1)
            countone++;
            if(nums[i]==2)
            counttwo++;
        }
        int index=0;
        while(countzero--){
            nums[index++]=0;
        }
        while(countone--){
            nums[index++]=1;
        }
        while(counttwo--){
            nums[index++]=2;
        }
    }
};
