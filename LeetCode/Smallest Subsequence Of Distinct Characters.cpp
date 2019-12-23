class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0);
        vector<bool> used(26, false);
        for(char c : s) {
            cnt[c - 'a']++;
        }
        stack<char> stk;
        for(char c : s) {
            cnt[c - 'a']--;
            if(used[c - 'a'])
                continue;
            while(!stk.empty() && stk.top() > c && cnt[stk.top() - 'a']) {
                used[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(c);
            used[c - 'a'] = true;
        }
        string ret;
        while(!stk.empty()) {
            ret += stk.top(); stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
