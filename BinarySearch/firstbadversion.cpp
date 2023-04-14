// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       long long int low=1;
       long long int high=n;
       long long int mid=(low+high)/2;
       int result=mid;
       while(low<=high){
           mid=low+(high-low)/2;
           if(isBadVersion(mid)){
               high=mid-1;
               result=mid;
           }else if(!isBadVersion(mid)){
               low=mid+1;
           }
       }
       return result;
    }
};