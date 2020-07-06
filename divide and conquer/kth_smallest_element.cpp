/*
    Given an array arr[] and a number K where K is smaller than size of array, 
    the task is to find the Kth smallest element in the given array. 
    It is given that all array elements are distinct.
*/

// Solution 1 - Max Heap
// Time Complexity: O(k + (n-k)logk)
// Space Complexity: O(k)
lld kth_smallest_element(vll &a, lld k) {
    vll heap(a.begin(), a.begin()+k);
    make_heap(heap.begin(), heap.end());
    for(lld i=k; i<a.size(); ++i) {
        if(a[i] > heap.front()) continue;
        heap.push_back(a[i]);
        push_heap(heap.begin(), heap.end());
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
    }
    return heap.front();
}

// Solution 2 - Quick Sort
// Time Complexity: O(logn)
// Space Complexity: O(1)
lld partition(vll &a, lld low, lld high) {
    lld pivot = rand() % (high - low + 1);
    swap(a[low + pivot], a[high]);
    lld final_pivots_pos = low;
    for(lld i=low; i<high; ++i) {
        if(a[i] < a[high]) swap(a[final_pivots_pos++], a[i]);
    }
    swap(a[final_pivots_pos], a[high]);
    return final_pivots_pos;
}

lld kth_smallest_element(vll &a, lld k) {
    lld low = 0, high = a.size()-1;
    srand(time(0));
    while(low <= high) {
        lld pivot = partition(a, low, high);
        if(pivot == k - 1) return a[pivot];
        if(pivot < k - 1) low = pivot + 1;
        else high = pivot - 1;
    }
    return -1;
}