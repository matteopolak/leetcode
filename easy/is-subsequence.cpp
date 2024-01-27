class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i = -1;

		for (char c : s) {
			bool found = false;

			for (++i; i < t.length(); ++i) {
				if (t[i] == c) {
					found = true;
					break;
				}
			}

			if (!found)
				return false;
		}

		return true;
	}
};
