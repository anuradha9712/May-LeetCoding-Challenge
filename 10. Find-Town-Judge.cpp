# Find Town Judge

'''
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

-The town judge trusts nobody.
-Everybody (except for the town judge) trusts the town judge.
-There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N
'''

class Solution {
public:
    
      int findJudge(int N, vector<vector<int>>& trust) {
          vector<vector<int>> knows(N + 1, vector<int>(N + 1));
          for (auto &t : trust) knows[t[0]][t[1]] = 1;
          return findCelebrity(N, knows);
    }

    int findCelebrity(int n, vector<vector<int>>& knows, int i = 1) {
      for (auto j = i + 1; j <= n; ++j) if (knows[i][j]) i = j;
      for (auto j = 1; j < i; ++j) if (knows[i][j]) return -1;
      for (auto j = 1; j <= n; ++j) if (i != j && !knows[j][i]) return -1;
      return i;
    }
};

//Time: O(N).
//Memory: O(1).
