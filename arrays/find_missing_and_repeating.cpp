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

template <class T>
void swap(vector<T> a, lld i, lld j) {
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

/* Given an unsorted array of size N of positive integers. 
Atleast one number 'A' from set {1, 2, …N} is missing and atleast one number 'B' occurs twice in array. 
Find these two numbers.
Expected solution is O(n) time and constant extra space.

Solution:
Since it is not said that the array should not be modified, we'll modify
the element to indicate that we've seen it

The key here is to denote that we've seen an element by negating it
instead of doing something like setting it to -1
Negating it ensures that its value is not lost
So whatever element it points to still remains 
*/

void find_missing_and_repeating(vll &a) {
	lld missing = LLONG_MAX, repeating = LLONG_MAX;
	for(lld i=0; i<a.size(); ++i) {

		if(a[abs(a[i]) - 1] < 0)
			repeating = min(repeating, abs(a[i]));
		else
			a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
	}

	for(lld i=0; i<a.size(); ++i) {
		if(a[i] > 0) missing = min(missing, i+1);
	}

	cout << repeating << " " << missing << '\n';
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
		find_missing_and_repeating(a);
	}
	return 0;
}