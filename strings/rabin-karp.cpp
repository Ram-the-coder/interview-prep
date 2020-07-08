/*  Average and Best Case Time Complexity: O(pattern length + text length)
    Worst Case Time Complexity: O(pattern length * text length) - Occurs due to hash resulting in  false +ves
    Space complexity: O(1)
*/ 

// Returns the index of the first occurence of pattern in text else returns -1
lld rabin_karp(string pattern, string text, lld q) {
    lld pattern_hash = 0, text_window_hash = 0;
    lld leading_char_hash_multiplier = 1;
    lld num_possible_chars = 256;

    // leading_char_hash_multiplier = num_possible_chars ^ (pattern.length() - 1) % q
    for(lld i=0; i < pattern.length()-1; ++i)
        leading_char_hash_multiplier = (leading_char_hash_multiplier * num_possible_chars) % q;

    // Calculate the hash value for the pattern
    for(lld i=0; i<pattern.length(); ++i)
        pattern_hash = (pattern_hash * num_possible_chars + pattern[i]) % q;

    // Calculate the hash value of the first window of text
    for(lld i=0; i<pattern.length(); ++i)
        text_window_hash = (text_window_hash * num_possible_chars + text[i]) % q;

    // Slide a window over the text to find the pattern
    for(lld i=0; i <= text.length() - pattern.length(); ++i) {
        // If the hashes are same, check the characters one by one for a match
        if(pattern_hash == text_window_hash) {
            lld j;
            for(j=0; j<pattern.length(); ++j)
                if(pattern[j] != text[i+j]) break;

            if(j == pattern.length()) return i;
        }

        // Calculate the hash for the next window position
        if(i < text.length() - pattern.length()) {
            text_window_hash -= leading_char_hash_multiplier * text[i]; // Remove the leading char
            text_window_hash = text_window_hash * num_possible_chars + text[i + pattern.length()]; // Add the trailing char
            text_window_hash %= q;
            text_window_hash  = (text_window_hash + q) % q; // In case the hash is negative
        }
    }

    return -1;
}