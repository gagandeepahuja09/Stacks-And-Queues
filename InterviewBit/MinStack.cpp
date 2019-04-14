stack<int> stk;
stack<int> minStk;

MinStack::MinStack() {
    while(!stk.empty())
        stk.pop();
    while(!minStk.empty())
        minStk.pop();
}

void MinStack::push(int x) {
    stk.push(x);
    if(minStk.empty() || minStk.top() > x) {
        minStk.push(x);
    }
}

void MinStack::pop() {
    if(!stk.empty() && !minStk.empty()) {
        if(minStk.top() == stk.top())
            minStk.pop();
    }
    if(!stk.empty())
        stk.pop();
}

int MinStack::top() {
    return stk.empty() ? -1 : stk.top();
}

int MinStack::getMin() {
    return minStk.empty() ? -1 : minStk.top();
}


