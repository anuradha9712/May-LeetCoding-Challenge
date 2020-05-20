# Kth Smallest Element in BST

'''
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
'''

/////////////////////////////////////////////////////////////////////////////////
Aproach 1:-

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

 void inorderTraversal(TreeNode* root, vector<int>& V){
        if(root!=NULL){
            inorderTraversal(root->left,V);
            V.push_back(root->val);
            inorderTraversal(root->right,V);
        }
    }
    
    
     int kthSmallest(TreeNode* root, int k) {
        
        vector<int>V;
        inorderTraversal(root,V);
        return V[k-1];
     } 
     
 }
 
 //////////////////////////////////////////////////////////////////////////
 
 Approach 2:- 
 
  void findSmallest(TreeNode* root,int& count,int k, int& ans){
        if(root!=NULL){
            findSmallest(root->left,count,k,ans);
            count++;
            if(count==k){ ans= root->val;}
            findSmallest(root->right,count,k,ans);
        }
    }
    
      int kthSmallest(TreeNode* root, int k) {
       
        int count=0;
        int ans=0;
         findSmallest(root,count,k,ans);
        return ans;
        
    }

