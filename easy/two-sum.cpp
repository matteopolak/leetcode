class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		std::map<int, int> m;
		std::vector<int> out;

		int i = 0;

		for (int n : nums) {
			auto p = m.find(n);

			if (p != m.end()) {
				out.push_back(p->second);
				out.push_back(i);

				break;
			}

			m[target - n] = i++;
		}

		return out;
	}
};
