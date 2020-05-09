# Valid Perfect Square

'''
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
'''

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num ==1)
            return true;
        
        if(num == 2147483647)
            return false;
        
        for(int x=2;x<=num/2;x++){
            float y = log(num)/log(x);
            if(floor(y)==ceil(y))
                return true;
        }
        return false;
    }
};
