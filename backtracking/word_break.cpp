/*
    Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

    Return all such possible sentences.

    For example, given
    s = "snakesandladder",
    dict = ["snake", "snakes", "and", "sand", "ladder"].

    A solution is ["snakes and ladder", "snake sand ladder"].
*/

/*
    Solution
    Worst Case Time Complexity: O(2^(n-2))
    Space Complexity: O(2^n) -> to store the resulting sentences
    Auxillary Space Complexity: O(n)
*/

void word_break_recursive(vector<string> &res, string s, unordered_set<string> &dict, int start, string &cur_sentence) {
    if(start == s.length()) {
        res.pb(cur_sentence);
    }
    for(int i=start; i<s.length(); ++i) {
        string word = s.substr(start, i - start + 1);
        if(dict.find(word) != dict.end()) {
            cur_sentence += (cur_sentence == "") ? word : " " + word;
            word_break_recursive(res, s, dict, i+1, cur_sentence);
            if(cur_sentence.length() == word.length()) cur_sentence.erase(0);
            else cur_sentence.erase(cur_sentence.length() - word.length() - 1);
        }
    }
}

vector<string> word_break(string s, unordered_set<string> &dict) {
    vector<string> res;
    string cur_sentence = "";
    word_break_recursive(res, s, dict, 0, cur_sentence);
    return res;
}