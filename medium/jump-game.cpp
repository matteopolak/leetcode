class Solution {
public:
	bool canJump(vector<int> &nums) {
		// 3 0 0 0 ?
		// 4 7 0 0 1 1 0 4

		// once we reach a zero (going +1 each time),
		// keep track of the "highest" jump (and its index)
		// to determine the farthest we could jump.
		// then, take the jump. if we end on a 0,
		// backtrack until the first zero we were looking at,
		// finding the largest jump (compared to our currnet-highest that we used to
		// jump with)

		int highestI = 0;
		int jump = 0;

		for (int i = 0; i < nums.size() - 1; ++i) {
			if (nums[i] == 0) {
				if (jump + highestI < i + 1)
					return false;

				continue;
			}

			if (nums[i] + i > jump + highestI) {
				highestI = i;
				jump = nums[i];
			}
		}

		return true;
	}
};
