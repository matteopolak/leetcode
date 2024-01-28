class Solution {
public:
	vector<string> summaryRanges(vector<int> &nums) {
		vector<string> ans;

		if (nums.size() == 0)
			return ans;

		int s = nums[0];
		int e = nums[0];

		int p = nums[0];

		for (int n : nums) {
			if (n > p + 1) {
				// push range
				ans.push_back(make_range(s, e));

				s = n;
				e = n;
			} else {
				e = n;
			}

			p = n;
		}

		ans.push_back(make_range(s, e));

		return ans;
	}

	string make_range(int s, int e) {
		if (s == e)
			return to_string(s);

		return to_string(s) + "->" + to_string(e);
	}
};
