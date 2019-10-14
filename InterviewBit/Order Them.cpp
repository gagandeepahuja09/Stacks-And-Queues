/*Order them

Given an array of integers A describing ranking of trucks. Your task is to insert these rank in another array B by some means of operations such that B is sorted in ascending order. For performing these operations you can use one stack C.

In one Operation you can perform any of the following steps:

    Remove the first element from A and append at the back of C.
    Remove the last element from C and append at the back of B.
    Remove the first element from A and append at the back of B.
*/

int Solution::solve(vector<int> &A) {
    int need = 1;
    stack<int> stk;
    for(int i = 0; i < A.size(); i++) {
        while(!stk.empty() && stk.top() == need) {
            need++;
            stk.pop();
        }
        if(A[i] == need)
            need++;
        else if(!stk.empty() && A[i] > stk.top()){
            // cout << A[i] << " " << stk.top();
            return false;
        }
        else
            stk.push(A[i]);    
    }
    return true;
}
