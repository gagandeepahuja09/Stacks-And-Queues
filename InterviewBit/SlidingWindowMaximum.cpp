vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> dq;
    vector<int> ret;
    for(int i = 0; i < A.size(); i++) {
        while(!dq.empty() && A[dq.back()] <= A[i])
            dq.pop_back();
        dq.push_back(i);
        if(dq.front() <= i - B) {
            dq.pop_front();
        }
        if(i >= B - 1) {
            ret.push_back(A[dq.front()]);
        }
    }
    return ret;
}

