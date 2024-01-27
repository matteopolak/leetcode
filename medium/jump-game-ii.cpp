class Solution {
public:
	int jump(vector<int> &nums) {
		int jumps = 0;
		int l = nums.size();

		if (l == 1) {
			return 0;
		}

		int currentEnd = 0;
		int farthest = 0;

		for (int i = 0; i < l - 1; ++i) {
			farthest = max(farthest, i + nums[i]);

			if (i == currentEnd) {
				currentEnd = farthest;
				jumps++;
			}
		}

		return jumps;
	}
};
