class Solution {
public:
    string decodeString(string s) {
        stack<int> count;
        vector<string> resStk;
        string res = "";
        int i = 0; 
        while(i < s.size()) {
            if(s[i] >= '1' && s[i] <= '9') {
                int num = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i++] - '0');
                }
                count.push(num);
            }
            else if(s[i] == '[') {
                resStk.push_back(res);
                res = "";
                i++;
            }
            else if(s[i] == ']') {
                int c = count.top(); count.pop();
                string temp = resStk.back(); resStk.pop_back();
                for(int j = 0; j < c; j++) {
                    temp += res;
                }
                res = temp;
                i++;
            }
            else {
                res += s[i++];
            }
        }
        return res;
    }
};
