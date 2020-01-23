class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> stk;
        vector<int> cnt(26, 0);
        vector<bool> used(26, false);
        for(char c : s) 
            cnt[c - 'a']++;
        for(int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']--;
            if(used[s[i] - 'a'])
                continue;
            while(!stk.empty() && stk.top() > s[i] && cnt[stk.top() - 'a']) {
                char c = stk.top(); stk.pop();
                used[c - 'a'] = false;
            }
            used[s[i] - 'a'] = true;
            stk.push(s[i]);
        }
        string ret;
        while(!stk.empty()) ret += stk.top(), stk.pop();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
