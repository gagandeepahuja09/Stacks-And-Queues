void pushBottom(stack<int>& stk, int val, vector<int>& res) {
    if(stk.empty()) {
        res.insert(res.begin(), val);
        stk.push(val);
        return;
    }
    int t = stk.top();
    stk.pop();
    pushBottom(stk, val, res);
    stk.push(t);
}

void recRev(stack<int>& stk, vector<int>& res) {
    if(stk.empty())
        return;
    int t = stk.top();
    stk.pop();
    recRev(stk, res);
    pushBottom(stk, t, res);
}

vector<int> Solution::solve(vector<int> &A) {
    stack<int> stk;
    for(int i = 0; i < A.size(); i++) {
        stk.push(A[i]);
    }
    vector<int> ret;
    recRev(stk, ret);
    return ret;
}

