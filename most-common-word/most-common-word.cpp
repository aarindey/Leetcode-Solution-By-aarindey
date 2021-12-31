class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> map;
        string temp = "";
        int max = INT_MIN;
        string ans;

        // must first convert the string to lowercase
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        // insert each word into a map, must only be letters or words
        for (int i=0; i <= paragraph.size(); i++) {
            if (paragraph[i] >= 'a' && paragraph[i] <= 'z') {
                temp = temp + paragraph[i];
            } else {
                if (temp != "") {
                    map[temp]++;
                    temp = "";
                }
            }
        }
        // delete banned items from map
        for (int i=0; i < banned.size(); i++) {
            if (map.find(banned[i]) != map.end()) {
                map.erase(banned[i]);
            }
        }
        // return the most common ocurring string in the map
        for (auto i : map) {
            if (max < i.second) {
                max = i.second;
                ans = i.first;
            }
        }
    
    return ans;
    }
};