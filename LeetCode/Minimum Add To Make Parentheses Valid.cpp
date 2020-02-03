class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> stk;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')') {
                if(stk.empty())
                    count++;
                else 
                    stk.pop();
            }
            else if(s[i] == '(') {
                stk.push(0);
            }
        }
        while(!stk.empty()) {
            stk.pop();
            count++;
        }
        return count;
    }
};
