#include<bits/stdc++.h>
#define lld long long
#define vll vector<lld>
#define vvll vector<vector<lld>>
#define pb push_back
#define mp make_pair
#define ipv(v) for(lld i=0; i<v.size(); ++i) cin >> v[i]
#define dispv(v) for(lld i=0; i<v.size();++i) cout << v[i] << " "; cout << '\n'
#define dispa(a, n) for(lld i=0; i<n; ++i) cout << a[i] << " "; cout << '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vll get_z_arr(string str) {

    lld window_left, window_right, k;
    vector<lld> Z(str.length());

    window_left = window_right = 0;

    for(lld i=0; i<str.length(); ++i) {

        if( i > window_right) {

            window_left = window_right = i;
            while(window_right < str.length() && str[window_right - window_left] == str[window_right]) ++window_right;
            --window_right;
            Z[i] = window_right - window_left + 1;

        } else {
            
            k = i - window_left;
            if(Z[k] < window_right - i + 1) Z[i] = Z[k];
            else {
                window_left = i;
                while(window_right < str.length() && str[window_right - window_left] == str[window_right]) ++window_right;
                --window_right;
                Z[i] = window_right - window_left + 1;
            }

        }
    }

    return Z;
}

lld z_algorithm(string pattern, string text) {
    string concat = pattern + "$" + text;

    vll Z = get_z_arr(concat);

    for(lld i=pattern.length()+1; i<Z.size(); ++i)
        if(Z[i] == pattern.length()) 
            return i - pattern.length() - 1;
    
    return -1;
}

int main() {
	fastio;

	lld t;
	string pattern, text;

	cin >> t;

	while(t--) {
		cin >> text >> pattern;
        cout << z_algorithm(pattern, text) << '\n';
	}
	return 0;
}