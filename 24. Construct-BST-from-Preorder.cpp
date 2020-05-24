# Construct BST from Preorder Traversal

Return the root node of a binary search tree that matches the given preorder traversal.

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Time Complexity:- O(n)

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*>S;
        TreeNode* root = new TreeNode(preorder[0]);
        S.push(root);
        
        for(int i=1;i<preorder.size();i++){
            
            if(preorder[i] < S.top()->val){
                S.top()->left = new TreeNode(preorder[i]);
                S.push(S.top()->left);
            }
            else{
                TreeNode *curr ;
                while(!S.empty() && preorder[i] > S.top()->val){
                    
                    curr = S.top();
                    S.pop();
                }
                curr->right = new TreeNode(preorder[i]);
                S.push(curr->right);

                
            }
        }
        return root;

        
    }
};
