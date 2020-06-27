int merge(vector<int> &a, int s1, int m, int e2) {
    int e1 = m, s2 = m+1;
    int count = 0;
    
    vector<int> merged_array(e2-s1 + 1);

    int i = s1, j = s2, k = 0;
    
    while(i <= e1 && j <= e2) {
        if(a[i] < a[j]) {
            merged_array[k++] = a[i++];
        } else {
            merged_array[k++] = a[j++];
            count += e1 - i + 1;
        }
    }
    
    while(i <= e1) {
        merged_array[k++] = a[i++];
    }
    
    while(j <= e2) {
        merged_array[k++] = a[j++];
    }
    
    for(int i=s1, k=0; i <= e2; ++i, ++k) {
        a[i] = merged_array[k];
    }
    
    return count;
}

int merge_sort(vector<int> &a, int start, int end) {
    if(start == end) return 0;
    int mid = (start + end) / 2;
    int count = 0;
    count += merge_sort(a, start, mid);
    count += merge_sort(a, mid+1, end);
    count += merge(a, start, mid, end);
    return count;
}

int find_number_of_inversions(vector<int> &a) {
    return merge_sort(a, 0, a.size()-1);
}