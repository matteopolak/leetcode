impl Solution {
	pub fn merge_alternately(word1: String, word2: String) -> String {
		let mut l = word1.chars();
		let mut r = word2.chars();

		let mut o = String::with_capacity(word1.len() + word2.len());

		loop {
			let l = l.next();
			let r = r.next();

			if let Some(l) = l {
				o.push(l);
			}

			if let Some(r) = r {
				o.push(r);
			}

			if l.is_none() && r.is_none() {
				break o;
			}
		}
	}
}
