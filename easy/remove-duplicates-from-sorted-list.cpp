class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr)
			return head;

		ListNode *prev = head;
		ListNode *curr = head->next;

		while (curr) {
			if (prev->val == curr->val) {
				prev->next = curr->next;
			} else {
				prev = curr;
			}

			curr = curr->next;
		}

		return head;
	}
};
