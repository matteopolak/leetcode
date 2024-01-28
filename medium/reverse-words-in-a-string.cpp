class Solution {
public:
	string reverseWords(string s) {
		string out = "";
		string word = "";

		for (int i = s.length() - 1; i >= 0; --i) {
			if (s[i] != ' ') {
				word = s[i] + word;
			} else if (word.length() != 0) {
				if (out.length() != 0) {
					out += ' ';
				}

				out += word;
				word = "";
			}
		}

		if (word.length() != 0) {
			if (out.length() != 0) {
				out += ' ';
			}

			out += word;
		}

		return out;
	}
};
