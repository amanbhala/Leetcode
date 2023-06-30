class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>nums;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        nums.push_back({nums2[i],nums1[i]});
        sort(nums.rbegin(),nums.rend());
        priority_queue<int,vector<int>, greater<int>>minh;
        long long currsum=0;
        for(int i=0;i<k-1;i++){
            minh.push(nums[i].second);
            currsum+=nums[i].second;
        }
        long long ans=0;
        for(int i=k-1;i<n;i++){
            currsum+=nums[i].second;
            ans=max(ans,(long long)currsum*nums[i].first);
            if(minh.size()>0&&minh.top()<nums[i].second){
                currsum-=minh.top();
                minh.pop();
                minh.push(nums[i].second);
            }else{
                currsum-=nums[i].second;
            }
        }
    return ans;
    }
};