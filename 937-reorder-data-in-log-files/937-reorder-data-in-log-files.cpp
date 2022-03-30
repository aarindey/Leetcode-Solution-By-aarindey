class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {       
        map<string, set<string>> mp;
        vector<string> ans;
        set<string> s;
        vector<string> temp;
        for(int i = 0; i<logs.size(); i++){
            int idx = string(logs[i]).find(' ');
            string content = logs[i].substr(idx+1);
            if(content[0] >='a' && content[0]<='z'){
                mp[logs[i].substr(idx+1,logs[i].length()-1)].insert(logs[i]);
            }else{
                temp.push_back(logs[i]);
            }
        }        
        for(auto& m: mp){
            for(auto& str: m.second){
                ans.push_back(str);    
            }
        }
        for(int i = 0; i< temp.size(); i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};