class Solution {
public:
    int minimumRefill(vector<int>& p, int capA, int capB) {
        int currA=capA;
        int currB=capB;
        int n=p.size();
        int l=0,h=n-1;
        int ans=0;
        while(l<=h)
        {
            if(l==h)
            {
                if(currA>=currB)
                {
                    if(currA>=p[l])
                    {
                        currA-=p[l];
                        l++;
                    }
                    else
                    {
                        currA=capA;
                        ans++;
                        currA-=p[l];
                        l++;
                    }
                }
                else
                {
                     if(currB>=p[h])
                     {
                         currB-=p[h];
                         h--;
                     }
                     else
                     {
                         currB=capB;
                         ans++;
                         currB-=p[h];
                         h--;
                     } 
                }
            }
            else 
            {
                if(currA>=p[l])
                    {
                        currA-=p[l];
                        l++;
                    }
                    else
                    {
                        currA=capA;
                        ans++;
                        currA-=p[l];
                        l++;
                    }
                if(currB>=p[h])
                     {
                         currB-=p[h];
                         h--;
                     }
                     else
                     {
                         currB=capB;
                         ans++;
                         currB-=p[h];
                         h--;
                     } 
            }
        }
        return ans;
    }
};