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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root)   return res;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode *prev=nullptr;
        while(!stk.empty()){
            TreeNode *cur=stk.top();
            if(!prev || prev->left==cur || prev->right==cur){
                if(cur->left)
                    stk.push(cur->left);
                else if(cur->right)
                    stk.push(cur->right);
            }else if(cur->left==prev){
                if(cur->right)
                    stk.push(cur->right);
            }else{
                res.push_back(cur->val);
                stk.pop();
            }
            prev=cur;
        }
        return res;
    }
};
