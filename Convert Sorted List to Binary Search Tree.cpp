/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(!head)   return nullptr;
        int n=1;
        ListNode *nd=head;
        while(nd->next){
            nd=nd->next;
            ++n;
        }
        n/=2;
        nd=head;
        ListNode *prev=nullptr;
        while(n--){
            prev=nd;
            nd=nd->next;
        }
        TreeNode *root=new TreeNode(nd->val);
        if(prev){
            prev->next=nullptr;
            root->left=sortedListToBST(head);
            prev->next=nd;
        }
        root->right=sortedListToBST(nd->next);
        return root;
    }
};



