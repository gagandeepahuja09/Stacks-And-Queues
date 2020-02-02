class StockSpanner {
public:
    stack<pair<int, int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        while(!stk.empty() && price >= stk.top().first) {
            count += stk.top().second;
            stk.pop();
        }
        stk.push({ price, count });
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
