string Solution::simplifyPath(string A) {
    stack<string> stk;
    for(int i = 0; i < A.size(); i++) {
        if(i < A.size() - 1 && A[i] == '.' && A[i + 1] == '.' && !stk.empty()) {
            stk.pop();
        }
        else if(A[i] != '.' && A[i] != '/') {
            string s = "";
            while(i < A.size() && A[i] != '.' && A[i] != '/') {
                s += A[i];
                i++;
            }
            stk.push(s);
        }
    }
    string ret;
    if(stk.empty())
        return "/";
    while(!stk.empty()) {
        ret = '/' + stk.top() + ret;
        stk.pop();
    }
    return ret;
}

