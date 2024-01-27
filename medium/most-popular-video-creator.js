/**
 * @param {string[]} creators
 * @param {string[]} ids
 * @param {number[]} views
 * @return {string[][]}
 */
var mostPopularCreator = function (creators, ids, views) {
	const byCreator = new Map();

	let highest = 0;

	for (const [i, creator] of creators.entries()) {
		if (byCreator.has(creator)) {
			const data = byCreator.get(creator);

			data.views += views[i];

			if (data.highest < views[i] || (data.highest === views[i] && data.highestId > ids[i])) {
				data.highest = views[i];
				data.highestId = ids[i];
			}
		} else {
			byCreator.set(creator, {
				views: views[i],
				highest: views[i],
				highestId: ids[i],
				id: creator,
			});
		}

		highest = Math.max(byCreator.get(creator).views, highest);
	}

	return [...byCreator.values()].filter(c => c.views === highest).map(c => [c.id, c.highestId]);
};
