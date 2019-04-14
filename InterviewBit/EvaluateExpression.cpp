int Solution::evalRPN(vector<string> &A) {
stack<int> stk;
for(int i = 0; i < A.size(); i++) {
    if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/") {
        int first = stk.top();
        stk.pop();
        int second = stk.top();
        stk.pop();
        if(A[i] == "+") 
            stk.push(second + first);
        else if(A[i] == "-")
            stk.push(second - first);
        else if(A[i] == "*")
            stk.push(second * first);
        else 
            stk.push(second / first);    
    }
    else 
        stk.push(stoi(A[i]));
}
return stk.top();
}


