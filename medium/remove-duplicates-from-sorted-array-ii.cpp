class Solution {
public:
	int removeDuplicates(vector<int> &nums) {
		if (nums.size() < 2)
			return nums.size();

		int end = 2;

		for (int i = 2; i < nums.size(); ++i) {
			if (nums[i] != nums[end - 1] || nums[i] != nums[end - 2]) {
				nums[end++] = nums[i];
			}
		}

		return end;
	}
};
