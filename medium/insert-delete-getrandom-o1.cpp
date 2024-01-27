class RandomizedSet {
public:
	RandomizedSet() {}

	bool insert(int val) {
		bool inserted = this->set.insert({val, vec.size()}).second;

		if (inserted) {
			vec.push_back(val);
		}

		return inserted;
	}

	bool remove(int val) {
		if (this->set.count(val) == 0)
			return false;

		int idx = this->set[val];

		this->vec[idx] = this->vec[this->vec.size() - 1];
		this->vec.pop_back();

		this->set[this->vec[idx]] = idx;
		this->set.erase(val);

		return true;
	}

	int getRandom() { return this->vec[rand() % this->vec.size()]; }

private:
	unordered_map<int, int> set;
	vector<int> vec;
};
