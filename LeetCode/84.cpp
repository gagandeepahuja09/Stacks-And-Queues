class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> stk;
        // left and right arrays will store position of previous and next smaller element
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && a[i] <= a[stk.top()]) {
                stk.pop();    
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        while (!stk.empty())
            stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && a[i] <= a[stk.top()]) {
                stk.pop();    
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        int maxHeight = 0;
        for (int i = 0; i < n; i++) {
            // cout << a[i] << " " << left[i] << " " << right[i] << endl;
            int currHeight = a[i] * (right[i] - left[i] - 1);
            maxHeight = max(maxHeight, currHeight);
        }
        return maxHeight;
    }
};
