class Solution {
public:
	int minSubArrayLen(int target, vector<int> &nums) {
		if (nums.size() == 0)
			return 0;

		// sliding window:
		// get the first n elements until its >= target
		// then remove the first item, then increase the end until its >= target,
		// ... repeat until the end

		// window [s, e]
		int s = 0;
		int e = 0;
		// value of current window
		int value = nums[s];

		// smallest window
		int ans = INT_MAX;
		bool found = false;

		while (e < nums.size()) {
			while (value < target && ++e < nums.size()) {
				value += nums[e];
			}

			if (value >= target) {
				found = true;
				ans = min(ans, e - s + 1);
			}

			if (s < nums.size())
				value -= nums[s++];
		}

		return found ? ans : 0;
	}
};
