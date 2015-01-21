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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if(!root)   return res;
        queue<TreeNode*> q;
        q.push(root);
        int cur=1, next=0;
        bool rev=false;
        res.push_back(vector<int>());
        while(!q.empty()){
            TreeNode *nd=q.front();    q.pop();
            res.back().push_back(nd->val);
            if(nd->left){
                q.push(nd->left);
                ++next;
            }
            if(nd->right){
                q.push(nd->right);
                ++next;
            }
            if(--cur==0){
                if(rev)
                    reverse(begin(res.back()), end(res.back()));
                if(next){
                    rev=!rev;
                    res.push_back(vector<int>());
                    res.back().reserve(next);
                    swap(cur, next);
                }
            }
        }
        return res;
    }
};
