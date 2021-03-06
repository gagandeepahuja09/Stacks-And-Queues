/*
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;
        int curr = 0;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '(') {
                // for A + B
                stk.push(curr);
                curr = 0;
            }
            else {
                // for (A)
                curr = stk.top() + max(curr * 2, 1);
                stk.pop();
            }
        }
        return curr;
    }
};
*/

class Solution {
public:
    int scoreOfParentheses(string S) {
        int ret = 0, l = 0;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '(')
                l++;
            else
                l--;
            if(S[i] == ')' && S[i - 1] == '(')
                ret += (1 << l);
        }
        return ret;
    }
};
