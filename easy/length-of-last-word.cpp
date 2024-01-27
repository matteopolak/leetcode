class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = 0;
		bool clear = false;

		for (char c : s) {
			if (c != ' ') {
				if (clear)
					length = 0;

				clear = false;
				length++;
			} else {
				clear = true;
			}
		}

		return length;
	}
};
