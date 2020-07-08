/*
    Given a array of N strings, find the longest common prefix among all strings present in the array.
*/

/*
    Solution 1: Character by character matching
    Time complexity: O(n*m)
    Space complexity: O(1)
*/
string longest_common_prefix(vector<string> words) {
    int len = 0;
    while(true) {
        char cur_char;
        int i;
        for(i=0; i<words.size(); ++i) {
            if(words[i].length() < len) break;
            if(i == 0) cur_char = words[i][len];
            else if(words[i][len] != cur_char) break;
        }
        if(i < words.size()) break;
        ++len;
    }

    return len == 0 ? "-1" : words[0].substr(0, len);
}

/*
    Solution 2: Using trie
    Time complexity: O(n*m)
    Space complexity: O(n*m)
*/

class Trie_Node {
public:
    vector<Trie_Node*> next;
    int count;

    Trie_Node() {
        count = 0;
        for(int i=0; i<26; ++i) next.pb(NULL);
    }
};

void trie_add(Trie_Node* root, string word) {
    int i=0;
    Trie_Node* cur = root;
    while(i < word.length()) {
        if(!cur->next[word[i] - 'a']) cur->next[word[i] - 'a'] = new Trie_Node();
        cur->next[word[i] -'a']->count++;
        cur = cur->next[word[i] -'a'];
        ++i;
    }
}

string longest_common_prefix(vector<string> words) {
    Trie_Node *root = new Trie_Node();
    for(auto word : words) trie_add(root, word);

    Trie_Node *cur = root;
    int common_prefix_len = 0;
    while(true) {
        bool end_reached = true;
        for(int i=0; i<26; ++i) {
            if(!cur->next[i] || cur->next[i]->count != words.size()) continue;
            cur = cur->next[i];
            end_reached = false;
            ++common_prefix_len;
            break;
        }
        if(end_reached) break;
    }

    return common_prefix_len ? words[0].substr(0, common_prefix_len) : "-1";
}