/*
    We are given a row wise sorted matrix of size r*c, 
    we need to find the median of the matrix given. 
    It is assumed that r*c is always odd.
*/

// Solution 1
// Time complexity: O(r^2 * c)
// Space complexity: O(r)
int matrix_median(vector<vector<int>> &a, int r, int c) {
    vector<int> ptr(r, -1);
    int median_index = (r*c)/2 + 1;
    int median = -1;
    for(int i=0; i<median_index; ++i) {
        int next_min = 0;
        for(int j=1; j<r; ++j) {
            if(ptr[j] == c-1) continue;
            if(a[j][ptr[j]+1] < a[next_min][ptr[next_min]+1]) next_min = j;
        }
        ptr[next_min]++;
        median = a[next_min][ptr[next_min]];
    }
    return median;
}

// Solution 2
// Time complexity: O(log(MAX_NUMBER) * r * logc)
// Space complexity: O(1)
int matrix_median(vector<vector<int>> &a, int r, int c) {
    // Find the range of the numbers in the matrix
    // left - lowest number
    // right - highest number
    int left = a[0][0], right = a[0][c-1], mid, num_elements_less_than_median = (r*c) / 2;

    for(int i=1; i<r; ++i) {
        left = min(left, a[i][0]);
        right = max(right, a[i][c-1]);
    }

    while(left < right) {
        mid = (left + right) / 2;

        // Find number of elements less than or equal to mid
        int count_le = 0; // no. of elements less than or equal to mid
        for(int i=0; i<r; ++i) count_le += (upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin());

        if(count_le <= num_elements_less_than_median) left = mid + 1;
        else right = mid;
    }

    return left;
}