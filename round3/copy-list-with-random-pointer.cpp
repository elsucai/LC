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
    RandomListNode *copyRandomList(RandomListNode *head) {
		if(!head)
			return NULL;
		RandomListNode* copy, *pre, *ptr;
		unordered_map<RandomListNode*, RandomListNode*> hm;
		copy = pre = new RandomListNode(0);

		for(ptr = head; ptr; ptr = ptr->next){
			pre->next = new RandomListNode(ptr->label);
			pre = pre->next;
			hm[ptr] = pre;
		}
		for(ptr = head; ptr; ptr = ptr->next){
			hm[ptr]->random = hm[ptr->random];
		}

		return copy->next;
    }
};
