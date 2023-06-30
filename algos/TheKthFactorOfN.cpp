class Solution {
public:
    int kthFactor(int n, int k) {
        int count=0;
        if(n==1&&k==1)
        return 1;
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                count++;
                if(count==k)
                return i;
            }
        }
        if(count+1==k)
        return n;
        return -1;
    }
};