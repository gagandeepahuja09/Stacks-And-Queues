class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> stk;
        vector<int> ret;
        for(int i  = 0; i < ast.size(); i++) {
            if(ast[i] > 0) {
                stk.push_back(ast[i]);
            }
            else {
                bool broken = false;
                while(!stk.empty()) {
                    int t = stk.back();
                    if(abs(t) <= abs(ast[i])) {
                        stk.pop_back();
                    }
                    if(abs(t) >= abs(ast[i])) {
                        broken = true;
                        break;
                    }
                }
                if(!broken) {
                    ret.push_back(ast[i]);
                }
            }
        }
        for(int i = 0; i < stk.size(); i++) {
            ret.push_back(stk[i]);
        }
        return ret;
    }
};
