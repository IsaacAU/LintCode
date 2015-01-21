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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root)   return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *nd=stk.top(); stk.pop();
            res.push_back(nd->val);
            if(nd->right)
                stk.push(nd->right);
            if(nd->left)
                stk.push(nd->left);
        }
        return res;
    }
};

