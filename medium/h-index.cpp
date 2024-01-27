class Solution {
public:
	int hIndex(vector<int> &citations) {
		int l = min(citations.size(), (unsigned long)1001);
		vector<int> count(l, 0);

		for (int n : citations) {
			for (int i = 1; i <= min(n, l - 1); ++i) {
				count[i]++;
			}
		}

		for (int i = l - 1; i >= 0; --i) {
			if (count[i] >= i)
				return i;
		}

		return 0;
	}
};
