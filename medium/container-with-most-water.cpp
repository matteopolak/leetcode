class Solution {
public:
	int maxArea(vector<int> &height) {
		int l = 0;
		int r = height.size() - 1;
		int m = 0;

		while (l < r) {
			int area = min(height[l], height[r]) * (r - l);

			m = max(m, area);

			if (height[l] < height[r]) {
				++l;
			} else if (height[l] > height[r]) {
				--r;
			} else {
				++l;
				--r;
			}
		}

		return m;
	}
};
