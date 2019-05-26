vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> ret;
    queue<int> q;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] < 0) {
            q.push(i);
        }
        if(q.size() && q.front() <= i - B) {
            q.pop();
        }
        if(i >= B - 1) {
            if(q.size()) {
                ret.push_back(A[q.front()]);
            }
            else
                ret.push_back(0);
        }
    }
    return ret;
}

