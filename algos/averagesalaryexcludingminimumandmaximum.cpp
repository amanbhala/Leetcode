class Solution {
public:
// Two Iterations
    double average(vector<int>& salary) {
        int count=salary.size();
        int maximum=INT_MIN;
        int minimum=INT_MAX;
        for(int i=0;i<count;i++){
            maximum=max(maximum,salary[i]);
            minimum=min(minimum,salary[i]);
        }
        double c=count-2;
        double result=0.0;
        for(auto a: salary){
            if(a!=maximum&&a!=minimum){
                result+=(a/c);
            }
        }
        return result;
    }
// One Iteration
    double average(vector<int>& salary) {
        int count=salary.size();
        int maximum=INT_MIN;
        int minimum=INT_MAX;
        double c=count-2;
        double result=0.0;
        for(int i=0;i<count;i++){
            maximum=max(maximum,salary[i]);
            minimum=min(minimum,salary[i]);
            result+=(salary[i]/c);
        }
        result=result-(maximum/c);
        result=result-(minimum/c);
        return result;
    }
// Same solution as above, but different way of parsing vector
    double average(vector<int>& salary) {
        int count=salary.size();
        int maximum=INT_MIN;
        int minimum=INT_MAX;
        double c=count-2;
        double result=0.0;
        for(auto a: salary){
            maximum=max(maximum,a);
            minimum=min(minimum,a);
            result+=(a/c);
        }
        result=result-(maximum/c);
        result=result-(minimum/c);
        return result;
    }
};