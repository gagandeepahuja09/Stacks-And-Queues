/*
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        string ret;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.push(ret.size());
            }
            else if(s[i] == ')') {
                int t = stk.top();
                stk.pop();
                reverse(ret.begin() + t, ret.end());
            }
            else {
                ret += s[i];
            }
        }
        return ret;
    }
};
*/

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        vector<int> pair(n);
        string ret;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else if(s[i] == ')') {
                int t = stk.top();
                stk.pop();
                pair[i] = t;
                pair[t] = i;
            }
        }
        for(int i = 0, d = 1; i < n; i += d) {
            if(s[i] == '(' || s[i] == ')') {
                i = pair[i];
                d = -d;
            }
            else
                ret += s[i];
        }
        return ret;
    }
};
