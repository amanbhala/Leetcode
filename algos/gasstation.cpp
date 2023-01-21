class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Approach 1 - TLE because TC has a lot of zeroes
        // We loop through the array, find the difference between gas and cost, store that in travel and then see whether we can do this throughout the array. We will only do this when gas is greater then or equal to cost value. 
        // for(int i=0;i<gas.size();i++){
        //     if(gas[i]>=cost[i]){
        //         int travel=gas[i]-cost[i];
        //         int index=i;
        //         int startindex=index;
        //         index++;
        //         index=index%gas.size();
        //         while(startindex!=index){
        //             travel+=gas[index];
        //             if(travel<cost[index]){
        //                 break;
        //             }else{
        //                 travel-=cost[index];
        //             }
        //             index++;
        //             index=index%gas.size();
        //         }
        //         if(index==startindex){
        //             return startindex;
        //         }
        //     }
        // }
        // return -1;

        // Approach - Sort the array to get gas stations with highest value first to avoid TLE, but this will fail at cases where there is duplciate gas values
        // vector<pair<int,int>>input;
        // for(int i=0;i<gas.size();i++){
        //     input.push_back({gas[i],cost[i]});
        // }
        // sort(input.rbegin(),input.rend());
        // for(int i=0;i<input.size();i++){
        //     if(input[i].first>=input[i].second){
        //         int travel=input[i].first-input[i].second;
        //         int j=input[i].first;
        //         int index=i;
        //         for(int k=0;k<gas.size();k++){
        //             if(gas[k]==j){
        //                 index=k;
        //                 break;
        //             }
        //         }
        //         int startindex=index;
        //         index++;
        //         index=index%gas.size();
        //         while(startindex!=index){
        //             travel+=gas[index];
        //             if(travel<cost[index]){
        //                 break;
        //             }else{
        //                 travel-=cost[index];
        //             }
        //             index++;
        //             index=index%gas.size();
        //         }
        //         if(index==startindex){
        //             return startindex;
        //         }
        //     }
        // }
        // return -1;
        // Approach 3 - Add the gas and cost, if cost > gas then no solution exists.
        // If from any position we are able to reach the end of the array then we can definitely say that a solution exists.
        int gassum=0;
        for(int i=0;i<gas.size();i++)
            gassum+=gas[i];
        int costsum=0;
        for(int i=0;i<cost.size();i++)
            costsum+=cost[i];
        if(costsum>gassum)
        return -1;
        int solution=0;
        int total=0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                solution=i+1;
            }
        }
        return solution;
    }
};
