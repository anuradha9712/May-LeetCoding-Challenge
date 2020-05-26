# 26. Contiguous Array

'''
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
'''

class Solution {
public:
    
    /* Time complexity:- O(n)
    Space Complexity:- O(n)
    */
    
    int findMaxLength(vector<int>& nums) {
        map<int,int>mp;
        mp[0] = -1;
        int maxlen = 0; 
        int count = 0;
        
        for(int i=0;i<nums.size();i++)
        { 
            count += nums[i]==1 ? 1 : -1;
            if(mp.find(count)!=mp.end())
                maxlen = max(maxlen , i-mp[count]);
            else
                mp[count] = i;
        }
        return maxlen;
        
    }
};
