/*
    Given a String of length S, reverse the whole string without reversing the individual words in it. 
    Words are separated by dots.
*/

// note: no special header files need to included other than <bits/stdc++.h> (or) <sstream>
string reverse_words_in_string(string s) {
    string res = "";
    stringstream string_stream(s);
    string word;
    // c++ equivalent of split()
    while(getline(string_stream, word, '.')) {
        res = (res != "") ? (word + "." + res) : (word);
    }
    return res;
}