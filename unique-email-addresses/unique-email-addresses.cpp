class Solution {
public:
    string normalise(string s)
    {
        string normalised="";
        bool plus_encountered=false;
        bool domain_reached=false;
        for(char c:s)
        {
            if(c=='@')
            {
                domain_reached=true;
            }
            if(domain_reached)
            {
                normalised+=c;
                continue;
            }
            if(c=='.')
                continue;
            else if(c=='+')
            {
                plus_encountered=true;
               continue;
            }
         if(plus_encountered)
         {
             continue;
         }
         normalised+=c; 
        }
        return normalised;
    }
    int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> email;
        for(string s:emails)
        {
            email.insert(normalise(s));
        }
        return email.size();
    }
};