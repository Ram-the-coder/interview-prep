lld get_gcd(lld a, lld b) {
    if(b == 0) return a;
    return get_gcd(b, a%b);
}