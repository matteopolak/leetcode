class Solution {
public:
	bool isPalindrome(string s) {
		int l = nextStart(0, s);
		int r = nextEnd(s.length() - 1, s);

		while (r > l) {
			if (convert(s[r]) != convert(s[l])) {
				return false;
			}

			l = nextStart(l + 1, s);
			r = nextEnd(r - 1, s);
		}

		return true;
	}

	char convert(char c) {
		if (c >= 'A' && c <= 'Z') {
			return c + ('a' - 'A');
		}

		return c;
	}

	int nextStart(int start, string s) {
		for (int i = start; i < s.length(); ++i) {
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
					(s[i] >= '0' && s[i] <= '9')) {
				return i;
			}
		}

		return -1;
	}

	int nextEnd(int start, string s) {
		for (int i = start; i >= 0; --i) {
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
					(s[i] >= '0' && s[i] <= '9')) {
				return i;
			}
		}

		return -1;
	}
};
