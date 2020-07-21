/*
    Given a string and number of rows ‘n’. 
    Print the string formed by concatenating n rows when input string is written in row-wise Zig-Zag fashion.

    Input: str = "ABCDEFGH", n = 2
    Output: "ACEGBDFH"
    Explanation: Let us write input string in Zig-Zag fashion in 2 rows.
    A   C   E   G   
    B   D   F   H
    Now concatenate the two rows and ignore spaces in every row. We get "ACEGBDFH"
*/

// Solution 
// TC: O(n)
// SC: O(1)
string zigzag(string s, lld rows) {
    if(rows == 1) return s;
    string res = "";
    int eveninc = rows*2 - 2;
    int oddinc = 0;
    for(lld cr=0; cr<rows; ++cr, oddinc += 2, eveninc -= 2) {
        bool even = true;
        for(lld j=cr; j<s.length();) {
            res += s[j];
            if(even) j += eveninc ? eveninc : oddinc;
            else j += oddinc ? oddinc : eveninc;
            even = !even;
        }
    }
    return res;
}