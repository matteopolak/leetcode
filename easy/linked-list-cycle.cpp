class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr)
			return false;

		ListNode *slow = head;
		ListNode *fast = head->next;

		while (slow && fast) {
			if (slow == fast)
				return true;

			if (slow)
				slow = slow->next;

			if (fast->next)
				fast = fast->next->next;
			else
				fast = nullptr;
		}

		return false;
	}
};
