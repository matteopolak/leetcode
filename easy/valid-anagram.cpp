class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> sc;
		unordered_map<char, int> st;

		for (char c : s) {
			sc[c]++;
		}

		for (char c : t) {
			st[c]++;
		}

		if (st.size() != sc.size())
			return false;

		for (auto i : sc) {
			if (st[i.first] != i.second)
				return false;
		}

		return true;
	}
};
