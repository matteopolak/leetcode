class Solution {
public:
	int majorityElement(vector<int> &nums) {
		int c = 0;
		int t = 0;

		for (int n : nums) {
			if (c == 0)
				t = n;

			c += n == t ? 1 : -1;
		}

		return t;
	}
};
