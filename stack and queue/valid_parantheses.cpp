/*
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:
        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.

    Note that an empty string is also considered valid.

    Example 1:

    Input: "()"
    Output: true
    Example 2:

    Input: "()[]{}"
    Output: true
*/

/*
    Solution 1
    Time Complexity: O(n)
    Extra Space: O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> braces;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') braces.push(s[i]);
            else if(s[i] == ')') {
                if(!braces.empty() && braces.top() == '(') braces.pop();
                else return false;
            } else if(s[i] == '}') {
                if(!braces.empty() && braces.top() == '{') braces.pop();
                else return false;
            } else if(s[i] == ']') {
                if(!braces.empty() && braces.top() == '[') braces.pop();
                else return false;
            }
        }
        return braces.empty();
    }
};

/*
    Solution 2
    Time Complexity: O(n)
    Extra Space: O(1)
*/
class Solution {
public:
    bool isValid(string s) {
        int top = -1;
        for(int i =0; i < s.length(); ++i){
            if(top < 0 || !isMatch(s[top], s[i])) 
                s[++top] = s[i];
            else
                --top;
        }
        return top == -1;
    }
    bool isMatch(char c1, char c2){
        if(c1 == '(' && c2 == ')') return true;
        if(c1 == '[' && c2 == ']') return true;
        if(c1 == '{' && c2 == '}') return true;
        return false;
    }
};