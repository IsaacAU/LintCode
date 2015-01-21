/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    // method 1: hashmap
    RandomListNode *copyRandomList1(RandomListNode *head) {
        // write your code here
        if(!head)   return nullptr;
        unordered_map<RandomListNode*, RandomListNode*> m;
        RandomListNode *copy=new RandomListNode(head->label);
        m[head]=copy;
        RandomListNode *nd=head;
        while(nd->next){
            nd=nd->next;
            copy->next=new RandomListNode(nd->label);
            copy=copy->next;
            m[nd]=copy;
        }
        for(auto it=begin(m); it!=end(m); ++it)
            if(it->first->random)
                it->second->random=m[it->first->random];
        return m[head];
    }
    // method 2: insert copy
    RandomListNode *copyRandomList2(RandomListNode *head){
        if(!head)   return nullptr;
        RandomListNode *nd=head;
        while(nd){
            RandomListNode *tmp=nd->next;
            nd->next=new RandomListNode(nd->label);
            nd->next->next=tmp;
            nd=tmp;
        }
        nd=head;
        while(nd){
            if(nd->random)
                nd->next->random=nd->random->next;
            nd=nd->next->next;
        }
        RandomListNode dummy(-1);
        RandomListNode *prev=&dummy;
        nd=head;
        while(nd){
            prev->next=nd->next;
            nd->next=nd->next->next;
            prev=prev->next;
            nd=nd->next;
        }
        return dummy.next;
    }
};
