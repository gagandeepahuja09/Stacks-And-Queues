int Solution::trap(const vector<int> &A) {
    int l = 0, r = A.size() - 1, lMax = INT_MIN, rMax = INT_MIN;
    int ret = 0;
    while(l <= r) {
        if(A[l] <= A[r]) {
            if(A[l] > lMax) {
                lMax = A[l];
            }
            else
                ret += (lMax - A[l]);
            l++;    
        }
        else {
            if(A[r] > rMax) {
                rMax = A[r];
            }
            else
                ret += (rMax - A[r]);
            r--;    
        }
    }
    return ret;
}

