class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int l = 0;
		int r = numbers.size() - 1;

		vector<int> ans(2);

		// we'll start with two pointers, one on each end
		// if the number is too big, move the right one left
		// too small, move the left one right

		while (l < r) {
			int s = numbers[l] + numbers[r];

			if (s < target) {
				l++;
			} else if (s > target) {
				r--;
			} else {
				ans[0] = l + 1;
				ans[1] = r + 1;

				break;
			}
		}

		return ans;
	}
};
