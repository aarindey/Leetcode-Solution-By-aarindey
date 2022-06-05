class TextEditor {
public:
    string s;
    int p;
    
    TextEditor() {
        s="";
        p=0;
    }
    
    void addText(string text) {
        s.insert(p, text);
        p+= text.size();
    }
    
    
    int deleteText(int k) {
        int count = min(p, k);
        s.erase(s.begin()+p-count, s.begin()+p);
        p -= count;
        return count;
    }
    
    string cursorLeft(int k) {
        p=max(p-k, 0);
        int shift=min(p, 10);
        return s.substr(p-shift, shift); 
        
    }
    
    string cursorRight(int k) {
        p = min(p+k, (int) s.size());
        int shift = min(p, 10);
        return s.substr(p-shift, shift);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */