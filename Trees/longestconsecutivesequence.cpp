class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    // First Solution - O(nlogn) solution (because of sorting) , O(1) Space complexity
        if(!nums.size())
        return 0;
        sort(nums.begin(),nums.end());
        int final_ans=1;
        int ans=1;
        // I used whileloop flag to check whether while loop ran or not to have control over variable "i".
        bool whileloop=false;
        for(int i=0;i<nums.size()-1;){
            while(i+1<nums.size()){
                if(nums[i+1]-nums[i]==1){
                    ans++;
                    i++;
                    whileloop=true;
                }else if(nums[i+1]==nums[i]){
                    i++;
                    whileloop=true;
                    continue;
                }else{
                    break;
                }
            }
            final_ans=max(final_ans,ans);
            ans=1;
            if(!whileloop){
                i++;
            }else{
                whileloop=false;
            }
        }
        return final_ans;
        // Second Solution - Using set
        if(!nums.size())
        return 0;
        int ans=1;
        int final_ans=1;
        set<int> s;
        for(auto i: nums){
            s.insert(i);
        }
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                int next=nums[i]+1;
                while(s.find(next)!=s.end()){
                    ans++;
                    next++;
                }
                final_ans=max(final_ans,ans);
                ans=1;
            }
        }
        return final_ans;
    }
};
