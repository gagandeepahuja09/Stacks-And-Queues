class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> stk = { INT_MAX };
        int ans = 0;
        for(auto x : arr) {
            while(stk.back() <= x) {
                int currMin = stk.back();   stk.pop_back();
                ans += min(stk.back(), x) * currMin;
            }
            stk.push_back(x);
        }
        for(int i = stk.size() - 1; i >= 2; i--) {
            ans += (stk[i] * stk[i - 1]);    
        }
        return ans;
    }
};
