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
