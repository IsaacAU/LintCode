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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode*> stk;
        vector<int> res;
        if(!root)   return res;
        TreeNode *nd=root;
        while(nd || !stk.empty()){
            if(nd){
                stk.push(nd);
                nd=nd->left;
            }else{
                nd=stk.top();  stk.pop();
                res.push_back(nd->val);
                nd=nd->right;
            }
        }
        return res;
    }
};
