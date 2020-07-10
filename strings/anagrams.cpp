/* 
    Given two strings a and b consisting of lowercase characters. 
    The task is to check whether two given strings are anagram of each other or not. 
    
    An anagram of a string is another string that contains same characters, only the order of characters can be different. 
    For example, “act” and “tac” are anagram of each other.
*/

/*
    Solution
    Time Complexity: O(m + n)
    Space Compleixity: O(MAX_NUMBER_OF_CHARACTERS)

    The space can be optimized a bit more by using just one array
    and incrementing the count when processing string a
    and decrementing the count when processing string b.
    Finally if all the values in the array are 0, then a and b are anagrams
*/

bool are_anagrams(string a, string b) {
    if(a.length() != b.length()) return false;

    vector<lld> afreq(26, 0), bfreq(26, 0);

    for(lld i=0; i<a.length(); ++i) afreq[a[i] - 'a']++;
    for(lld i=0; i<b.length(); ++i) bfreq[b[i] - 'a']++;

    for(lld i=0; i<26; ++i)
        if(afreq[i] != bfreq[i])
            return false;

    return true;
}