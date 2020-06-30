/*
	Given arrival and departure times of all trains that reach a railway station. 
	Your task is to find the minimum number of platforms required for the railway station so that no train waits.

	Note: Consider that all the trains arrive on the same day and leave on the same day. 
	Also, arrival and departure times will not be same for a train, 
	but we can have arrival time of one train equal to departure of the other. 
	In such cases, we need different platforms, 
	i.e at any given instance of time, same platform can not be used for both departure of a train and arrival of another.
*/

/*
	Solution 1
	Time Complexity: O(MAX_TIME)
	Space Complexity: O(MAX_TIME)

	This solution is good when MAX_TIME is small
*/

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

int main() {
	fastio;

	lld t;
	lld n;

	cin >> t;

	while(t--) {
		cin >> n;
		
		lld time;
		vector<lld> status(60*24 + 1, 0); 
		// Status denotes the net number of trains arriving at that moment
		// Its negative if more trains are leaving than arriving

		for(lld i=0; i<n; ++i) {
			cin >> time;
			time = (time / 100) * 60 + (time % 100); // convert time in HHMM format into absolute minutes
			status[time]++;
		}

		for(lld i=0; i<n; ++i) {
			cin >> time;
			time = (time / 100) * 60 + (time % 100);
			status[time+1]--;
		}

		lld min_platforms = 0, current_no_trains = 0;
		for(lld i=0; i <= 60*24; ++i) {	
			current_no_trains += status[i];
			min_platforms = max(min_platforms, current_no_trains);
		}

		cout << min_platforms << '\n';
	}
	return 0;
}

/*
	Solution 2
	Time Complexity: O(nlogn)
	Space Complexity: O(n)

	This solution is good when MAX_TIME is large compared to n
*/

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

int main() {
	fastio;

	lld t;
	lld n;

	cin >> t;

	while(t--) {
		cin >> n;
		vll arrival(n), departure(n);
		
		ipv(arrival);
		ipv(departure);

		sort(arrival.begin(), arrival.end());
		sort(departure.begin(), departure.end());

		lld min_platforms = 1, current_no_trains = 1;

		lld i = 1, j = 0;
		while(i < n && j < n) {
			if(arrival[i] <= departure[j]) {
				current_no_trains++;
				i++;
			} else {
				current_no_trains--;
				j++;
			}

			min_platforms = max(min_platforms, current_no_trains);
		}

		cout << min_platforms << '\n';
	}
	return 0;
}