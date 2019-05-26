/*
Reversing the first B elements of queue

Given an array of integers A and an integer B. we need to reverse the order of the first B elements of the array, leaving the other elements in the same relative order.

Note: You are required to first insert elements into an auxiliary queue then perform Reversal of first B elements.

*/

vector<int> Solution::solve(vector<int> &A, int B) {
    queue<int> q;
    for(int i = 0; i < A.size(); i++) {
        q.push(A[i]);
    }
    stack<int> stk;
    for(int i = 0; i < B; i++) {
        int f = q.front();
        q.pop();
        stk.push(f);
    }
    while(stk.size()) {
        int t = stk.top();
        stk.pop();
        q.push(t);
    }
    for(int i = 0; i < A.size() - B; i++) {
        int f = q.front();
        q.pop();
        q.push(f);
    }
    vector<int> v;
    while(q.size()) {
        v.push_back(q.front());
        q.pop();
    }
    return v;
}

