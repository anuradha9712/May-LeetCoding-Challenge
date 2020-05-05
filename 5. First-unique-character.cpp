# first unique xharacter in string

'''
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

'''

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(int j=0;j<s.size();j++){
            if(mp[s[j]] < 2)
                return j;
        }
        return -1;
        
    }
};
