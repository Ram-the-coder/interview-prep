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

// Kadane's Algorithm to find the largest sum contiguous subarray
lld maxSum(vll &a) {
    lld max_so_far = a[0]; 
    lld cur_max = a[0]; 
  
   for (lld i = 1; i < a.size(); ++i) 
   { 
        cur_max = max(a[i], cur_max + a[i]); 
        max_so_far = max(max_so_far, cur_max); 
   } 
   return max_so_far; 
}

int main() {
	fastio;

	lld t;
	lld n;

	cin >> t;

	while(t--) {
		cin >> n;
		vll a(n);
		ipv(a);
		cout << maxSum(a) << '\n';
	}
	return 0;
}