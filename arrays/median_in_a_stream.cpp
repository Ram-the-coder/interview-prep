/*
    Given an input stream of N integers. 
    The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.
    Example:
    Input:
    4
    5
    15
    1 
    3
    Output:
    5
    10
    5
    4
*/

/*
    Solution 1
    Time Complexity: O(n^2)
    Space Complexity: O(n)
*/
void insert(vector<int> &a, int x) {
    for(int i=0; i<a.size(); ++i) {
        if(a[i] < x) continue;
        a.insert(a.begin()+i, x);
        return;
    }
    a.push_back(x);
}  

int main() {
	fastio;

	lld n, x;

    cin >> n;
    vector<int> a;
    for(int i=0; i<n; ++i) {
        cin >> x;
        insert(a, x);
        cout << ( !(a.size() % 2) ? (a[a.size()/2] + a[a.size()/2 - 1]) / 2 : a[a.size()/2] ) << '\n';
    }
	return 0;
}


/*
    Solution 2 - Heaps
    Time Complexity: O(nlogn)
    Space Complexity: O(n)
    
    Logic:
    We can use a max heap on left side to represent elements that are less than effective median, 
    and a min heap on right side to represent elements that are greater than effective median.

    After processing an incoming element, the number of elements in heaps differ utmost by 1 element. 
    When both heaps contain same number of elements, we pick average of heaps root data as effective median. 
    When the heaps are not balanced, we select effective median from the root of heap containing more elements.
*/

int main() {
	fastio;

	lld n, x;

    cin >> n;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int median = 0;
    for(int i=0; i<n; ++i) {
        cin >> x;
        if(x <= median) {
            left.push(x);
            if(left.size() - right.size() > 1) {
                int top = left.top();
                left.pop();
                right.push(top);
            }
        } else {
            right.push(x);
            if(right.size() - left.size() > 1) {
                int top = right.top();
                right.pop();
                left.push(top);
            }
        }

        if(left.size() == right.size())
            median = (left.top() + right.top()) / 2;
        else
            median = (left.size() > right.size()) ? left.top() : right.top();

        cout << median << '\n';
    }
	return 0;
}