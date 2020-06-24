#include<bits/stdc++.h>
#define lld long long
#define vll vector<lld>
#define vvll vector<vector<lld>>
#define pb push_back
#define mp make_pair
#define ipv(v) for(lld i=0; i<v.size(); ++i) cin >> v[i]
#define dispv(v) for(lld i=0; i<v.size();++i) cout << v[i] << " "; cout << '\n'
#define dispa(a, n) for(lld i=0; i<n; ++i) cout << a[i] << " "; cout << '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
void merge_intervals(vector<pair<int, int>> &intervals) {
	// Sort the intervals by start time
	sort(intervals.begin(), intervals.end()); // By default vector of pairs is sorted by comparing pair.first
	lld index = 0; // Store the index of the last element in the output array (modified intervals array)

	// Starting from the second interval, check if the current interval overlaps with the last interval
	// The key point to note is that, if intervals[i] doesn't overlap with intervals[i-1] then intervals[i+k] will not
	// overlap with intervals[i-1] because the start time of intervals[i+k] is greater than that of intervals[i]
	for(lld i=1; i<intervals.size(); ++i) {
		if(intervals[index].second >= intervals[i].first) {
			// Overlap
			intervals[index].first = min(intervals[index].first, intervals[i].first);
			intervals[index].second = max(intervals[index].second, intervals[i].second);
		} else {
			// No overlap
			intervals[++index] = intervals[i];
		}
	}


	// Output the merged intervals
	for(lld i=0; i<=index; ++i) {
		cout << intervals[i].first << ' ' << intervals[i].second << ' ';
	}
	cout << '\n';

}

int main() {
	fastio;

	lld t;
	lld n, s, e;

	cin >> t;

	while(t--) {
		cin >> n;
		vector<pair<int, int>> intervals;
		for(lld i=0; i<n; ++i) {
		    cin >> s >> e;
		    intervals.pb({s, e});
		}

		merge_intervals(intervals);
	}
	return 0;
}