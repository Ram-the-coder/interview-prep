/*
	Given a string, find the length of the longest substring (contiguous elements) without repeating characters.
*/

int len_longest_substring_without_repeat(string s) {
	unordered_map<char, int> chars; // Contains the index of the most recent instance of a character
	chars.reserve(s.length());

	int start = 0, end = -1, max_len = 0;

	for(int i=0; i<s.length(); ++i) {
		auto itr = chars.find(s[i]);
		// Check if the current character is already present in the current substring
		if(itr != chars.end() && itr->second >= start) {
			start = itr->second + 1;
			end = max(end+1, start);
		} else {
			end++;
		}
		
		chars[s[i]] = i; // Update the character index info
		max_len = max(max_len, end-start+1); // Update max len
	}

	return max_len;
}
