int Solution::braces(string A) {
    stack<char> stk;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == ')') {
            char c = stk.top();
            stk.pop();
            bool flag = true;
            while(c != '(') {
                if(c == '+' || c == '-' || c == '*' || c == '/') {
                    flag = false;
                }
                c = stk.top();
                stk.pop();
            }
            if(flag)
                return flag;
        }
        else
            stk.push(A[i]);
    }
    return false;
}

