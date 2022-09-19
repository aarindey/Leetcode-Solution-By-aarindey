class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content_path;
        vector<vector<string>> result;
        
        for (int i = 0; i < paths.size(); i++) {
            string curr = paths[i];
            int itr = 0;
            string path = "", file = "", content = "";

            while (curr[itr] != ' ') {
                path += curr[itr++];
            }
            
            itr++; 
            
            while (itr < curr.size()-1) {
                while (curr[itr] != '(') {
                    file += curr[itr++];
                }
                
                itr++;
                
                while (curr[itr] != ')') {
                    content += curr[itr++];
                }
                
                content_path[content].push_back(path + "/" + file);

                itr += 2; 
                file = "";
                content = "";
            }
        }
        
        for (auto &el: content_path) {
            if (el.second.size() > 1) {
                vector<string> curr;

                for (int i = 0; i < el.second.size(); i++) {
                    curr.push_back(el.second[i]);
                }

                result.push_back(curr);
            }
        }
        
        return result;
    }
};