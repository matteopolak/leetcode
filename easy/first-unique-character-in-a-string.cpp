class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> found(26, INT_MAX);

		int i = 0;

		for (char c : s) {
			int k = c - 'a';

			if (found[k] != INT_MAX) {
				found[k] = -1;
			} else if (found[k] != -1) {
				found[k] = i;
			}

			i++;
		}

		int min = INT_MAX;

		for (int c : found) {
			if (c != -1 && c < min)
				min = c;
		}

		return min == INT_MAX ? -1 : min;
	}
};
