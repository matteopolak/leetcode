class Solution {
public:
	int romanToInt(string s) {
		int n = s.size();
		int sum = 0;

		for (int i = n - 1; i >= 0; --i) {
			if (i == 0) {
				sum += value(s[i]);
				continue;
			}

			int v = value(s[i]);
			int p = value(s[i - 1]);

			if (v > p) {
				sum += v - p;
				--i;
			} else {
				sum += v;
			}
		}

		return sum;
	}

	int value(char c) {
		switch (c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
	}
};
