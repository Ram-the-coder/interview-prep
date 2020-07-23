/*
    Given an input stream of n integers, find the kth largest element for each element in the stream.
    Example:
    Input:
    2
    4 6
    1 2 3 4 5 6
    1 2
    3 4

    Output:
    -1 -1 -1 1 2 3
    3 4 
*/

/*
    Solution
    Time Comlexity: O(nlogk)
    Space Complexity: O(k)
*/

int main() {
	fastio;

	lld t;
	lld k, n, x;

	cin >> t;

	while(t--) {
		cin >> k >> n;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(int i=0; i<n; ++i) {
            cin >> x;
            if(min_heap.size() < k) {
                min_heap.push(x);
                if(min_heap.size() == k) cout << min_heap.top() << ' ';
                else cout << "-1 ";
                continue;
            }

            if(x > min_heap.top()) {
                min_heap.push(x);
                min_heap.pop();
            }

            cout << min_heap.top() << ' ';
        }
		cout << '\n';
	}
	return 0;
}