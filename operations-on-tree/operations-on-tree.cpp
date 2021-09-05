// Lock: O(1)
// Unlock:O(1)
// Upgrade:O(n)
class LockingTree {
public:
    vector<vector<int> >adj;// adj list for tree
    map<int,int>locked;//map for locked user
    map<int,int>anc;//ancestor map
    LockingTree(vector<int>& parent) {
      adj=vector<vector<int> >(parent.size());
        anc[0]=-1;
        for(int i=1;i<parent.size();i++)
        {
            anc[i]=parent[i];   // stores ancestor  of ith node
            adj[parent[i]].push_back(i);//directed to child
        }
    }
    
    bool lock(int num, int user) {
    
        if(locked.find(num)==locked.end())//checking unlocked
        { 
            locked[num]=user;
            return 1;
        }
        else  //locked
        return 0;
    }
    
    bool unlock(int num, int user) {
        if(locked.find(num)!=locked.end()) // checking locked 
        {
            if(locked[num]==user)
            {
                locked.erase(num);
                return 1;
            }
            else
            return 0;
        }
        else // already unlocked
            return 0;
    }
    
    int dfs(int src)// checking at least one desecendent locked
    {
        for(int i=0;i<adj[src].size();i++)
        {
            int x=adj[src][i];
            if(locked.find(x)!=locked.end())//found
                      return 1;
             if(dfs(x))
                  return 1;
        }
        return 0;
    }
    int check_anc(int up)//checking  not have any locked ancestors
    {
         
            while(up!=-1)  // anc[root]=-1
            {   
                if(locked.find(up)!=locked.end())
				       return 0;
                up=anc[up]; //moving up to ancestor
            }
            return 1;
    }
    void dfs_des(int src)//unlocking all desecendent
    {
       for(int i=0;i<adj[src].size();i++)
        {
            int x=adj[src][i];
            if(locked.find(x)!=locked.end()){
                locked.erase(x);
            }
           dfs_des(x);
        }
    }
    bool upgrade(int num, int user) {
        if(locked.find(num)!=locked.end())return 0;
        
        if(dfs(num)&&check_anc(anc[num]))
        {
            dfs_des(num);//unlocking all desecendent
            locked[num]=user;//locked user
            return 1;
        }return 0;
    }
};
/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */