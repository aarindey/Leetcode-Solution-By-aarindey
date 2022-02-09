class Bitset {
private:
    int n;
    int countBits;
    string bits,rev;
public:
    Bitset(int size) {
        n=size;
        string s(n,'0');
        string r(n,'1');
        rev=r;
        bits=s;
        countBits=0;
    }
    
    void fix(int idx) {
        if(!(bits[idx]-'0'))
        {
            countBits++;
        }
        bits[idx]='1';
        rev[idx]='0';
    }
    
    void unfix(int idx) { 
        if(bits[idx]-'0')
        {
            countBits--;
        }
        bits[idx]='0';
        rev[idx]='1';
    }
    
    void flip() {
        swap(bits,rev);
        countBits=n-countBits;
    }
    
    bool all() {
        return countBits==n;
    }
    
    bool one() {
        return countBits>=1;
    }
    
    int count() {
        return countBits;
    }
    
    string toString() {
        return bits;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */