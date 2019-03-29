string Solution::simplifyPath(string A) {
    stack<string> stk;
    string res = "/";
    string dir;
    for(int i=0; i < A.length(); i++) {
        dir.clear();
        while(A[i] == '/')
            i++;
        while(i < A.length() && A[i] != '/') {
            dir += A[i];
            i++;    
        }
        if(dir == "..") {
            if(!stk.empty())
                stk.pop();
        }
        else if(dir == ".")
            continue;
        else if(dir.length()) {
            stk.push(dir);
        }    
    }
    stack<string> temp;
    while(!stk.empty()) {
        temp.push(stk.top());
        stk.pop();
    }
    while(!temp.empty()) {
        string s = temp.top();
        if(temp.size() > 1)
            res += (s + "/");
        else
            res += s;
        temp.pop();    
    }
    return res;
}

