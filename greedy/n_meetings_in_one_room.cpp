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

class Meeting {
public:
	lld start, finish, meeting_no;

	Meeting(lld n) : meeting_no(n) {}
};

void find_max_meetings(vector<Meeting> &meetings) {

	vector<Meeting> res;

	// Sort by finish time
	sort(meetings.begin(), meetings.end(), [](const Meeting &m1, const Meeting &m2) -> bool {
		return m1.finish < m2.finish;
	});

	// Find the meetings
	lld last_meeting_finish_time = meetings[0].finish;
	res.pb(meetings[0]);

	for(lld i=1; i<meetings.size(); ++i) {
		if(meetings[i].start >= last_meeting_finish_time) {
			last_meeting_finish_time = meetings[i].finish;
			res.pb(meetings[i]);
		}
	}

	// Output
	for(lld i=0; i<res.size(); ++i)
		cout << res[i].meeting_no << " ";
	cout << '\n';


}

int main() {
	fastio;

	lld t;
	lld n;

	cin >> t;

	while(t--) {
		cin >> n;
		vector<Meeting> meetings;
		lld time;

		for(lld i=0; i<n; ++i) {
			cin >> time;
			Meeting temp(i+1);
			temp.start = time;
			meetings.pb(temp);
		}

		for(lld i=0; i<n; ++i) {
			cin >> time;
			meetings[i].finish = time;
		}

		find_max_meetings(meetings);
	}
	return 0;
}