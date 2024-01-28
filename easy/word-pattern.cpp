class Solution {
public:
	bool wordPattern(string pattern, string s) {
		unordered_map<char, string> ps;
		unordered_map<string, bool> used;

		int pi = 0;

		int st = 0;
		int en = 0;

		while (pi < pattern.length() && en < s.length()) {
			while (++en < s.length() && s[en] != ' ') {
			}

			// remove the space
			bool sp = en < s.length() && s[en] == ' ';

			string word = s.substr(st, en - st + 1 - sp);

			if (ps[pattern[pi]] == "") {
				if (used[word])
					return false;

				used[word] = true;
				ps[pattern[pi]] = word;
			} else {
				if (word != ps[pattern[pi]]) {
					return false;
				}
			}

			st = en + sp;
			pi++;
		}

		return pi == pattern.length() && en == s.length();
	}
};
