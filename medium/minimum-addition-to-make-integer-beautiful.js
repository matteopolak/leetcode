/**
 * @param {number} n
 * @param {number} target
 * @return {number}
 */
var makeIntegerBeautiful = function (n, target) {
	const n0 = n;
	let i = 0;

	for (; getDigitSum(n) > target; ++i) {
		n = Math.floor(n / 10) + 1
	}

	return n * (10 ** i) - n0;
};

var getDigitSum = function (n) {
	return n.toString().split('').reduce((a, b) => a + parseInt(b), 0);
}
