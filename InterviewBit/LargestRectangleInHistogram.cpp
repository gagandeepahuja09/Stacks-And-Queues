int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> stk;
    vector<int> left(A.size(), -1);
    vector<int> right(A.size(), A.size());
    for(int i = 0; i < A.size(); i++) {
        while(!stk.empty() && A[stk.top()] >= A[i]) {
            stk.pop();
        }
        if(!stk.empty()) {
            left[i] = stk.top();
        }
        stk.push(i);
    }
    while(!stk.empty())
        stk.pop();
    for(int i = A.size() - 1; i >= 0; i--) {
        while(!stk.empty() && A[stk.top()] >= A[i]) {
            stk.pop();
        }
        if(!stk.empty()) {
            right[i] = stk.top();
        }
        stk.push(i);
    }
    int maxRec = 0;
    for(int i = 0; i < A.size(); i++) {
        int rec = (right[i] - left[i] - 1) * A[i];
        maxRec = max(maxRec, rec);
    }
    return maxRec;
}

