/* Problem: To rotate a matrix in-place by 90 degrees in anti-clockwise direction*/

/* SOLUTION 1 */

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

// Rotates the ith element i in the square submatrix that is at 'off' offset distance inside the matrix a
void _rotate(vvll &a, lld off, lld i) {
	lld n = a.size();
	lld temp = a[off][i+off];
	a[off][i+off] = a[i+off][n-1-off];
	a[i+off][n-1-off] = a[n-1-off][n-1-off-i];
	a[n-1-off][n-1-off-i] = a[n-1-off-i][off];
	a[n-1-off-i][off] = temp;	
}

void rotate(vvll &a) {
	lld n = a.size();
	for(lld off=0; off<ceil(n/2.0); ++off) {
		// Rotate the submatrix that is at 'off' offset distance inside the matrix a
		for(lld i=0; i<n-(2*off)-1; ++i) {
			_rotate(a, off, i);
		}
	}
}

int main() {
	fastio;

	lld t;
	lld n;

	cin >> t;

	while(t--) {
		cin >> n;
		vvll a(n, vll(n));
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				cin >> a[i][j];

		rotate(a);
		for(lld i=0; i<n; ++i)
			for(lld j=0; j<n; ++j)
				cout << a[i][j] << " ";
		cout << '\n';
	}
	return 0;
}

/* SOLUTION 2 */
// Take transpose of matrix and reverse the columns
