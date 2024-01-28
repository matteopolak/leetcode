class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>> &intervals,
														 vector<int> &newInterval) {
		vector<vector<int>> res;
		bool merged = false;

		if (intervals.size() == 0) {
			res.push_back(newInterval);

			return res;
		}

		for (vector<int> interval : intervals) {
			if (newInterval[1] < interval[0]) {
				if (!merged) {
					res.push_back(newInterval);
					merged = true;
				}

				res.push_back(interval);
			} else if (newInterval[0] > interval[1]) {
				res.push_back(interval);
			} else {
				newInterval[0] = min(interval[0], newInterval[0]);
				newInterval[1] = max(interval[1], newInterval[1]);
			}
		}

		if (!merged) {
			res.push_back(newInterval);
		}

		return res;
	}
};
