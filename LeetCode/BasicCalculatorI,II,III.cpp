class Solution {
public:
    int prec(char c) {
        if(c == '^')
            return 3;
        if(c == '*' || c == '/')
            return 2;
        if(c == '+' || c == '-')
            return 1;
        return -1;
    }
    
    int calculate(string s) {
        string post = "";
        stack<char> stk;
        // Infix to Postfix
        for(int i = 0; i < s.size(); i++) {
            if(isspace(s[i]))
                continue;
            if(isdigit(s[i])) {
                while(isdigit(s[i])) {
                    post += s[i];
                    i++;
                }
                i--;
                post += '$';
            }
            else if(s[i] == '(') {
                stk.push(s[i]);
            }
            else if(s[i] == ')') {
                while(!stk.empty() && stk.top() != '(') {
                    post += stk.top();
                    stk.pop();
                }
                if(stk.size() && stk.top() == '(') {
                    stk.pop();
                }
            }
            else {
                while(stk.size() && prec(s[i]) <= prec(stk.top())) {
                    post += stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
        while(!stk.empty()) {
            post += stk.top();
            stk.pop();
        }
        cout << post << endl;
        // Evaluate Postfix expression
        stack<int> stk2;
        for(int i = 0; i < post.size(); i++) {
            if(isdigit(post[i])) {
                int temp = 0;
                while(isdigit(post[i])) {
                    temp = temp * 10 + (post[i++] - '0');
                }
                stk2.push(temp);
                // i++;
            }
            else {
                int val1 = 0, val2 = 0;
                if(stk2.size()) {
                    val1 = stk2.top(); stk2.pop();
                }
                if(stk2.size()) {
                    val2 = stk2.top(); stk2.pop();
                }
                switch(post[i]) {
                    case '+' : stk2.push(val2 + val1);  break;
                    case '-' : stk2.push(val2 - val1);  break;
                    case '*' : stk2.push(val2 * val1);  break;
                    case '/' : stk2.push(val2 / val1);  break;    
                }
            }
        }
        return stk2.size() ? stk2.top() : 0;
    }
};
