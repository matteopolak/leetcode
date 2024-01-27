class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int extra = 0;
		int tank = 0;
		int start = 0;

		for (int i = 0; i < gas.size(); ++i) {
			extra += gas[i] - cost[i];
			tank += gas[i] - cost[i];

			if (tank < 0) {
				tank = 0;
				start = i + 1;
			}
		}

		return extra < 0 ? -1 : start;
	}
};
