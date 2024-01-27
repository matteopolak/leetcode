class Solution {
public:
	string addBinary(string a, string b) {
		int carry = 0;
		string out = "";

		int ai = a.size() - 1;
		int bi = b.size() - 1;

		while (ai >= 0 || bi >= 0) {
			int ac = ai >= 0 && a[ai] == '1' ? 1 : 0;
			int bc = bi >= 0 && b[bi] == '1' ? 1 : 0;

			int s = ac + bc + carry;

			if (s == 0) {
				out += '0';
				carry = 0;
			} else if (s == 1) {
				out += '1';
				carry = 0;
			} else if (s == 2) {
				out += '0';
				carry = 1;
			} else if (s == 3) {
				out += '1';
				carry = 1;
			}

			--ai;
			--bi;
		}

		if (carry == 1) {
			out += '1';
		}

		reverse(out.begin(), out.end());

		return out;
	}
};
