class RandomizedCollection {
public:
	RandomizedCollection() { srand(time(nullptr)); }

	bool insert(int val) {
		vec.push_back(val);
		map[val].insert(vec.size() - 1);

		return map[val].size() == 1;
	}

	bool remove(int val) {
		if (map[val].empty())
			return false;

		int index = *map[val].begin();
		map[val].erase(index);

		if (index != vec.size() - 1) {
			int last = vec.back();
			vec[index] = last;
			map[last].erase(vec.size() - 1);
			map[last].insert(index);
		}

		vec.pop_back();

		return true;
	}

	int getRandom() { return vec[rand() % vec.size()]; }

private:
	unordered_map<int, unordered_set<int>> map;
	vector<int> vec;
};
