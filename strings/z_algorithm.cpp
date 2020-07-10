// An element Z[i] of Z array stores length of the longest substring starting from str[i] 
// which is also a prefix of str[0..n-1]. 
vll get_z_arr(string str) {

    lld window_left, window_right, k;
    vector<lld> Z(str.length());

    window_left = window_right = 0;

    for(lld i=1; i<str.length(); ++i) {

        if( i > window_right) {

            window_left = window_right = i;
            // Initially window-right - window_left is 0,
            // So basically we're comparing str[0...] with str[window_left...]
            while(window_right < str.length() && str[window_right - window_left] == str[window_right]) ++window_right;
            --window_right;
            Z[i] = window_right - window_left + 1;

        } else {
            // we already know that
            // str[window_left...window_right] == str[0...window_right - window_left]
            // So str[k....window_right-window_left] == str[i...window_right]
            // So if Z[k] < window_right - i + 1, then Z[i] = Z[k]
            // Else we need to check if there can be more matches after window_right
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
    // We add $ to separate the pattern and text
    // The Z array cannot contain an entry > pattern.length() 
    // as long as $ is not a character in text
    string concat = pattern + "$" + text;

    vll Z = get_z_arr(concat);

    // Iterate throught the z-array to see if it contains an entry of pattern.length()
    // If an entry is found at i, that means
    // starting from text[i - pattern.length() - 1] there is a substring that contain the pattern
    for(lld i=pattern.length()+1; i<Z.size(); ++i)
        if(Z[i] == pattern.length()) 
            return i - pattern.length() - 1;
    
    return -1;
}