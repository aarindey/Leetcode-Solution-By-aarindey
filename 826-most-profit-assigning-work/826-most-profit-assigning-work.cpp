class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        int mx=v[0].second;
        
        for(int i=1;i<n;i++){
            v[i].second=max(v[i].second,mx);
            mx=v[i].second;
        }

        sort(v.begin(),v.end());
        
        int res=0;
        int m=worker.size();
        for(int i=0;i<m;i++){
            if(v[0].first > worker[i]){
                continue;
            }
            
            int l=0,r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(v[mid].first <= worker[i]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            
            res+=v[r].second;
            
            
        }
        
        
        return res;
        
        
        
        
    }
};