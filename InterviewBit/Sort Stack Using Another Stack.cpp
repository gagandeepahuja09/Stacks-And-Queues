vector<int> Solution::solve(vector<int> &A) {
    // sort(A.begin(), A.end());
    // return A;
    stack<int> stk, aux;
    for(auto i : A)
        stk.push(i);
    while(!stk.empty()) {
        int t = stk.top();
        stk.pop();
        while(!aux.empty() && aux.top() < t) {
            stk.push(aux.top());
            aux.pop();
        }
        aux.push(t);
    }
    vector<int> ret;
    while(!aux.empty()) {
        // cout << aux.top() << " ";
        ret.push_back(aux.top());
        aux.pop();
    }
    return ret;
}

