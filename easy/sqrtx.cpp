class Solution {
public:
	int mySqrt(int x) {
		int min = 0;
		int max = 46340;

		if (x >= 2147395600)
			return 46340;

		for (;;) {
			// find n such that (n + 1) * (n + 1) > x, (n - 1) * (n - 1) < x

			int mid = (min + max) / 2;
			int s = mid * mid;
			int s1 = (mid + 1) * (mid + 1);

			if (s <= x && s1 > x)
				return mid;

			if (s > x) {
				max = mid;
			} else {
				min = mid;
			}
		}
	}
};
