int Solution::braces(string A) {
    stack<char> stk;
    for(int i=0; i<A.length(); i++) {
        if(A[i] == ')') {
            char top = stk.top();
            stk.pop();
            bool flag = true;
            while(top != '(') {
                if(top == '*' || top == '/' || top == '+' || top == '-')
                    flag = false;
                top = stk.top();
                stk.pop();
            }
            if(flag == true)
                return true;
        }
        else if(A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*'
            || A[i] == '/')
            stk.push(A[i]);
    }
    return false;
}

