class Solution {
public:
    string decodeString(string s) {
        stack<int> numStk;
        stack<string> strStk;
        strStk.push("");
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '1' && s[i] <= '9') {
                int num = 0;
                while(s[i] >= '0' && s[i] <= '9')
                    num = num * 10 + (s[i++] - '0');
                i--;
                numStk.push(num);
            }
            else if(s[i] == '[') {
                string s;
                strStk.push(s);
            }
            else if(s[i] == ']') {
                string temp = strStk.top(); strStk.pop();
                int count = numStk.top();   numStk.pop();
                string repeated;
                while(count--)
                    repeated += temp;
                if(strStk.size())
                    strStk.top() += repeated;
                else
                    strStk.push(repeated);
            }
            else {
                strStk.top() += s[i];
            }
        }
        return strStk.empty() ? "" : strStk.top();
    }
};
