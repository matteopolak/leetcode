class Solution {
public:
	vector<int> findSubstring(string s, vector<string> &words) {
		// uses a sliding window
		// the window size is the length of all words concatenated
		// the window moves one word at a time
		// the window is valid if the count of each word in the window
		// is the same as the count of each word in the words vector
		// the window is invalid if the count of a word in the window
		// is greater than the count of that word in the words vector
		// the window is invalid if a word in the window is not in the
		// words vector

		vector<int> result;
		int n = s.size();
		int m = words.size();
		int k = words[0].size();
		unordered_map<string, int> count;

		for (auto &word : words) {
			count[word]++;
		}

		for (int i = 0; i < k; i++) {
			int start = i;
			int end = i;
			int numWords = 0;
			unordered_map<string, int> window;

			while (end + k <= n) {
				string word = s.substr(end, k);
				end += k;

				if (count[word] == 0) {
					start = end;
					numWords = 0;
					window.clear();
				} else {
					window[word]++;
					numWords++;

					while (window[word] > count[word]) {
						string firstWord = s.substr(start, k);
						start += k;
						window[firstWord]--;
						numWords--;
					}

					if (numWords == m) {
						result.push_back(start);
					}
				}
			}
		}

		return result;
	}
};
