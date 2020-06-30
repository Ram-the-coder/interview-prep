float fractional_knapsack(vector<pair<lld, lld>> items, lld max_capacity) {
	// Sort items based on value per unit weight
	sort(items.begin(), items.end(), [](const pair<lld, lld> &i1, const pair<lld, lld> &i2) -> bool {
		return i1.first * 1.0 / i1.second > i2.first * 1.0 / i2.second;
	});

	lld remaining_capacity = max_capacity;
	float max_value = 0;
	
	for(lld i=0; i<items.size() && remaining_capacity > 0; ++i) {
		if(items[i].second <= remaining_capacity) {
			max_value += items[i].first;
			remaining_capacity -= items[i].second;
		} else {
			max_value += remaining_capacity * items[i].first * 1.0 / items[i].second;
			remaining_capacity = 0;
		}
	}

	return max_value;
}