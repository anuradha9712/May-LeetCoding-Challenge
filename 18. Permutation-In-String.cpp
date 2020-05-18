# Permutation in String

'''
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
 
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
'''

//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int s1_len = s1.size();
        int s2_len = s2.size();
        
        if(s1_len > s2_len) return false;
        
        vector<int>smap(26,0);
        vector<int>wmap(26,0);

        // Store frequency of character of s1 into smap
        for(int i=0;i<s1_len;i++){
            smap[s1[i]-'a']++;
            wmap[s2[i]-'a']++;
        }
        
        if(smap == wmap) return true;

       // we subtract one preceding character and add a new succeeding character to the new window considered. 
        for(int j=1; j<= s2_len - s1_len; j++){
            
            wmap[s2[j+s1_len - 1] -'a']++;
            wmap[s2[j-1] - 'a']--;
         
            if(smap == wmap) return true;
        }
        
        return false;
        
    }
};
