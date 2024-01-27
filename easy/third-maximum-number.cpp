class Solution {
public:
	int thirdMax(vector<int> &nums) {
		long m1 = (long)INT_MIN - 1;
		long m2 = (long)INT_MIN - 1;
		long m3 = (long)INT_MIN - 1;

		for (int n : nums) {
			if (n > m1) {
				m3 = m2;
				m2 = m1;
				m1 = n;
			} else if (n > m2 && n != m1) {
				m3 = m2;
				m2 = n;
			} else if (n > m3 && n != m2 && n != m1) {
				m3 = n;
			}

			printf("m1: %d | m2: %d | m3: %d\n", m1, m2, m3);
		}

		return m3 != (long)INT_MIN - 1 ? m3 : m1;
	}
};
