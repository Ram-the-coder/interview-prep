#include <bits/stdc++.h>
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

void merge_without_extra_space(vll &a, vll &b) {
    // Since b is already sorted, we can consider it as a min-heap
    // Starting from the minimum element in a, if the min-element in b
    // is smaller than a[i], then swap that min-element to a[i] and push the
    // element that was in a[i] into the min-heap b
    for(lld i=0; i<a.size(); ++i) {
        if(a[i] > b[0]) {
            pop_heap(b.begin(), b.end(), greater<int>()); // Removes the min element from the heap and moves it to the end of the container
            swap(a[i], b[b.size()-1]); // Swap a[i] and the min-element of the heap
            push_heap(b.begin(), b.end(), greater<int>()); // Inserts the element at the end of the container into the heap
        }
    }

    sort_heap(b.begin(), b.end());
}

int main() {
    fastio;

    lld t;

    cin >> t;

    while(t--) {
        lld x, y;
        cin >> x >> y;
        vll a(x), b(y);
        ipv(a);
        ipv(b);
        merge_without_extra_space(a, b);
        for(lld i=0; i<a.size(); ++i) cout << a[i] << " ";
        for(lld i=0; i<b.size(); ++i) cout << b[i] << " ";
        cout << '\n';
    }
    return 0;
}