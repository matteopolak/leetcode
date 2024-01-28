class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		vector<vector<int>> ans;

		if (intervals.size() == 0)
			return ans;
		sort(intervals.begin(), intervals.end());

		// end of the previous interval
		int s = intervals[0][0];
		int e = intervals[0][1];

		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i][0] > e) {
				// make interval
				ans.push_back(make_interval(s, e));

				s = intervals[i][0];
				e = intervals[i][1];
			} else {
				e = max(e, intervals[i][1]);
			}
		}

		ans.push_back(make_interval(s, e));

		return ans;
	}

	vector<int> make_interval(int s, int e) {
		vector<int> intv(2);

		intv[0] = s;
		intv[1] = e;

		return intv;
	}
};
