class Solution {
public:
	vector<int> productExceptSelf(vector<int> &nums) {
		vector<int> out(nums.size(), 1);
		int c = 1;

		for (int i = 0; i < nums.size(); ++i) {
			out[i] *= c;
			c *= nums[i];
		}

		c = 1;

		for (int i = nums.size() - 1; i >= 0; --i) {
			out[i] *= c;
			c *= nums[i];
		}

		return out;
	}
};
