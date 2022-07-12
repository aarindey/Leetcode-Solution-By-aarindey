class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty()&&st.top().second<=price)
        {
            st.pop();
        }
        if(st.size()==0)
        {
            st.push({idx,price});
            idx++;
            return idx;
        }
        else
        {
            int ans=idx-st.top().first;
            st.push({idx,price});
            idx++;
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */