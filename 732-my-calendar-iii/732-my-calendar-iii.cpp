class MyCalendarThree {
public:
    vector<pair<int, int>>all;
    int n;
    
    MyCalendarThree() {
        n = 0;
    }
    
    int book(int start, int end) {
       
        pair<int, int>val = {start, 0}; 
        auto pos = lower_bound(all.begin(), all.end(), val);
        all.insert(pos, val);
      
        val = {end-1, 1}; 
        pos = lower_bound(all.begin(), all.end(), val);
        all.insert(pos, val);
        
        n += 2; 
        
        int maxi = 0;
        
     
        int res = 0;
        for(int i=0; i<n; i++){
            auto t = all[i];
            if(t.second == 0)
                res++;
            else
                res--;
            
            maxi = max(maxi, res);
        }
        
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */