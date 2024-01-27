
class Solution {
public:
	vector<int> gridIllumination(int n, vector<vector<int>> &lamps,
															 vector<vector<int>> &queries) {
		// 0: not illuminated
		// 1: illuminated

		vector<int> result;
		unordered_map<int, int> row;
		unordered_map<int, int> col;
		unordered_map<int, int> diag1;
		unordered_map<int, int> diag2;
		unordered_map<int, unordered_map<int, bool>> lamp;

		for (auto &l : lamps) {
			if (lamp[l[0]][l[1]])
				continue;

			int x = l[0];
			int y = l[1];

			row[x]++;
			col[y]++;
			diag1[x + y]++;
			diag2[x - y]++;

			lamp[x][y] = true;
		}

		for (auto &q : queries) {
			int x = q[0];
			int y = q[1];

			if (row[x] > 0 || col[y] > 0 || diag1[x + y] > 0 || diag2[x - y] > 0) {
				result.push_back(1);

				for (int i = x - 1; i <= x + 1; i++) {
					for (int j = y - 1; j <= y + 1; j++) {
						if (i < 0 || i >= n || j < 0 || j >= n)
							continue;

						if (lamp[i][j]) {
							lamp[i][j] = false;

							row[i]--;
							col[j]--;
							diag1[i + j]--;
							diag2[i - j]--;
						}
					}
				}
			} else {
				result.push_back(0);
			}
		}

		return result;
	}
};
