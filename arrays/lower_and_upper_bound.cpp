// Returns the index of the greatest element that is smaller than key in the sorted array a.
int predecessor(vector<int> &a, int key) {
    int low = 0, high = a.size()-1, mid, ans = -1;

    while(low <= high) {

        mid = (low + high) / 2;

        if(key <= a[mid]) {
            high = mid - 1;
            continue;
        }

        low = mid + 1;
        ans = mid;
    }

    return ans;
}

// Returns the index of the first element that is stricty greater than key in the sorted array a.
int upper_bound(vector<int> &a, int key) {
    int low = 0, high = a.size()-1, mid, ans = -1;
    while(low <= high) {
        mid = (high + low) / 2;
        if(key >= a[mid]) {
            low = mid + 1;
            continue;
        }

        ans = mid;
        high = mid - 1;
    }
    return ans;
}

// Returns the index of the first element that is greater than or equal to key in the sorted array a.
int lower_bound(vector<int> &a, int key) {
    int low = 0, high = a.size()-1, mid, ans = -1;
    while(low <= high) {
        mid = (high+low)/2;
        if(key <= a[mid]) {
            ans = mid;
            high = mid-1;
            continue;
        }

        low = mid + 1;
    }
    return ans;
}