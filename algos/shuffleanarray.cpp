class Solution {
    vector<int>original;
public:
    Solution(vector<int>& nums) {
        original=nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int>copy=original;
        int l=original.size();
        for(int i=l-1;i>=0;i--){
            int j=rand()%l;
            swap(copy[i],copy[j]);
        }
        return copy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
