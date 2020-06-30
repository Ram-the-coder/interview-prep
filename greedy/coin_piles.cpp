/*
	There are N piles of coins each containing  Ai (1<=i<=N) coins.  

	Now, you have to adjust the number of coins in each pile such that for any two pile, 
	if a be the number of coins in first pile and b is the number of coins in second pile then |a-b|<=K. 

	In order to do that you can remove coins from different piles to decrease the number of coins in those piles 
	but you cannot increase the number of coins in a pile by adding more coins. 

	Now, given a value of N and K, along with the sizes of the N different piles 
	you have to tell the minimum number of coins to be removed in order to satisfy the given condition.

	Note: You can also remove a pile by removing all the coins of that pile.
*/

/* 
	Solution 1
	Time Complexity: O(n^2)
	Space Complexity: O(1)
*/

lld get_min_coins_to_remove(vll &pile_height, lld k) {
	lld min_coins_to_remove = LLONG_MAX;

	for(lld remove_until = 0; remove_until < pile_height.size(); ++remove_until) {
		// remove all piles completely whose height is less than pile_height[remove_until]
		lld coins_to_remove = 0, diff;

		for(lld i=0; i<pile_height.size(); ++i) {
			diff = pile_height[i] - pile_height[remove_until];

			if(diff < 0) coins_to_remove += pile_height[i];
			else if(diff > k) coins_to_remove += diff - k;
		}	

		min_coins_to_remove = min(min_coins_to_remove, coins_to_remove);
	}
	

	return min_coins_to_remove;
}


/* 
	Solution 2
	Time Complexity: O(nlogn)
	Space Complexity: O(1)
*/
lld get_min_coins_to_remove(vll &pile_height, lld k) {
	lld min_coins_to_remove = LLONG_MAX;

	sort(pile_height.begin(), pile_height.end());

	for(lld remove_until = 0, coins_removed_as_piles = 0;
	 	remove_until < pile_height.size(); 
	 	coins_removed_as_piles += pile_height[remove_until++]) {

		// remove all piles completely whose height is less than pile_height[remove_until]
		// The sum of coins in piles that have been removed (as their height is less than pile_height) 
		// is present in coins_removed_as_piles

		lld coins_to_remove = coins_removed_as_piles, diff;

		for(lld i=remove_until; i<pile_height.size(); ++i) {
			diff = pile_height[i] - pile_height[remove_until];
			if(diff > k) coins_to_remove += diff - k;
		}	

		min_coins_to_remove = min(min_coins_to_remove, coins_to_remove);
	}
	

	return min_coins_to_remove;
}