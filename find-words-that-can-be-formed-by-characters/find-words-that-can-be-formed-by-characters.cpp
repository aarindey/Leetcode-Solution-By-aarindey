class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
      unordered_map<char,int> mp;
        for(int i=0;i<chars.size();i++)
      {
          mp[chars[i]]++;
      }
        int a,sum=0;
        unordered_map<char,int> temp;
        for(int j=0;j<words.size();j++)
        {
            temp=mp;
            a=0;
        for(int i=0;i<words[j].size();i++)
        {
            temp[words[j][i]]--;
        }
            for(auto it:temp)
            {
                if(it.second<0)
                 a=1;   
            }
             if(a==0)
             sum+=words[j].size(); 
        }
        return sum; 
    }
  
};