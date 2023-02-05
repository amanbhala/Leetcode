class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // Approach - 1, O(n^4), TLE
        // int count=0;
        // for(auto ele1: nums1){
        //     for(auto ele2: nums2){
        //         for(auto ele3: nums3){
        //             for(auto ele4: nums4){
        //                 if(ele1+ele2+ele3+ele4==0)
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;
        // Approach - 2, Using map O(n^2)
        unordered_map<int,int>s;
        int count=0;
        int n=nums1.size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         int val=nums1[i]+nums2[j];
        //         if(s.find(val)==s.end())
        //         s[val]=1;
        //         else
        //         s[val]++;
        //     }
        // }
        // Optimized way to insert values in map
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=-1*(nums3[i]+nums4[j]);
                if(s.find(val)!=s.end()){
                    count+=s[val];
                }
            }
        }
        return count;
    }
};
