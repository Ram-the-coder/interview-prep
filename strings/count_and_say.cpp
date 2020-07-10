/*
    Given a pattern as below and an integer n your task is to decode it and print nth row of it. The pattern follows as :
    1
    11
    21
    1211
    111221
    ............

    Constraints:
    1<=T<=20
    1<=N<=20
*/

/*
    Solution
    Time Complexity: O(2^n) assuming in each iteration the length of the strings doubles
    Space Complexity: O(2^n) to store the nth row which contains 2^(n-1) characters according to our assumption
*/
string count_and_say(string s) {
    string next = "";
    int prev = 0;
    for(int i=1; i<s.length(); ++i) {
        if(s[i] == s[prev]) continue;
        next += to_string(i - prev) + s[prev];
        prev = i;
    }

    next += to_string(s.length() - prev) + s[prev];

    return next;
}

string get_count_and_say_row(int n) {
    string s = "1";
    --n;

    while(n--) {
        s = count_and_say(s);
    }

    return s;
}

int main() {
	fastio;

	int t, n;

	cin >> t;

	while(t--) {
		cin >> n;
		cout << get_count_and_say_row(n) << '\n';
	}
	return 0;
}