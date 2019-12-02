class Solution {
public:
    bool find132pattern(vector<int>& A) {
        if(A.size() < 3)
            return false;
        int n = A.size();
        vector<int> mn(n);
        mn[0] = A[0];
        for(int i = 1; i < A.size(); i++)
            mn[i] = min(mn[i - 1], A[i]);
        stack<int> stk;
        for(int j = A.size() - 1; j >= 0; j--) {
            if(mn[j] < A[j]) {
                // aj is j, mnj is i
                while(!stk.empty() && stk.top() <= mn[j]) {
                    stk.pop();
                }
                // stk.top is k
                if(!stk.empty() && stk.top() < A[j]) {
                    return true;
                }
                stk.push(A[j]);
            }
        }
        return false;
    }
};
