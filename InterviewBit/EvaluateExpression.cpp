int Solution::evalRPN(vector<string> &A) {
    stack<int> stk;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/") {
            int n1 = stk.top();
            stk.pop();
            int n2 = stk.top();
            stk.pop();
            if(A[i] == "+") {
                stk.push(n2 + n1);
            }
            if(A[i] == "-") {
                stk.push(n2 - n1);
            }
            if(A[i] == "/") {
                stk.push(n2 / n1);
            }
            if(A[i] == "*") {
                stk.push(n2 * n1);
            }
        }
        else {
            stk.push(stoi(A[i]));
        }
    }
    return stk.top();
}

