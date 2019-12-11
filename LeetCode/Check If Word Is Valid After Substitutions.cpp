class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') {
                stk.push('a');
            }
            else if(s[i] == 'b') {
                stk.push('b');
            }
            else if(s[i] == 'c') {
                if(stk.size() < 2) {
                    return false;
                }
                if(stk.top() != 'b')
                    return false;
                stk.pop();
                if(stk.top() != 'a')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
