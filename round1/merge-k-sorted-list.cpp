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
	static bool comp(ListNode* l1, ListNode* l2){
		return l1->val < l2->val;
	}

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(lists.empty())
			return NULL;
		ListNode* head, *pre, *next;

		multiset<ListNode*, bool(*)(ListNode*, ListNode*)> ms(comp);
		for(int i = 0; i < lists.size(); i++){
			if(lists[i])
				ms.insert(lists[i]);
		}
		if(ms.empty())
			return NULL;
		head = pre = *(ms.begin());
		next = pre->next;

		ms.erase(ms.begin());
		if(next)
			ms.insert(next);
		if(ms.empty())
			return head;

		while(ms.size() > 1){
			next = *(ms.begin());
			ms.erase(ms.begin());

			pre->next = next;
			pre = next;
			next = pre->next;

			if(next)
				ms.insert(next);
		}

		pre->next = *(ms.begin());
		return head;
    }
};
