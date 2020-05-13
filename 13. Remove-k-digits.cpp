# Remove K digits

'''
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
'''

/*
Time: O(N*K)
Space: O(1)
*/

Approach:== If all the digits are in increasing order than we will delete the last digit , 
otherwise we will delete a digit for which next digit is smaller.


class Solution {
public:
       
    string removeKdigits(string num, int k) {
     
        if(num.size() <= k)
            return "0";
      
        while(k--){
            int i=0;
            int len = num.size();

            while(i<len-1 && num[i+1] >= num[i]) i++;
            
            num.erase(i,1);
            
        }
        //Remove trailing zeros
        while (num.length() > 1 && num[0] == '0')
            num = num.substr(1,num.size());

        return num=="" ? 0 : num ;
    }
};
