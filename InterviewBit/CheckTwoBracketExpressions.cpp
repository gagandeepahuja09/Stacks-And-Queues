/*
Check two bracket expressions

Given two strings A and B. Each string represents an expression consisting of 
lowercase english alphabets, '+', '-' and '()'. The task is to compare them and check if 
they are similar. If they are similar return 1 else return 0.
*/

string change(string A) {
    bool pos = true, done = false;
    stack<int> stk;
    string s = "";
    stk.push(1);
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(') {
            if(i > 0 && A[i - 1] == '-')
                stk.push(!stk.top());
            else
                stk.push(stk.top());
        }
        else if(A[i] == ')')
            stk.pop();
        else if(A[i] == '+' || A[i] == '-') {
            if(stk.top() == 1) {
                s += A[i];
            }
            else {
                if(A[i] == '+')
                    s += '-';
                else
                    s += '+';
            }
        }
        else 
            s += A[i];
    }
    // cout << s << " ";
    return s;
}

int Solution::solve(string A, string B) {
    A = change(A);
    B = change(B);
    return (A == B);
}

