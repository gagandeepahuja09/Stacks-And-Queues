int Solution::braces(string A) {
    stack<int> stk;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == ')') {
            int ans = 0;
            while(stk.top() != '(') {
                if(stk.top() == '-' ||  stk.top() == '+' || stk.top() == '/' 
                || stk.top() == '*')
                    ans = 1;
                stk.pop();    
            }
            if(!stk.empty())
                stk.pop();
            if(!ans)
                return 1;
        }
        else
            stk.push(A[i]);
    }
    return 0;
}

