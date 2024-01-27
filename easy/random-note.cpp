class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> ls;

		for (char c : magazine) {
			ls[c]++;
		}

		for (char c : ransomNote) {
			if (--ls[c] < 0)
				return false;
		}

		return true;
	}
};
