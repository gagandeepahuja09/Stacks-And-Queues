vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> stk;
    int n = A.size();
    vector<int> ret(n, -1);
    for(int i = 0; i < A.size(); i++) {
        while(!stk.empty() && A[stk.top()] >= A[i])
            stk.pop();
        if(stk.empty())
            ret[i] = -1;
        else
            ret[i] = A[stk.top()];
        stk.push(i);
    }
    return ret;
}

