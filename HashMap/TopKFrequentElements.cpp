class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto ele: nums){
            m[ele]++;
        }
        set<pair<int,int>>s;
        for(auto it=m.begin();it!=m.end();it++){
            s.insert({it->second,it->first});
        }
        vector<int>res;
        auto it=s.end();
        it--;
        while(k--){
            res.push_back(it->second);
            it--;
        }
        return res;
    }
};