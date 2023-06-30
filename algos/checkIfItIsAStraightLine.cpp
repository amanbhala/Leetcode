class Solution {
    float slope(float x1,float y1,float x2,float y2){
        if(x2-x1!=0)
        return (y2-y1)/(x2-x1);
        else
        return INT_MIN;
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float sl=slope(coordinates[0][0],coordinates[0][1],coordinates[1][0],coordinates[1][1]);
        cout<<sl<<" ";
        for(int i=2;i<=coordinates.size()-1;i++){
            cout<<slope(float(coordinates[i-1][0]),float(coordinates[i-1][1]),float(coordinates[i][0]),float(coordinates[i][1]))<<" ";
            if(slope(coordinates[i-1][0],coordinates[i-1][1],coordinates[i][0],coordinates[i][1])!=sl){
            return false;
            }
        }
         return true;
    }
};