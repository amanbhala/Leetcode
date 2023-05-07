// TLE SOLUTION
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>res(obstacles.size(),1);
        if(obstacles.size()==0)
        return {};
        res[0]=1;
        // Start from that element, move lower and see the first element that is equal to or less than that element, and add +1 to the value at that position
        for(int i=1;i<obstacles.size();i++){
            int j=i-1;
            while(j>=0){
                if(obstacles[i]>=obstacles[j]){
                    res[i]=max(res[j]+1,res[i]);
                }
                j--;
            }
        }
        return res;
    }
};

// LIS based solution, Greedy+BinarySearch
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>ans(n),lis;
        for(int i=0;i<n;i++){
            int idxToInsert=upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
            if(idxToInsert==lis.size()){
                lis.push_back(obstacles[i]);
            }else{
                lis[idxToInsert]=obstacles[i];
            }
            ans[i]=idxToInsert+1;
        }
        return ans;
    }
};