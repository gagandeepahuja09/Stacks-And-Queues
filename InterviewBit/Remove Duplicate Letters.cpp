/*
Remove Duplicate Letters

Given a string A consisting of lowercase English alphabets. Find and return lexicographically smallest string B after removing duplicate letters from A so that every letter appears once and only once.


Input Format

The only argument given is string A.

Output Format

Return lexicographically smallest string B after removing duplicate letters from A.

Constraints

1 <= length of the string <= 200000
A consists of lowercase English alphabets only. 

For Example

Input 1:
    A = "cbacdcbc"
Output 1:
    B = "acdb"

Input 2:
    A = "bcabc"
Output 2:
    B = "abc"

*/

string Solution::solve(string A) {
    if(!A.size())
        return A;
    vector<int> cnt(26, 0), inStack(26, 0);
    stack<char> stk;
    for(int i = 0; i < A.size(); i++) {
        cnt[A[i] - 'a']++;
    }
    inStack[A[0] - 'a'] = 1;
    cnt[A[0] - 'a']--;
    stk.push(A[0]);
    for(int i = 1; i < A.size(); i++) {
            cnt[A[i] - 'a']--;
            if(inStack[A[i] - 'a'])
                continue;
            while(!stk.empty() && A[i] < stk.top() && cnt[stk.top() - 'a'] > 0) {
                inStack[stk.top() - 'a'] = 0;
                stk.pop();
            }
            stk.push(A[i]);
            inStack[A[i] - 'a'] = 1;
    }
    string ret;
    while(stk.size()) {
        ret += stk.top();
        stk.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

