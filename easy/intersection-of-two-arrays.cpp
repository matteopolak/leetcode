class Solution {
public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
		vector<int> res;

		unordered_set<int> n1;
		unordered_set<int> n2;

		for (int n : nums1) {
			n1.insert(n);
		}

		for (int n : nums2) {
			if (!n2.count(n) && n1.count(n)) {
				res.push_back(n);
			}

			n2.insert(n);
		}

		return res;
	}
};
