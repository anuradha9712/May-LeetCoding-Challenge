# Number Complement

'''

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. 
So you need to output 2.

'''

class Solution {
public:
    int findComplement(int num) {
        
       //find number of bits in number 
       int bit_count = int(log2(num))+1;
       int ones = pow(2,bit_count) - 1;
        
   return ones ^ num;
        
    }
};
