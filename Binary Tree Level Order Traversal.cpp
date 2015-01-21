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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if(!root)   return res;
        queue<TreeNode*> q;
        q.push(root);
        int cur=1, next=0;
        vector<int> level;
        while(!q.empty()){
            TreeNode *nd=q.front(); q.pop();
            level.push_back(nd->val);
            if(nd->left){
                q.push(nd->left);
                ++next;
            }
            if(nd->right){
                q.push(nd->right);
                ++next;
            }
            if(--cur==0){
                swap(cur, next);
                res.push_back(level);
                level.clear();
            }
        }
        return res;
    }
};

