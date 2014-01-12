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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(!node)
			return NULL;
		UndirectedGraphNode* croot = NULL;
		queue<UndirectedGraphNode*> q;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hm;
		croot = new UndirectedGraphNode(node->label);
		hm[node] = croot;
		q.push(node);

		UndirectedGraphNode* cur, *tmp, *clone;
		while(!q.empty()){
			cur = q.front();
			q.pop();
			clone = hm[cur];
			for(int i = 0; i < (cur->neighbors).size(); i++){
				tmp = (cur->neighbors)[i];
				if(hm.find(tmp) == hm.end()){
					hm[tmp] = new UndirectedGraphNode(tmp->label);
					q.push(tmp);
				}
				(clone->neighbors).push_back(hm[tmp]);
			}
		}
		return croot;
    }
};
