class Solution {
public:
	int removeElement(vector<int> &nums, int val) {
		int end = 0;

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != val) {
				nums[end++] = nums[i];
			}
		}

		return end;
	}
};
