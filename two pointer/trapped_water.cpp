/*
	Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. 
	Compute how much water can be trapped in between blocks after raining.
*/

/*
	Solution 1
	Time Complexity: O(n)
	Space Complexity: O(n)
*/

lld trapped_water(vll &a) {
	vll max_left(a.size()), max_right(a.size());

	lld amt_of_water = 0, diff;

	for(lld i=0; i<a.size(); ++i) {
		max_left[i] = (i == 0) ? a[i] : max(max_left[i-1], a[i]);
	}   

	for(lld i=a.size()-1; i>=0; --i) {
		max_right[i] = (i == a.size()-1) ? a[i] : max(max_right[i+1], a[i]);
		diff = min(max_left[i], max_right[i]) - a[i];
		amt_of_water += diff > 0 ? diff : 0;
	}   

	return amt_of_water;
}

/*
	Solution 2
	Time complexity: O(n)
	Space complexity: O(1)
*/
lld trapped_water(vll &a) {

	lld amt_of_water = 0, left = 0, right = a.size()-1, min_height = LLONG_MAX;

	while(left < right) {
		if(a[left] < a[right]) {
			min_height = a[left];
			while(a[++left] <= min_height && left < right) {
				amt_of_water += min_height - a[left];
			}
		} else {
			min_height = a[right];
			while(a[--right] <= min_height && left < right) {
				amt_of_water += min_height - a[right];
			}
		}
	}

	return amt_of_water;
}