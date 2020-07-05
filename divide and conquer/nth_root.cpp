/*
    You are given 2 numbers (N , M); the task is to find N√M (Nth root of M).
    Return nth root of m if the root is an integer, else return -1
*/

// compare a^b with m^n without exceeding the long long int range
int compare_apb_with_mpn(lld a, lld b, lld m_power_n) {
    lld power = a;
    for(lld i=1; i<b; ++i) {
        if(power > m_power_n) return 1;
        power *= a;
    }
    
    if(power == m_power_n) return 0;
    if(power < m_power_n) return -1;
    return 1;
    
}

// Time complexity: O(logn)
// Space complexity: O(1)
lld nth_root(lld m, lld n) {
    lld start = 0, end = m, mid, power;

    while(start <= end) {
        mid = (start + end) / 2;
        switch(compare_apb_with_mpn(mid, n, m)) {
            case 0: return mid;
            case 1: end = mid-1; break;
            case -1: start = mid+1; break;
            default: break;
        }
    }

    return -1;
}