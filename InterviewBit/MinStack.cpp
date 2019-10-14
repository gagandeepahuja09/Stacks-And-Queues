stack<int> stk;
int mn;

MinStack::MinStack() {
    mn = INT_MAX;
    while(!stk.empty())
        stk.pop();
}

void MinStack::push(int x) {
    if(stk.empty()) {
        stk.push(x);
        mn = x;
        return;
    }
    if(x < mn) {
        stk.push(2 * x - mn);
        mn = x;
    }
    else
        stk.push(x);
}

void MinStack::pop() {
    if(stk.empty())
        return;
    if(stk.top() < mn) {
        int curr = mn;
        mn = 2 * mn - stk.top();
    }
    stk.pop();
}

int MinStack::top() {
    if(stk.empty())
        return -1;
    if(stk.top() < mn)
        return mn;
    return stk.top();    
}

int MinStack::getMin() {
    if(stk.empty())
        return -1;
    return mn;
}


