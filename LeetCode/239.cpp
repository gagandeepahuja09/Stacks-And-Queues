// 1 3 -1 --> 3
// { 3, 1} { 1, 0 } { -1, 1 }
// We can keep on popping all elements which are before i - k index
// 3 -1 -3 --> 
// 1 3 -1 -3 5 3 6 7
// 1
// 1 3 ==> 3 => 3
// 3 -1 ==> 3 -1 => 3
// 3 -1 -3 ==> 3 -1 -3 => 3
// 3 -1 -3 5 ==> 5 => 5
// 5 3 ==> 5 3 => 5
// 5 3 6 ==> 6 => 6
// 6 7 ==> 7 => 7
// From back we can remove all elements which are < the current element at i index
// because i would be preferred over them
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++) {
            if(!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};
