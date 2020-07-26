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

/*
    All pairs shortest path algorithm
    DP Algorithm
    Time Complexity: O(V^3)
    Space Complexity: O(V^2) - adjacency matrix representation
*/
void floyd_warshall(vector<vector<int>> &dist) {
    const int v = dist.size();
    for(int k=0; k<v; ++k) {
        for(int i=0; i<v; ++i) {
            for(int j=0; j<v; ++j) {
                if(dist[k][j] > 1e7 - dist[i][k]) continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
	fastio;

	lld t;
    int v;

	cin >> t;

	while(t--) {
		cin >> v;
        vector<vector<int>> sp(v, vector<int>(v));
        for(int i=0; i<v; ++i) {
            for(int j=0; j<v; ++j) {
                cin >> sp[i][j];
            }
        }
        
        floyd_warshall(sp);

        for(int i=0; i<v; ++i) {
            for(int j=0; j<v; ++j) {
                if(sp[i][j] == 1e7) cout << "INF ";
                else cout << sp[i][j] << " ";
            }
            cout << '\n';
        }
	}
	return 0;
}