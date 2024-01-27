class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int maxWidth) {
		vector<string>(lines);

		// index of first word in line
		int s = 0;
		// index of last word in line
		int e = 0;

		// length of all words in current line
		int l = 0;

		while (s < words.size()) {
			for (int i = s; i < words.size(); ++i) {
				if (words[i].length() + l + max(e - s + (l == 0 ? 0 : 1), 0) <=
						maxWidth) {
					e = i;
					l += words[i].length();
				} else {
					break;
				}
			}

			// we need to pad spaces now
			string line = words[s];

			if (e == words.size() - 1) {
				// if only one word, pad to end
				int p = maxWidth - (l + max(e - s, 0));

				if (s != e) {
					line += ' ';
				}

				for (int i = s + 1; i <= e; ++i) {
					line += words[i];

					if (i != e)
						line += ' ';
				}

				line += pad(p);
			} else if (e == s) {
				int p = maxWidth - l;

				line += pad(p);
			} else {
				// min spaces for each word
				int spaces = (maxWidth - l) / (e - s);
				// index to stop extra spaces
				int endExtra = s + (maxWidth - l) % (e - s) - 1;

				if (endExtra >= s) {
					line += pad(spaces + 1);
				} else {
					line += pad(spaces);
				}

				for (int i = s + 1; i < e; ++i) {
					line += words[i];

					if (endExtra >= i) {
						line += pad(spaces + 1);
					} else {
						line += pad(spaces);
					}
				}

				line += words[e];
			}

			lines.push_back(line);

			s = e + 1;
			e = s;
			l = 0;
		}

		return lines;
	}

	string pad(int length) {
		string p = "";

		for (int i = 0; i < length; ++i) {
			p += ' ';
		}

		return p;
	}
};
