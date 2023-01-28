class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Approach - 1 , Creating another vector and doing operations on it.
        vector<int> extra=nums;
        int s=nums.size();
        // Nothing is needed when the size of the vector is 0 or 1
        if(s==0||s==1)
        return ;
        int j=0;
        k=k%s;  // k value can be greater than the length of the vector
        for(int i=s-k;i<s;i++){
            extra[j++]=nums[i];
        }
        j=0;
        for(int i=k;i<s;i++){
            extra[i]=nums[j++];
        }
        nums=extra;
        // Approach -2 , O(1) Space Complexity solution
        int n = nums.size();
        k = k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
    }
    void reverse(vector<int>&nums, int l , int r){
        int left=l;
        int right=r;
        while(left<right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
};
