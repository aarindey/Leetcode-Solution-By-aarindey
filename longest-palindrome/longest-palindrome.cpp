class Solution {
public:
    int longestPalindrome(string s) {
     unordered_map<char,int> mp; 
        for(char c:s)   
        {
            mp[c]++;
        } 
        int sum=0;
    
            bool first=true;
              for(auto pr:mp)
            {
            if(pr.second%2==0)
                sum+=pr.second;
            else if(first)
            {
                sum+=pr.second;
                first=false;
            }
            else
             sum+=(pr.second-1);
              }
        
        return sum;
    }
};