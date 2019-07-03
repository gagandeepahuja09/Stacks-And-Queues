class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++) {
            if(!stk.empty() && stk.top() == s[i]) {
                while(!stk.empty() && stk.top() == s[i]) {
                    stk.pop();        
                }
            }
            else {
                stk.push(s[i]);
            }
        }
        string ret;
        while(!stk.empty()) {
            ret = stk.top() + ret;
            stk.pop();
        }
        return ret;
    }
};
