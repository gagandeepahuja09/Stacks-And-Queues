int Solution::largestRectangleArea(vector<int> &A) {
    A.push_back(0);
    stack<int> stk;
    int n = A.size();
    int maxArea = 0, i = 0;
    while(i < n) {
        if(stk.empty() || A[i] >= A[stk.top()]) 
            stk.push(i++);
        else {
            int currMax = stk.top();
            stk.pop();
            maxArea = max(maxArea, A[currMax] * (stk.empty() ? i : 
            i - 1 - stk.top()));
        }    
    }
    return maxArea;
}

