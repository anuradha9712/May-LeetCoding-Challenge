// =======Check If It Is a Straight Line============

//You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
//Check if these points make a straight line in the XY plane.

// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int len = coordinates.size();
        if(len==2)
            return true;
        
        float slope = (float)(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        
        for(int i=2;i<len;i++){
            float currSlope = (float)(coordinates[i][1]-coordinates[i-1][1])/
                              (coordinates[i][0]-coordinates[i-1][0]);
            
            if(currSlope != slope)
                return false;
        }
        
        return true;
    }
};



