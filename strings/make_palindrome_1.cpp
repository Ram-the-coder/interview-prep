// Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.

/*
    Solution
    Time Complexity: O(n)
    Space Complexity: O(n) -> to store the LPS array when calculating LPS
*/

vector<lld> get_lps(string s) {
    vector<lld> lps(s.length());

    lps[0] = 0;

    lld i = 1, len = 0;

    while(i < s.length()) {
        if(s[i] == s[len]) lps[i++] = ++len;
        else {
            if(len == 0) lps[i++] = 0;
            else len = lps[len - 1];
        }
    }

    return lps;
}

lld min_chars_front_to_make_palindrome(string s) {
    // we need to find the length len such that s[0...len-1] is a palindrome
    // Once we find that, the ans is just s.length() - len
    // A palindrome is just a string that when reversed is also the same
    // So let, sr = s + "$" + reverse(s)
    // If s is a palindrome then the lps(sr) will be s.length()
    // lps(sr) will find the longest substring that is a prefix of sr and that which is a suffix of reverse(sr)
    // Basically, returns the length of the substring starting from index 0 of s, that is a palindrome
    string sr = s + "$" + string(s.rbegin(), s.rend());
    lld len = get_lps(sr).back();
    return s.length() - len;
}