/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(!node)   return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while(!q.empty()){
            UndirectedGraphNode *nd=q.front();  q.pop();
            if(m.count(nd)==0)
                m[nd]=new UndirectedGraphNode(nd->label);
            for(auto n:nd->neighbors)
                if(m.count(n)==0)
                    q.push(n);
        }
        for(auto it=begin(m); it!=end(m); ++it)
            for(auto n:it->first->neighbors)
                it->second->neighbors.push_back(m[n]);
        return m[node];
    }
};
