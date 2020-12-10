class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            while(!dq.empty() && nums[dq.back()] <= val) {
                dq.pop_back();
            }
            dq.push_back(i);
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                ret.push_back(nums[dq.front()]);
            }
        }
        return ret;
    }
};

// Keep on removing from back, when you encounter a <= number
// 1 3 -1 3 5 3 6 7
// 1 ==> 1
// 1 3 -> 3 ==> 3
// 3 -1 ==> 3
// 3 -1 3 -> 3 ==> 3
// 3 5 -> 5 ==> 5
// 5 3 => 5
// 5 3 6 -> 6 ==> 6
// 6 7 -> 7 ==> 7
