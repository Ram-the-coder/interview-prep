/*
    Given a sorted array A, size N, of integers; every element appears twice except for one. 
    Find that element that appears once in array.
    Find that element in O(log n) complexity.
*/

lld find_once_in_a_sorted_array(vll &a) {
    lld low = 0, high = a.size()-1, mid;

    while(low <= high) {
        mid = (high + low) / 2;

        // if a[mid] is not equal to any of its neighbors, then its the element that appears once
        if((mid == 0 || a[mid-1] != a[mid]) && (mid == a.size()-1 || a[mid+1] != a[mid] )) return a[mid];

        if(mid % 2 == 0) {
            // If mid is an even index and a[mid] == a[mid+1] 
            // then the element that appears once is to the right of mid
            // else it is to the left
            if(mid < a.size()-1 && a[mid] == a[mid+1]) low = mid + 1;
            else high = mid - 1;
        } else {
            // If mid is an odd index and a[mid] == a[mid-1] 
            // then the element that appears once is to the right of mid
            // else it is to the left
            if(mid > 0 && a[mid] == a[mid-1]) low = mid + 1;
            else high = mid - 1;
        }
    }

    return -1;
}
