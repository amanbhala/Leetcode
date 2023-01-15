class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // First Solution
        // Base cases
        if(prices.size()==0||prices.size()==1)
        return 0;
        if(prices.size()==2){
            if(prices[1]>prices[0]){
                return prices[1]-prices[0];
            }else{
                return 0;
            }
        }
        // In this problem we will just try to find out whenever we can buy lower and sell higher and calculate profit and add it to total profit.
        int profit=0;
        int low=prices[0];
        int high=prices[0];
        if(prices[1]<prices[0]){
            low=prices[1];
        }
        for(int i=1;i<prices.size()-1;i++){
            // If this point is less than it's left and right neighbour then this becomes low.
            if(prices[i]<prices[i+1]&&prices[i]<prices[i-1]){
                low=prices[i];
            }
            // If this point is greater than or equal to next value and greater than previous value then this becomes high.
            else if(prices[i]>=prices[i+1]&&prices[i]>prices[i-1]){
                high=prices[i];
                profit+=(high-low);
            }
            // If this value is less than previous value then low becomes current value
            else if(prices[i]<prices[i-1]){
                low=prices[i];
            }
            // If this value is greater than previous value then this becomes high
            else if(prices[i]>prices[i-1]){
                high=prices[i];
            }
            // If this value is equal to the previous value then we shift low to point to this value otherwise low value will not be updated. Look at this case: [0,5,5,6,2,1,1,3]
            else{
                low=prices[i];
            }
        }
        if(prices[prices.size()-1]>prices[prices.size()-2]){
            high=prices[prices.size()-1];
            profit+=(high-low);
        }
        return profit;
        
        // Second Solution
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};
