class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> found;
		vector<string> result;

		if (s.size() < 10)
			return result;

		for (int i = 0; i <= s.size() - 10; ++i) {
			string ss = s.substr(i, 10);

			if (found[ss]++ == 1) {
				result.push_back(ss);
			}
		}

		return result;
	}
};
