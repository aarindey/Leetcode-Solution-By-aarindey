class Encrypter {
public:
    unordered_map<char,string> m;
    unordered_map<string,int> dict;
    // vector k is keys, vector v is values and vector d is dictionary
    Encrypter(vector<char>& k, vector<string>& v, vector<string>& d) {
        int n = k.size();
        // we store the key value pairs in an unordered_map m, so that encryption of a char takes O(1).
        for(int i=0;i<n;i++){
            m[k[i]] = v[i];
        }
        
        // we encrypt the strings in the vector d and store it's count in an unordered_map dict.
        // so that we can directly say the count of decryptions for a string in O(1).
        n = d.size();
        for(int i=0;i<n;i++){
            string p = encrypt(d[i]);
            dict[p]++;
        }
    }
    
    string encrypt(string s) {
        // encrypt the string using key value pairs in unordered_map m
        int n = s.length();
        string p = "";
        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end()){
                return "";
            }
            p += m[s[i]];
        }
        return p;
    }
    
    int decrypt(string s) {
        if(dict.find(s)==dict.end()) return 0; // if not present in dict, return 0
        return dict[s]; // else return count.
    }
};