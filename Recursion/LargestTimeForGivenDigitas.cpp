class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string result="";
        int sum=0;
        for(auto ele: arr)
        sum+=ele;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if(i!=j&&j!=k&&k!=i){
                        string hh=to_string(arr[i])+to_string(arr[j]);
                        string mm=to_string(arr[k])+to_string(arr[6-i-j-k]);
                        if(hh<"24"&&mm<"60"){
                            result=max(result,hh+":"+mm);
                        }
                    }
                }
            }
        }
        return result;
    }
};