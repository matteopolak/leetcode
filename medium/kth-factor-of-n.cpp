class Solution {
public:
	int kthFactor(int n, int k) {
		int s = sqrt(n);
		bool isSquare = s * s == n;

		for (int i = 1; i <= s - isSquare; ++i) {
			if (n % i == 0 && --k == 0)
				return i;
		}

		for (int i = s; i >= 1; --i) {
			if (n % i == 0 && --k == 0)
				return n / i;
		}

		return -1;
	}
};
