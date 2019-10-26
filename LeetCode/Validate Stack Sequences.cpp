class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& pop) {
        int i = 0, j = 0;
        stack<int> stk;
        while(i < pu.size()) {
            stk.push(pu[i++]);
            while(!stk.empty() && j < pop.size() && pop[j] == stk.top()) {
                stk.pop();
                j++;
            }
        }
        return (i == pu.size() && j == pu.size());
    }
};
