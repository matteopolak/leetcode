class Solution {
public:
	vector<string> letterCombinations(string digits) {
		string prefix = "";
		letterCombinations(digits, prefix);
		return result;
	}

private:
	void letterCombinations(string digits, string prefix) {
		if (digits.empty()) {
			if (!prefix.empty())
				result.push_back(prefix);
			return;
		}

		int digit = digits[0] - '0';
		string letters = digitToLetters[digit];

		for (int i = 0; i < letters.size(); i++) {
			string letter = letters.substr(i, 1);
			string newPrefix = prefix + letter;
			letterCombinations(digits.substr(1), newPrefix);
		}
	}

	vector<string> result;
	unordered_map<int, string> digitToLetters = {
			{2, "abc"}, {3, "def"},	 {4, "ghi"}, {5, "jkl"},
			{6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"},
	};
};
