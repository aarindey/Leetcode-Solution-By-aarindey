class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> v,temp;
        s+=' ';
        for(int i=0;i<s.length()-1;i++)
        {
            if(isdigit(s[i])&&!isdigit(s[i+1]))
            v.push_back(s[i]-'0');
            else if(isdigit(s[i])&&isdigit(s[i+1]))
            {
                v.push_back(stoi(s.substr(i,2)));
                i++;
            }
        }
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>=v[i+1])
            return false;
        }
        return true;
    }
};