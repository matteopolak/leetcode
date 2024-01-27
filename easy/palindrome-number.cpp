class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		long y = 0;
		long z = x;

		while (z) {
			y = y * 10 + z % 10;
			z /= 10;
		}

		return (long)x == y;
	}
};
