# Interval List Intersection

'''
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval. 
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
'''

Approach 1:-

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> result;

        if(A.size()==0 || B.size()==0) return result;
        
        //appending elements of vector B to vector A
        A.insert(A.end(), B.begin(), B.end());
        
        //sort vector according to increasing start time
        sort(A.begin(),A.end(),[](vector<int> a, vector<int> b){return (a[0] < b[0]); });
        
        int startTime = A[0][0];
        int endTime = A[0][1];
        
        for(int k=1;k<A.size();k++){
            
            if(startTime <= A[k][0] && endTime >=A[k][0]){
                vector<int> temp;
                temp.push_back(A[k][0]);
                temp.push_back(min(endTime , A[k][1]));
                result.push_back(temp);
            }
            startTime = A[k][0];
            endTime = max(endTime , A[k][1]);
        }
        return result;      
    }
};
