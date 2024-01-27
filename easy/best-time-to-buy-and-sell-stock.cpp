class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int diff = 0;
		int min = INT_MAX;

		for (int p : prices) {
			if (p < min)
				min = p;
			else if (p - min > diff)
				diff = p - min;
		}

		return diff;
	}
};
