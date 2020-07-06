/*
    Given two sorted arrays A and B of size M and N respectively and an element k. 
    The task is to find the element that would be at the k’th position of the final sorted array.
*/

// Solution - 1: 2 pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
lld kth_element1(vll &a, vll &b, lld k) {
    lld ap = -1, bp = -1, el = -1;
    while(k--) {
        if(ap == a.size() - 1) {
            el = b[++bp];
        } else if(bp == b.size() - 1) {
            el = a[++ap];
        } else {
            el = (a[ap+1] < b[bp+1]) ? a[++ap] : b[++bp];
        }
    }

    return el;
}

// Solution - 2 
// Time Complexity: O(logn + logm)
// Space Complexity: O(logn + logm) -> stack size
lld kth_element2(vll &a, vll &b, lld k, lld aLow, lld bLow, lld aHigh, lld bHigh) {
    // Base cases
    if(k == 1) return min(a[aLow], b[bLow]);
    if(aLow > aHigh) return b[bLow + k - 1];
    if(bLow > bHigh) return a[aLow + k - 1];

    lld aMid = (aHigh - aLow) / 2;
    lld bMid = (bHigh - bLow) / 2;
    
    return (aMid + bMid + 2 > k) 
        ? (a[aLow + aMid] > b[bLow + bMid]) ? kth_element(a, b, k, aLow, bLow, aLow + aMid - 1, bHigh) : kth_element(a, b, k, aLow, bLow, aHigh, bLow + bMid - 1)
        : (a[aLow + aMid] < b[bLow + bMid]) ? kth_element(a, b, k - aMid - 1, aLow + aMid + 1, bLow, aHigh, bHigh) : kth_element(a, b, k - bMid - 1, aLow, bLow + bMid + 1, aHigh, bHigh);
}   


// Solution - 3
// Time Complexity: O(logk) = O(log(m+n))
// Space Complexity: O(logk) = O(log(m+n)) -> Stack size
lld kth_element(vll &a, vll &b, lld k, lld aLow, lld aHigh, lld bLow, lld bHigh) {
    if(k > (aHigh - aLow + 1 + bHigh - bLow + 1) || k < 1) return -1;

    // let array a be smaller than b 
    if(aHigh - aLow > bHigh - bLow) return kth_element(b, a, k, bLow, bHigh, aLow, aHigh);

    // if s is empty returning k-th element of b 
    if(aLow > aHigh) return b[bLow + k - 1];

    // if k = 1 return minimum of first two elements of both arrays 
    if(k == 1) return min(a[aLow], b[bLow]);

    // now the divide and conquer part 
    lld i = min(aHigh-aLow+1, k / 2), j = min(bHigh-bLow+1, k / 2);

    return (a[aLow + i-1] < b[bLow + j-1]) 
                ? kth_element(a, b, k - i, aLow + i, aHigh, bLow, bHigh)
                : kth_element(a, b, k - j, aLow, aHigh, bLow + j, bHigh);
}