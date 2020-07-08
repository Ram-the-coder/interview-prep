/*
    Given a string S, find the longest palindromic substring in S.
    Incase of conflict, return the substring which occurs first ( with the least starting index ).
    NOTE: Required Time Complexity O(n2)
*/

bool isPalindrome(string s, lld start, lld end) {
    while(start < end)
        if(s[start++] != s[end--]) return false;
    return true;
}

/*
    Solution 1 - Recursion
    Time Complexity: O(2^n)
    Space Complexity: O(n) -> Recursion Stack Size
*/
string longest_palindromic_substring(string s, lld start, lld end) {
    while(start < end) {
        if(isPalindrome(s, start, end)) return s.substr(start, end-start+1);
        string left = longest_palindromic_substring(s, start, end-1);
        string right = longest_palindromic_substring(s, start+1, end);
        return (left.length() >= right.length()) ? left : right;
    }
    return s.substr(0, 1);
}

/*
    Solution 2
    Time Complexity: O(n^3)
    Space Complexity: O(1)
*/
string longest_palindromic_substring(string s, lld start, lld end) {
    lld maxLength = 1, start = 0; 
    for (lld i = 0; i < str.length(); i++) { 
        for (lld j = i; j < str.length(); j++) { 
            if(isPalindrome(s, i, j) && (j - i + 1) > maxLength) {
                start = i; 
                maxLength = j - i + 1; 
            }
        } 
    } 
    return s.substr(start, maxLength);
}


/*
    Solution 2 - Memoizing the recursive approach
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
*/
string longest_palindromic_substring(string s, vector<vector<pair<lld, lld>>> &dp) {
    pair<lld, lld> left, right;
    for(lld i=s.length()-1; i>=0; --i) {
        dp[i][i] = {i, i};
        for(lld j=i+1; j<s.length(); ++j) {
            right = dp[i+1][j];
            left = dp[i][j-1];
            if(s[i] == s[j] && (j == i+1 || (dp[i+1][j-1].first == i+1 && dp[i+1][j-1].second == j-1))) dp[i][j] = {i, j};
            else if(left.second - left.first >= right.second - right.first) dp[i][j] = left;
            else dp[i][j] = right;
        }
    }
    return s.substr(dp[0][s.length()-1].first, dp[0][s.length()-1].second - dp[0][s.length()-1].first + 1);
}

/*
    Solution 3 - DP with space optimization
    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Logic is same as solution 2, but just using a single row dp instead of a matrix dp.
*/
string longest_palindromic_substring(string s) {
    pair<lld, lld> left, right, prev;
    vector<pair<lld, lld>> dp(s.length());
    for(lld i=s.length()-1; i>=0; --i) {
        // dp[j] = {a, b} -> s[a]...s[b] is the longest palindromic substring in s[i]...s[j]
        prev = dp[i]; // prev - dp[i+1][j-1]
        dp[i] = {i, i};
        for(lld j=i+1; j<s.length(); ++j) {
            pair<lld, lld> nextPrev = dp[j]; // dp[i+1][j], in the next iteration this j will be that iteration's j - 1
            right = dp[j]; // dp[i+1][j]
            left = dp[j-1]; // dp[i][j-1]
            if(s[i] == s[j] && (j == i+1 || (prev.first == i+1 && prev.second == j-1))) dp[j] = {i, j};
            else if(left.second - left.first >= right.second - right.first) dp[j] = left;
            else dp[j] = right;
            prev = nextPrev;
        }
    }
    
    return s.substr(dp[s.length()-1].first, dp[s.length()-1].second - dp[s.length()-1].first + 1);
}


/*
    Solution 4 - Expanding from the center
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

string longest_palindromic_substring(string s) {
    lld low, high;
    pair<lld, lld> longest_palindrome = {0, 0};

    // One by one consider every character as center point of 
    // even and odd length palindromes
    for(lld i=0; i<s.length(); ++i) {
        // i is the center point of even length palindrome
        low = i-1;
        high = i;
        while(low >= 0 && high < s.length() && s[low] == s[high]) {
            if(high - low > longest_palindrome.second - longest_palindrome.first) {
                longest_palindrome = {low, high};
            }
            --low; ++high;
        }
        
        // i is the center point of an odd length palindrome
        low = i-1;
        high = i+1;
        while(low >= 0 && high < s.length() && s[low] == s[high]) {
            if(high - low > longest_palindrome.second - longest_palindrome.first) {
                longest_palindrome = {low, high};
            }
            --low; ++high;
        }
    }

    return s.substr(longest_palindrome.first, longest_palindrome.second - longest_palindrome.first + 1);
}