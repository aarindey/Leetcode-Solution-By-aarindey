class Solution {
public:
    int index(char c,string alien)
    {
     for(int i=0;i<alien.length();i++)
     {
         if(c==alien[i])
          return i;   
     }   
        return -1;
    }
    // static bool comp(vector<int> v1,vector<int> v2)
    // {
    //    bool sorted=true;
    //   for(int i=0;i<min(v1.size(),v2.size());i++)
    //       {
    //       if(v1[i]>v2[i])
    // sorted=false;
    //   }   
    //     if(sorted)
    //     return ;
    // }
    bool isAlienSorted(vector<string>& words, string order) 
    {
        int mini=INT_MAX;
     vector<vector<int> > vec(words.size());
     vector<vector<int> > org(words.size());
        int k=0;
        for(auto s:words)
        {
        
            if(s.length()<mini)
             mini=s.length();
            for(auto c:s)
            {
                vec[k].push_back(index(c,order));
            }
            k++;
        }
       return is_sorted(vec.begin(),vec.end());
    }
};