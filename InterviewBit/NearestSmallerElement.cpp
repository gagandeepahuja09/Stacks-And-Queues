/*
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> stk;
    int n = A.size();
    vector<int> ret(n, -1);
    for(int i = A.size() - 1; i >= 0; i--) {
        while(stk.size() && A[i] < A[stk.top()]) {
            ret[stk.top()] = A[i];
            stk.pop();
        }
        stk.push(i);
    }
    return ret;
} 
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> stk;
    vector<int> ret;
    for(int i = 0; i < A.size(); i++) {
        while(!stk.empty() && A[i] <= A[stk.top()])
            stk.pop();
        if(stk.empty())
            ret.push_back(-1);
        else
            ret.push_back(A[stk.top()]);
        stk.push(i);    
    }
    return ret;
}


