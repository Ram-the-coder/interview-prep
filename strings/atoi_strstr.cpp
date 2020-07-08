/*
    Your task  is to implement the function atoi. 
    The function takes a string(str) as argument and converts it to an integer and returns it.
    Corner Cases:
    - Discards all leading whitespaces
    - Sign of the number
    - Overflow
    - Invalid input
*/

/*
    Solution
    Time complexity: O(n)
    Space complexity: O(1)
*/
int atoi(string str)
{
    if(str.length() == 0) return 0;
    int sign = 1, base = 0, i = 0;

    // ignore leading white spaces
    while(str[i] == ' ') ++i;

    // check for sign
    if(str[i] == '+' || str[i] == '-')
        sign = str[i++] == '-' ? -1 : 1;
   
    for(; i<str.length(); ++i) {
        if(str[i] < '0' || str[i] > '9') return -1; // invalid digit
        if(base > INT_MAX/10 || (base == INT_MAX/10 && str[i] > '7')) return -1; // overflow
        base = base*10 + (str[i] - '0');
    }
    
    return sign * base;
}

/*
    Your task is to implement the function strstr. 
    The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. 
    The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).
    Return -1 if no match found.

    Expected Time Complexity: O(|s|*|x|)
    Expected Auxiliary Space: O(1
*/

// Solution 1 - Hard coded
int strstr(string s, string x) {
    for(int start=0; start < s.length() - x.length() + 1; ++start) {
        int j;
        for(j=0; j<x.length(); ++j) {
            if(s[start+j] != x[j]) break;
        } 
        if(j == x.length()) return start;
    }
    return -1;
}

// Solution 2 - Using string::find() method
int strstr(string s, string x) {
    return s.find(x);
}