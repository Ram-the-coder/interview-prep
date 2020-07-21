/*
    Given an array of integers that might contain duplicates, return all possible subsets.

    Note:
    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.
    The subsets must be sorted lexicographically.
*/

/******************** Solution 1 ********************/
void get_unique_subsets(vii &a, int start, vii &subset, vvii &subsets) {
    
    if(start >= a.size()) {
        subsets.push_back(subset);
        return;
    }
    
    subset.push_back(a[start]);
    get_unique_subsets(a, start+1, subset, subsets);
    subset.pop_back();

    ++start;
    while(start < a.size() && a[start] == a[start-1]) ++start;

    get_unique_subsets(a, start, subset, subsets);
}

int main() {
	fastio;

	lld t;
	lld n;

	cin >> t;

	while(t--) {
		cin >> n;
		vii a(n);
		ipv(a);
		vvii subsets;
		vii s;
		sort(a.begin(), a.end());
		get_unique_subsets(a, 0, s, subsets);
		sort(subsets.begin(), subsets.end(), [](const vector<int> &a, const vector<int> &b)->bool {
            for(int i=0; i<a.size() && i<b.size(); ++i) {
                if(a[i] < b[i]) return true;
                else if(a[i] > b[i]) return false;
            }
            return a.size() < b.size();
        });
        
        for(int i=0; i<subsets.size(); ++i) {
            cout << "(";
            bool first = true;
            for(int j=0; j<subsets[i].size(); ++j) {
                cout << (first ? "" : " ") << subsets[i][j];
                first = false;
            }
            cout << ")";
        }
        cout << '\n';
	}
	return 0;
}



/******************** Solution 2 ********************/
void print_subset(vii &subset) {
    cout << "(";
    if(subset.size() > 0) {
        cout << subset[0];
        for(int j=1; j<subset.size(); ++j) {
            cout << ' ' << subset[j];
        }    
    }
    cout << ")";
}

void print_unique_subsets(vii &a, int start, vii &subset) {
    
    if(start >= a.size()) return;
    
    // Include a[start] in subset
    subset.push_back(a[start]);
    print_subset(subset); // Whenever a new element is added print the subset
    print_unique_subsets(a, start+1, subset);
    subset.pop_back();

    // Do not include any a[i] for all i >= start && a[i] == a[start], in the subset
    // Go to the next new element
    ++start;
    while(start < a.size() && a[start] == a[start-1]) ++start;
    
    print_unique_subsets(a, start, subset);
}

int main() {
	fastio;

	lld t;
	lld n;

	cin >> t;

	while(t--) {
		cin >> n;
		vii a(n);
		ipv(a);
		vvii subsets;
		vii s;
		sort(a.begin(), a.end());
		cout << "()"; // Empty set
		print_unique_subsets(a, 0, s);
        cout << '\n';   
	}
	return 0;
}