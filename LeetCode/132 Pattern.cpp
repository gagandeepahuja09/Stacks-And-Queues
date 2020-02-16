class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return false;
        vector<int> minLeft(n, INT_MAX);
        minLeft[0] = nums[0];
        for(int i = 1; i < n; i++) {
            minLeft[i] = min(minLeft[i - 1], nums[i]);
        }
        stack<int> stk;
        for(int i = n - 1; i >= 0; i--) {
            if(minLeft[i] < nums[i]) {
                while(!stk.empty() && stk.top() <= minLeft[i])
                    stk.pop();
                if(!stk.empty() && stk.top() < nums[i]) {
                    return true;
                }
                stk.push(nums[i]);
            }
        }
        return false;
    }
};
