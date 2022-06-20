class Solution { 
public: 
    bool matchReplacement(string s, string sub, vector<vector<char>>& maps) { 
        map<char,set<char>> mp;  
        for(auto it : maps) 
        mp[it[0]].insert(it[1]); 
        vector<string> ans; 
        for(int i = 0 ; i <= s.size()-sub.size(); i++) 
        ans.push_back(s.substr(i,sub.size())); 
        for(auto it : ans) 
        { 
            int i = 0; 
            bool anss= true; 
            while(i < sub.size()) 
            { 
                if(sub[i] != it[i]) 
                { 
                    if(mp[sub[i]].find(it[i]) == mp[sub[i]].end()) 
                    { 
                    anss= false; 
                       break; 
                    } 
                } 
                i++; 
            } 
            if(anss) 
            return true; 
        } 
        return false; 
    } 
};