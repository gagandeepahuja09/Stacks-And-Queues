class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> stk;
        string ret;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.push(i);
                ret += s[i];
            }
            else if(s[i] == ')') {
                if(!stk.empty()) {
                    int t = stk.top();
                    stk.pop();
                    // ret.insert(ret.begin() + i, '(');
                    ret += s[i];
                }
            }
            else {
                ret += s[i];
            }
        }
        s = ret;
        ret = "";
        while(!stk.empty())
            stk.pop();
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ')') {
                stk.push(i);
                ret += s[i];
            }
            else if(s[i] == '(') {
                if(!stk.empty()) {
                    int t = stk.top();
                    stk.pop();
                    // cout <<" t";
                    // ret.insert(ret.begin() + i, '(');
                    ret += s[i];
                }
            }
            else {
                ret += s[i];
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
