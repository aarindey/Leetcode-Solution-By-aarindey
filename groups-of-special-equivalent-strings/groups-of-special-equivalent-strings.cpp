class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<pair<string,string> > st;
        for(int i=0;i<A.size();i++)
       {
            pair<string,string> p;
           for(int j=0;j<A[i].length();j++)
           {
               if(j%2==0)
               {
                p.first+=A[i][j];   
               }
               else
               {
                   p.second+=A[i][j];
               }    
           }
            sort(p.first.begin(),p.first.end());
            sort(p.second.begin(),p.second.end());
            st.insert(p);
       }  
        return st.size();
    }
};