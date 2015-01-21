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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildIter(vector<int>::iterator preB, vector<int>::iterator preE, vector<int>::iterator inB, vector<int>::iterator inE){
        if(preB==preE)  return nullptr;
        TreeNode *root=new TreeNode(*preB);
        auto it=find(inB, inE, *preB);
        root->left=buildIter(next(preB), next(preB, distance(inB, it)+1), inB, it);
        root->right=buildIter(next(preB, distance(inB, it)+1), preE, next(it), inE);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return buildIter(begin(preorder), end(preorder), begin(inorder), end(inorder));
    }
};
