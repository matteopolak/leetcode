class Solution {
public:
	int myAtoi(string s) {
		int v = 0;
		int n = -1;
		int sp = -1;

		bool st = false;

		for (int i = 0; i < s.length(); ++i) {
			char c = s[i];

			if (c == '-' && i == sp + 1) {
				n = 1;
				st = true;
				continue;
			} else if (c == '+' && i == sp + 1) {
				st = true;
				continue;
			} else if (c == ' ') {
				sp = i;

				if (st)
					break;
				continue;
			}

			if (c > '9' || c < '0') {
				break;
			}

			st = true;

			if (v < -INT_MAX / 10 ||
					(v == -INT_MAX / 10 && c > (n == 1 ? '8' : '7'))) {
				v = n == 1 ? INT_MIN : INT_MAX;
				n = 1;
				break;
			} else {
				v *= 10;
				v -= c - '0';
			}
		}

		return v * n;
	}
};
