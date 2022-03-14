class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        int n=path.size();
        vector<string> v;
        int low=0,high=1;
        for(int i=1;i<n;i++){
            if(path[i]=='/' && path[i-1]!='/'){
                string x= path.substr(low+1,i-low-1);
                if(x=="."){
                    low=i;
                    continue;
                }
                if(x==".."){
                    if(v.size()==0){
                        low=i;
                        continue;
                    }
                    v.pop_back();
                }
                else 
                    v.push_back(x);
                low=i;
            }
            if(path[i]=='/' && path[i-1]=='/')
                low=i;
        }
        // cout<<low<<endl;
        // for(auto &it : v)
        //     cout<<it<<endl;
        // cout<<path.substr(low+1,n-1-(low))<<endl;
        if(low<n-1){
            if(path.substr(low+1,n-1-(low))==".."){
                if(v.size())v.pop_back();
                
            }
            if(path.substr(low+1,n-1-(low))!="." && path.substr(low+1,n-1-(low))!="..")
                v.push_back(path.substr(low+1,n-1-(low)));
        }
        for(int i=0;i<v.size();i++){
            ans+='/';
            ans+=v[i];
        }
        if(v.size()==0)ans.push_back('/');
        return ans;
    }
};