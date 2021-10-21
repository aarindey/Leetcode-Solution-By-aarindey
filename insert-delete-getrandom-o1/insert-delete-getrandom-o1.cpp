class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end())
        {
            v.push_back(val);
            mp[val]=v.size()-1;
        }
        else
        return false;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
        return false;
        else
        {
            int last=v.back();
            v[mp[val]]=last;
            v.pop_back();
            mp[last]=mp[val];
            mp.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */