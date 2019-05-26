vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> stk;
    int n = A.size();
    vector<int> ret(n, -1);
    for(int i = A.size() - 1; i >= 0; i--) {
        while(stk.size() && A[i] < A[stk.top()]) {
            ret[stk.top()] = A[i];
            stk.pop();
        }
        stk.push(i);
    }
    return ret;
}

