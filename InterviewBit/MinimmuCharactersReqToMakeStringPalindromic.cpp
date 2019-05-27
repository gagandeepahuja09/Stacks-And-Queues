int Solution::solve(string A) {
    string rev = A; reverse(rev.begin(), rev.end());
    A = (A + "$" + rev);
    int len = 0, n = A.size();
    vector<int> lps(n, 0);
    lps[0] = 0;
    int i = 1;
    while(i < n) {
        if(A[i] == A[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }    
        }
    }
    return (rev.size() - lps.back());
}

