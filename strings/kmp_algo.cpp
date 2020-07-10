// Longest proper Prefix Suffix
// A proper prefix suffix of a string is a substring of length < the string length
// which is a prefix as well as a suffix
vector<lld> get_lps(string str) {

    lld len = 0; // length of the last longest "proper" prefix suffix

    vector<lld> lps(str.length());
    lps[0] = 0;

    lld i = 1;

    while(i < str.length()) {
        // The prefix extends from str[0]...str[len-1]
        // So if str[i] == str[len], means the next character of the last preffix is same as the next character of the last suffix
        // so we can extend the prefix suffix by one more character
        if(str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
            
        } else {
            // consider AABACAABAA
            // i = 9
            // lps until now = [0, 1, 0, 1, 0, 1, 2, 3, 4]
            // len = 4
            // even though str[9] != str[4],
            // str[5...8] = str[0...3]
            // So we need to find another str[0...y] = str[z...8] such that y < 3
            // So basically we need to find something that is a suffix of str[5..8] (AABA) and also a prefix of str[0...3] (AABA) but not AABA
            // Which means we need the lps of AABA
            if(len != 0) len = lps[len - 1]; 
            else lps[i++] = 0;
        }
    }

    return lps;
}

lld kmp(string pattern, string text) {
    vll lps = get_lps(pattern);

    lld i = 0, j = 0;

    while(i < text.size()) {

        if(pattern[j] == text[i]) {    
            ++i; 
            ++j;
            if(j == pattern.length()) return i - j;

        } else {
            // mismatch after j matches
            if(j == 0) ++i;
            else j = lps[j-1];
        }
    }

    return -1;
}