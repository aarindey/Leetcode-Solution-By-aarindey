class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char> > pq;
        if(a>0)
        pq.push({a,'a'});
        if(b>0)
        pq.push({b,'b'});
        if(c>0)
        pq.push({c,'c'});
        string ans="";
        while(pq.size()>1)
        {
            pair<int,char> ff,ss;
            ff=pq.top();
            pq.pop();
            ss=pq.top();
            pq.pop();
            if(ff.first>=2)
            {
                ans+=ff.second;
                ans+=ff.second;
                ff.first-=2;
            }else{
                ans+=ff.second;
                ff.first-=1;
            }
            if(ss.first>=2&&ss.first>=ff.first)
            {
                ans+=ss.second;
                ans+=ss.second;
                ss.first-=2;
            }else{
                ans+=ss.second;
                ss.first-=1;
            }
            if(ff.first>0)
            {
                pq.push(ff);
            }
            if(ss.first>0)
            {
                pq.push(ss);
            }
        }
        if(pq.size()==0)
            return ans;
        
        pair<int,char> pr;
        pr=pq.top();
        if(pr.first>=2)
            {
                ans+=pr.second;
                ans+=pr.second;
                pr.first-=2;
            }else{
                ans+=pr.second;
                pr.first-=1;
            }
        return  ans;
    }
};