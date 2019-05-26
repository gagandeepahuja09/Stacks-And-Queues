/*

Maximum Frequency stack

You are given a matrix A which represent operations of size N x 2. Assume initially you have a stack-like data structure you have to perform operations on it.

Operations are of two types:

    1 x: push an integer x onto the stack and return -1
    2 0: remove and return the most frequent element in the stack.
    If there is a tie for the most frequent element, the element closest to the top of the stack is removed and returned.

A[i][0] describes the type of operation to be performed. A[i][1] describe the element x or 0 corresponding to the operation performed.

*/

vector<int> Solution::solve(vector<vector<int> > &A) {
    stack<int> stk, ans;
    int maxFreq = 0;
    unordered_map<int, stack<int>> ele;
    unordered_map<int, int> mp;
    vector<int> ret;
    for(int i = 0; i < A.size(); i++) {
        if(A[i][0] == 2) {
            int ans = ele[maxFreq].top();
            mp[ans]--;
            ele[maxFreq].pop();
            ret.push_back(ans);
            if(ele[maxFreq].size() == 0) {
                maxFreq--;
            }
        }
        else {
            mp[A[i][1]]++;
            ele[mp[A[i][1]]].push(A[i][1]);
            maxFreq = max(maxFreq, mp[A[i][1]]);
            ret.push_back(-1);
        }
    }
    return ret;
}

