/*
MIN MAX RIDDLE

Given an array of integers A of size N.

Find and return an array containing the maximum of the minimum(s) of every window size in the array. The window size varies from 1 to N.

For example, given A = [6, 3, 5, 1, 12], consider window sizes of 1 through 5.

Windows of size 1 are [6], [3], [5], [1], [12]. The maximum of the minimum(s) values of these windows is 12.

Windows of size 2 are [6, 3], [3, 5], [5, 1], [1, 12] and their minima are {3, 3, 1, 1}. The maximum of these values is 3.

Continue this process through window size 5 to finally consider the entire array. All of the answers are [12, 3, 3, 1, 1].

*/

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> l(n, -1), r(n, n);
    stack<int> stk;
    for(int i = 0; i < n; i++) {
        while(!stk.empty() && A[stk.top()] >= A[i]) {
            stk.pop();
        }
        if(!stk.empty())
            l[i] = stk.top();
        stk.push(i);    
    }
    while(stk.size())
        stk.pop();
    for(int i = n - 1; i >= 0; i--) {
        while(!stk.empty() && A[stk.top()] >= A[i]) {
            stk.pop();
        }
        if(!stk.empty())
            r[i] = stk.top();
        stk.push(i);    
    }
    vector<int> ret(n, 0);
    for(int i = 0; i < n; i++) {
        int k = r[i] - l[i] - 2;
        ret[k] = max(ret[k], A[i]);
    }
    for(int i = n - 2; i >= 0; i--) {
        ret[i] = max(ret[i], ret[i + 1]);
    }
    return ret;
}

