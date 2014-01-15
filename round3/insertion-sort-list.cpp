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
    ListNode *insertionSortList(ListNode *head) {
		if(!head || !head->next)
			return head;
		ListNode* pre, *cur, *remain, *key;
		remain = head->next;
		pre = NULL;
		cur = head;
		cur->next = NULL;

		for(; remain; ){
			key = remain;
			remain = remain->next;
			for(cur = head, pre = NULL; cur && cur->val <= key->val; pre = cur, cur = cur->next)
				;
			if(!pre){
				key->next = head;
				head = key;
			}
			else{
				pre->next = key;
				key->next = cur;
			}
		}
		return head;
    }
};
