class BrowserHistory {
private:
    vector<string> v;
    int i;
public:
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        i=0;
    }
    
    void visit(string url) {
        v.erase(v.begin()+i+1,v.end());
        v.push_back(url);
        i++;
    }
    
    string back(int steps) {
        i=max(0,i-steps);
        return v[i];
    }
    
    string forward(int steps) {
        i=min((int)(v.size()-1),(int)(i+steps));
        return v[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */