class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int result = 0;
		int start = 0;
		int end = 0;
		int n = s.size();
		std::vector<int> count(256, 0);

		while (end < n) {
			char c = s[end];
			count[c]++;

			while (count[c] > 1) {
				count[s[start]]--;
				start++;
			}

			result = std::max(result, end - start + 1);
			end++;
		}

		return result;
	}
};
