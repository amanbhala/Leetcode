class Solution {
public:
    int trailingZeroes(int n) {
        // We just need to know the number of 5's in the number n
        int sum=0;
        while((n/5)>0){
            sum+=(n/5);
            n=n/5;
        }
        return sum;
    }
};
