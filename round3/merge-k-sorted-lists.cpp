/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	static bool comp(ListNode* a, ListNode* b){
		return a->val > b->val;
	}

    ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode*, vector<ListNode*>, bool(*)(ListNode*, ListNode*)> pq(comp);
		ListNode* pre, *cur, *head;
		
		for(int i = 0; i < lists.size(); i++){
			if(lists[i])
				pq.push(lists[i]);
		}
		if(pq.empty())
			return NULL;
			
		pre = cur = head = NULL;
		while(pq.size() > 1){
			cur = pq.top();
			pq.pop();
			if(!head){
				head = cur;
			}
			else{
				pre->next = cur;
			}
			pre = cur;
			cur = cur->next;
			if(cur)
				pq.push(cur);
		}
		cur = pq.top();
		pq.pop();
		if(!pre){
			head = pre = cur;
			return head;
		}
		pre->next = cur;
		return head;
    }
};
