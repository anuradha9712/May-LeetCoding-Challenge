# Course Schedule

'''
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
             
Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
             
Constraints:
-- The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
-- You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5             
'''
// Time Complexity: - O(|V| + |E|)


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj (n,vector<int>());
        vector<int>Indegree(n,0);
        
        // Create Adjacency list
        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
            Indegree[p[0]]++;         
        }
        
        queue<int>que;
        for(int i=0;i<n;i++){
            if(Indegree[i]==0)
                que.push(i);
        }
        
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            n--;
            for(auto d : adj[curr]){
                Indegree[d]--;
                if(Indegree[d]==0)
                    que.push(d);
            }
        }
        
        return (n==0)? true: false;
        
    }
};
