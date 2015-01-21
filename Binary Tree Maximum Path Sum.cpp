/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int helper(TreeNode *root, int &res){
        if(!root)   return 0;
        int x=helper(root->left, res), y=helper(root->right, res);
        res=max(res, root->val+max(x,0)+max(y,0));
        return root->val+max(max(x,0), max(y,0));
    } 
    
    int maxPathSum(TreeNode *root) {
        // write your code here
        if(!root)   return 0;
        int res=INT_MIN;
        helper(root, res);
        return res;
    }
};
