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

void BFS(vector<vector<int>> &adjacency, lld n, lld start_vertex) {
    queue<lld> q;
    q.push(start_vertex);
    vector<int> visited(n, 0);

    while(!q.empty()) {

        lld node = q.front();
        q.pop();
        if(visited[node]) continue;
        visited[node] = 1;
        cout << node << " ";

        for(lld i=0; i<n; ++i) {
            if(!visited[i] && adjacency[node][i]) {
                q.push(i);
            }
        }
    }

    cout << '\n';
}

int main() {
	fastio;

	lld t;
	lld n, e;

	cin >> t;

	while(t--) {
		cin >> n >> e;

		vector<vector<int>> adjacency(n, vector<int>(n, 0));

        lld u, v;

        for(lld i=0; i<e; ++i) {
            cin >> u >> v;
            adjacency[u][v] = 1;
        }

        BFS(adjacency, n, 0);
	}
	return 0;
}