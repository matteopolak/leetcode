class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string f = strs[0];
		int l = f.length();

		for (int i = 0;; ++i) {
			if (l < i)
				return f.substr(0, i);

			char c = f[i];

			for (string s : strs) {
				if (s.length() <= i || s[i] != c) {
					return s.substr(0, i);
				}
			}
		}

		return f;
	}
};
