class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stk;
        int points = 0;
        for(int i = 0; i < ops.size(); i++) {
            string s = ops[i];
            if(s == "D") {
                if(!stk.empty()) {
                    int t = stk.back();
                    points += (2 * t);
                    stk.push_back(2 * t);
                }
            }
            else if(s == "C") {
                if(!stk.empty()) {
                    points -= stk.back();
                    stk.pop_back();
                }
            }
            else if(s == "+") {
                int t = 0;
                if(!stk.empty()) {
                    t += stk.back();
                }
                if(stk.size() > 1) {
                    t += stk[stk.size() - 2];
                }
                stk.push_back(t);
                points += t;
            }
            else {
                int t = stoi(s);
                points += t;
                stk.push_back(t);
            }
        }
        return points;
    }
};
