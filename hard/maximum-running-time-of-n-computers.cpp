#include <algorithm>
#include <cstdio>
#include <vector>

class Solution {
public:
	long long maxRunTime(int n, std::vector<int> &batteries) {
		if (batteries.empty() || batteries.size() < n)
			return 0;

		long long total = 0;
		// get lowest battery with linear search, since batteres is NOT sorted
		long long start = INT64_MAX;

		for (int battery : batteries) {
			total += battery;
			if (battery < start)
				start = battery;
		}

		long long end = total / n;
		long long result = 0;

		while (start <= end) {
			long long mid = start + (end - start) / 2;

			if (canRun(n, batteries, mid)) {
				start = mid + 1;
				result = mid;
			} else {
				end = mid - 1;
			}
		}

		return result;
	}

private:
	bool canRun(int n, std::vector<int> &batteries, long long mid) {
		long long count = 0;
		long long needed = mid * n;

		for (int battery : batteries) {
			count += std::min((long long)battery, mid);

			if (count >= needed)
				return true;
		}

		return false;
	}
};
