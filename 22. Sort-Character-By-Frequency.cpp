# Sort Characters By Frequency

'''
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
'''

//Time Complexity:- O(nlogn)
//Space Complexity:- O(n)

class Solution {
public:
     
    string frequencySort(string s) {
        map<char,int>mp;
        
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        
        
        vector<pair<char, int>> vec;
        
        // copy key-value pairs from the map to the vector
        map<char, int> :: iterator it2;
        
        for (it2=mp.begin(); it2!=mp.end(); it2++)
            vec.push_back(make_pair(it2->first, it2->second));
        
        
        sort(vec.begin(), vec.end(),[](pair<char, int> a,  pair<char, int> b){return (a.second > b.second); });
        
        string ans;
        
        for(pair<char,int> p : vec){
            for(int i=0; i<p.second; ++i)
                ans+=p.first;
        }
        
        return ans;        
    }
};
