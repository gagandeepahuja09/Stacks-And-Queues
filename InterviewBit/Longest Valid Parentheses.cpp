int Solution::longestValidParentheses(string A) {
    int maxL = 0;
    stack<int> stk;
    stk.push(-1);
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(') {
            stk.push(i);
        }
        else {
            stk.pop();
            if(stk.empty()) {
                stk.push(i);
            }
            else {
                maxL = max(maxL, i - stk.top());
            }
        }
    }
    return maxL;
}

