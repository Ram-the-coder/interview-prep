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

	lld t, n, top, val;

	cin >> t;

	while(t--) {
		cin >> n;
		stack<pair<lld, lld>> stk;
        
		vll greaterEl(n, -1);
		
		for(lld i=0; i<n; ++i) {
		    cin >> val;
		    while(!stk.empty() && stk.top().second < val) {
		        greaterEl[stk.top().first] = val;
		        stk.pop();
		    }
		    
		    stk.push({i, val});
		}
		
		dispv(greaterEl);
	}
	return 0;
}