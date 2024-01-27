/**
 * @param {number[]} nums
 * @return {number}
 */
var averageValue = function (nums) {
	const [sum, count] = nums.reduce((a, b) => {
		if (b % 3 === 0 && b % 2 === 0) {
			a[1]++;
			a[0] += b;
		}

		return a;
	}, [0, 0]);

	return count === 0 ? 0 : Math.floor(sum / count);
};
