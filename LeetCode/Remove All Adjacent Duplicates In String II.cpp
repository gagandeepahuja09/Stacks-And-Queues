class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, char>> stk;
        stk.push({ 0, '$' });
        for(int i = 0; i < s.size(); i++) {
            if(stk.top().second != s[i]) {
                stk.push({ 1, s[i] });
            }
            else if(++stk.top().first == k) {
                stk.pop();
            }
        }
        string ret;
        while(!stk.empty()) {
            ret = string(stk.top().first, stk.top().second) + ret;
            stk.pop();
        }
        return ret;
    }
};
