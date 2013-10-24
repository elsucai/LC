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
        // Note: The Solution object is instantiated only once and is reused by each test case.
		priority_queue<ListNode*, vector<ListNode*>, bool(*)(ListNode*, ListNode*)> pq(comp);

		ListNode* pre, *head, *cur;
		pre = head = cur = NULL;

		for(int i = 0; i < lists.size(); i++){
			if(lists[i])
				pq.push(lists[i]);
		}

		if(pq.empty())
			return head;

		while(pq.size() > 1){
			cur = pq.top();
			pq.pop();
			if(!pre){
				head = pre = cur;
			}
			else{
				pre->next = cur;
				pre = cur;
			}
			cur = cur->next;
			if(cur)
				pq.push(cur);
		}

		//last list
		cur = pq.top();
		if(!pre)
			head = pre = cur;
		else
			pre->next = cur;

		return head;
    }
};
