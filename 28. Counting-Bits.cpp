# Counting Bits

Given a non negative integer number num.
For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:
Input: 2
Output: [0,1,1]

Example 2:
Input: 5
Output: [0,1,1,2,1,2]

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>setBits(num + 1);
        
        setBits[0]=0;
        
        if(num > 0){
            setBits[1]=1;

            for (int i = 2; i <= num; i++) { 

            // If current element i is even then 
            // it has set bits equal to the count 
            // of the set bits in i / 2 
            if (i % 2 == 0) { 
                setBits[i] = setBits[i / 2]; 
            } 

            // Else it has set bits equal to one 
            // more than the previous element 
            else { 
                setBits[i] = setBits[i - 1] + 1; 
            } 
        }    
    } 
        return setBits;
        
    }
};
