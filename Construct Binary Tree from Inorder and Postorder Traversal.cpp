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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildIter(vector<int>::iterator inB, vector<int>::iterator inE, vector<int>::iterator posB, vector<int>::iterator posE){
        if(inB==inE)    return nullptr;
        TreeNode *root=new TreeNode(*prev(posE));
        auto it=find(inB, inE, root->val);
        root->left=buildIter(inB, it, posB, next(posB, distance(inB, it)));
        root->right=buildIter(next(it), inE, next(posB, distance(inB, it)), prev(posE));
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        return buildIter(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }
};
