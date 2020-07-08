/*
    Given an string in roman no format (s)  your task is to convert it to integer .
*/

/*
    Solution
    Time Complexity: O(n)
    Space Complexity: O(n) -> stack size (can be easily converted to an iterative function too)
*/

unordered_map<char, int> base;

void init_base() {
    base.insert({'I', 1});
    base.insert({'V', 5});
    base.insert({'X', 10});
    base.insert({'L', 50});
    base.insert({'C', 100});
    base.insert({'D', 500});
    base.insert({'M', 1000});
}

int roman_to_decimal(string s, lld start, lld end) {
    if(end == start) return base[s[start]];

    if(base[s[start]] < base[s[start + 1]]) return roman_to_decimal(s, start + 1, end) - base[s[start]];
    else return roman_to_decimal(s, start + 1, end) + base[s[start]];
}