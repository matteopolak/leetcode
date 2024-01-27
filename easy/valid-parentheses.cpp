class Solution {
public:
	bool isValid(string s) {
		vector<char> ps;

		for (char c : s) {
			if (c == '(') {
				ps.push_back(')');
			} else if (c == '[') {
				ps.push_back(']');
			} else if (c == '{') {
				ps.push_back('}');
			} else {
				if (ps.size() == 0 || ps[ps.size() - 1] != c) {
					return false;
				}

				ps.pop_back();
			}
		}

		return ps.size() == 0;
	}
};
