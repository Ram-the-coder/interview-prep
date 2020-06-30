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

class Job {
public:
	lld id, deadline, profit;

	Job(): id(-1) {}

	Job(lld i, lld d, lld p) : id(i), deadline(d), profit(p) {}
};

/*
	Solution 1
	Time Complexity: O(n^2)
	Space Complexity: O(MAX_DEADLINE_VALUE)
*/
vector<lld> _max_profit(vector<Job> &jobs) {

	// Find the max deadline
	lld max_deadline = jobs[0].deadline;
	for(lld i=1; i<jobs.size(); ++i)
		max_deadline = max(max_deadline, jobs[i].deadline);

	// Sort jobs by profit
	sort(jobs.begin(), jobs.end(), [](const Job &j1, const Job &j2) -> bool {
		return j1.profit > j2.profit;
	});

	vector<lld> time_slot(max_deadline+1, -1);

	lld jobs_done = 0, profit = 0;

	for(lld i=0; i<jobs.size(); ++i) {
		// Assign the job to a time slot that is within its deadline
		// If no slot is preset, that job won't be done
		for(lld ts = jobs[i].deadline; ts >= 1; --ts) {
			if(time_slot[ts] == -1) {
				time_slot[ts] = jobs[i].id;
				jobs_done++;
				profit += jobs[i].profit;
				break;
			}
		}
	}

	return vector<lld> {jobs_done, profit};
}

/*
	Solution 2
	Time Complexity: O(nlogn)
	Space Complexity: O(MAX_DEADLINE_VALUE)
*/

class DisjointSet {

	vector<lld> parent;

	public:

	DisjointSet(lld n) {
		parent.resize(n+1);
		for(lld i=0; i < n+1; ++i) parent[i] = i;
	}

	lld find(lld s) {
		if(s == parent[s]) return s;
		return parent[s] = find(parent[s]);
	}

	void merge(lld u, lld v) {
		parent[v] = u;
	}
};

vector<lld> max_profit(vector<Job> &jobs) {
	// Find the max deadline
	lld max_deadline = jobs[0].deadline;
	for(lld i=1; i<jobs.size(); ++i)
		max_deadline = max(max_deadline, jobs[i].deadline);

	// Sort jobs by profit
	sort(jobs.begin(), jobs.end(), [](const Job &j1, const Job &j2) -> bool {
		return j1.profit > j2.profit;
	});

	DisjointSet ds(max_deadline);

	lld jobs_done = 0, profit = 0;
	for(lld i=0; i<jobs.size(); ++i) {
		// Find the maximum available free slot for 
        // this job (corresponding to its deadline) 
		lld available_slot = ds.find(jobs[i].deadline);

		// If maximum available free slot is greater 
        // than 0, then free slot available 
		if(available_slot > 0) {
			jobs_done++;
			profit += jobs[i].profit;
			ds.merge(ds.find(available_slot - 1), available_slot);
			// This slot is taken by this job 'i' 
            // so we need to update the greatest  
            // free slot. Note that, in merge, we  
            // make first parameter as parent of  
            // second parameter. So future queries 
            // for availableSlot will return maximum 
            // available slot in set of  
            // "availableSlot - 1" 
		}
	}

	return vector<lld> {jobs_done, profit};
}

int main() {
	fastio;

	lld t;
	lld n;

	cin >> t;

	while(t--) {
		cin >> n;
		vector<Job> jobs;

		lld id, deadline, profit;
		for(lld i=0; i<n; ++i) {
			cin >> id >> deadline >> profit;
			Job temp(id, deadline, profit);
			jobs.pb(temp);
		}

		vector<lld> res = max_profit(jobs);

		cout << res[0] << " " << res[1] << '\n';
	}
	return 0;
}