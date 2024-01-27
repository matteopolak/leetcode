
class Solution {
public:
	string minWindow(string s, string t) {
		// keep track of all chars -> count in the current window.
		// while the first char in the window is > 1, we can keep moving the window
		//
		// once we have a valid window, we can start shrinking it from the left
		// by removing chars that are not in t or have a count > 1
		//
		// we keep track of the min window and return it at the end

		unordered_map<char, int> count;

		for (char c : t) {
			count[c]++;
		}

		int start = 0;
		int end = 0;
		int n = s.size();
		int minStart = 0;
		int minLen = INT_MAX;
		int numChars = t.size();

		while (end < n) {
			char c = s[end];

			if (count[c] > 0) {
				numChars--;
			}

			count[c]--;
			end++;

			while (numChars == 0) {
				if (end - start < minLen) {
					minStart = start;
					minLen = end - start;
				}

				char c = s[start];

				if (count[c] == 0) {
					numChars++;
				}

				count[c]++;
				start++;
			}
		}

		return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
	}
};
