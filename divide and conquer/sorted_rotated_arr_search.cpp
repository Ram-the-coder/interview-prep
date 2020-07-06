/*
    Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. 
    The task is to find the index of the given element K in the array A.
    Expected Time Complexity: O(logn)
*/

lld get_pivot(vll &a) {
    lld low = 0, high = a.size()-1, mid;
    if(a.size() == 1) return 0;

    while(low <= high) {
        mid = (high + low) / 2;
        if(a[mid] < a[(mid + a.size() - 1) % a.size()]) return mid;
        if(a[low] < a[high]) return low;
        if(a[low] > a[mid]) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

lld binary_search_get_index(vll &a, lld start, lld end, lld k) {
    lld low = start, high = end, mid;

    while(low <= high) {
        mid = (high + low) / 2;
        if(a[mid] == k) return mid;
        if(a[mid] < k) low = mid + 1;
        else high = mid - 1;
    }   

    return -1;
}

lld find_el_in_sorted_rotated_arr(vll &a, lld k) {
    lld pivot = get_pivot(a);
    lld index = binary_search_get_index(a, 0, pivot-1, k);
    if(index == -1) {
        index = binary_search_get_index(a, pivot, a.size()-1, k);
    }
    return index;
}