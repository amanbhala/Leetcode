class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        if(nums1.size()==0&&nums2.size()!=0){
            return {{},nums2};
        }
        if(nums1.size()!=0&&nums2.size()==0){
            return {nums1,{}};
        }
        set<int>s1;
        set<int>s2;
        for(auto a: nums1){
            s1.insert(a);
        }
        for(auto a: nums2){
            s2.insert(a);
        }
        vector<int>distinctnum1={};
        vector<int>distinctnum2={};
        set<int>distincts1;
        set<int>distincts2;
        for(auto a: nums2){
            if(s1.find(a)==s1.end()){
                distincts1.insert(a);
                // distinctnum2.push_back(a);
            }
        }
        for(auto a: nums1){
            if(s2.find(a)==s2.end()){
                distincts2.insert(a);
                // distinctnum1.push_back(a);
            }
        }
        for(auto it=distincts1.begin();it!=distincts1.end();it++){
            distinctnum2.push_back(*it);
        }
        for(auto it=distincts2.begin();it!=distincts2.end();it++){
            distinctnum1.push_back(*it);
        }
        ans[0]=distinctnum1;
        ans[1]=distinctnum2;
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> distinct_nums1, distinct_nums2;
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }

        return {distinct_nums1, distinct_nums2};
    }
};