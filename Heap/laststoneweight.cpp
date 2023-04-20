class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto element: stones){
            pq.push(element);
        }
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(first>second){
                pq.push(first-second);
            }else{
                pq.push(0);
            }
        }
        return pq.top();
    }
};