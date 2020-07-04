/*
    Given a string s, partition s such that every partition is a palindrome.

    Return all possible palindrome partitioning of s.    
*/

class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
        int i = start, j = end;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    void find_partitions(string &s, vector<vector<string>> &res, vector<string> &partitions, int start) {
        
        if(start == s.length()) {
            res.pb(partitions);
            return;
        }
        
        for(int i = start; i < s.length(); ++i) {
            if(isPalindrome(s, start, i)) {
                partitions.pb(s.substr(start, i - start + 1));
                find_partitions(s, res, partitions, i+1);
                partitions.pop_back();
            }    
        }
/*        
        Adding character one by one is much about 5x slower than adding in bulk as done above
        One of the reasons may be that it creates partitions that are not a palindrome
        It also increases stack size

        // Add the current char to the last partitions
        if(partitions.size()) {
            partitions.back() += s[i];
            find_partitions(s, res, partitions, i+1);
            partitions.back().erase(partitions.back().length() - 1, 1);
        }
        
        // Add the current char to a new partition
        if(!partitions.size() || isPalindrome(partitions.back())) {
            partitions.pb(string(1, s[i]));
            find_partitions(s, res, partitions, i+1);
            partitions.pop_back();    
        }
    }
*/
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partitions;
        find_partitions(s, res, partitions, 0);
        return res;
    }
};