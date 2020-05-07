# Cousins in Binary Tree

'''
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

'''
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
    
    int level(TreeNode* root, int ptr, int lev) 
    { 
        // base cases 
        if (root == NULL) return 0; 
        if (root->val == ptr)  return lev; 

        // Return level if Node is present in left subtree 
        int l = level(root->left, ptr, lev+1); 
        if (l != 0)  return l; 

        // Else search in right subtree 
        return level(root->right, ptr, lev+1); 
    }
    
    bool isSibling(TreeNode* root, int x, int y){
        if(root == NULL)
            return false;
        
        return ((root->left!=NULL && root->right!= NULL && root->left->val==x && root->right->val==y) ||
                ( root->left!=NULL && root->right!= NULL && root->right->val==x && root->left->val==y) ||
                isSibling(root->left,x,y) ||
                isSibling(root->right,x,y));
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        return (!isSibling(root,x,y) && level(root,x,1) == level(root,y,1) ); 
    }
};
