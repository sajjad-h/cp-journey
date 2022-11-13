class StockSpanner {
public:

    int cur;
    vector<int> vals;
    stack<int> stk;

    StockSpanner() {
        cur = 0;
        vals.clear();
        while (!stk.empty()) stk.pop();
    }

    int next(int price) {
        if (vals.size() == 0) {
            vals.push_back(price);
            stk.push(cur++);
            return 1;
        }
        if (vals.back() > price) {
            vals.push_back(price);
            stk.push(cur++);
            return 1;
        }
        else {
            while (!stk.empty()) {
                if (vals[stk.top()] <= price) {
                    stk.pop();
                    continue;
                }
                break;
            }
            int ans = cur;
            if (!stk.empty()) ans -= stk.top();
            else ans++;
            vals.push_back(price);
            stk.push(cur++);
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */