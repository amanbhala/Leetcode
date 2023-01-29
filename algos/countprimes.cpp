class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prime(n+1,true);
        int count=0;
        for(int i=2;i*i<=n;i++){
            if(i>2&&i%2==0)
            continue;
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(prime[i])
            count++;
        }
        return count;
        // if(n<2)
        // return 0;
        // if(n==3)
        // return 1;
        // if(n==4)
        // return 2;
        // int count=0;
        // vector<bool> prime(n,false);
        // // prime[2]=true;
        // // prime[3]=true;
        // // prime[4]=false;
        // for(int i=2;i*i<=n;i++){
        //     if(!prime[i]){
        //         for(int j=i;j*i<=n;j++){
        //             prime[j*i]=true;
        //         }
        //     }
        // }
        // for(int i=2;i<n;i++){
        //     if(prime[i])
        //     count++;
        // }
        // return count;
        // for(int i=2;i<n;i++){
        //     if(isprime(i))
        //     count++;
        // }
        // return count;
    }
    // bool isprime(int num){
    //     int i=2;
    //     while(i<=num/2){
    //         if(num%i==0){
    //             return false;
    //         }
    //         i++;
    //     }
    //     return true;
    // }
};
