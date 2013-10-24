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
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		queue<UndirectedGraphNode*> q;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hm;
		UndirectedGraphNode* root, *cur, *next, *tmpnode, *tmpneighbor;
		unordered_set<UndirectedGraphNode*> visited;

		if(!node)
			return node;
		root = new UndirectedGraphNode(node->label);
		hm[node] = root;
		q.push(node);
		visited.insert(node);

		while(!q.empty()){
			cur = q.front();
			q.pop();

			//make a copy
			if(hm.find(cur) == hm.end()){
				tmpnode = new UndirectedGraphNode(cur->label);
				hm[cur] = tmpnode;
			}
			else
				tmpnode = hm[cur];

			// fill all neighbors
			for(int i = 0; i < (cur->neighbors).size(); i++){
				next = cur->neighbors[i];
				// create a new neighbor
				if(hm.find(next) == hm.end()){
					tmpneighbor = new UndirectedGraphNode(next->label);
					hm[next] = tmpneighbor;
				}
				else
					tmpneighbor = hm[next];
				tmpnode->neighbors.push_back(tmpneighbor);
				
				if(visited.find(next) == visited.end()){
					q.push(next);
					visited.insert(next);
				}
			}
		}
		
		return root;
    }
};
