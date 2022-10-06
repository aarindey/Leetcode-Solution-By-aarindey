class TimeMap {
private:
    unordered_map<string, string>ump;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key + to_string(timestamp)] = value;
    }
    
    string get(string key, int timestamp) {
        for(int i=timestamp;i>=0;i--){
            if(ump[key + to_string(i)] != ""){
                return ump[key + to_string(i)];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */