class Solution {
public:
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,-1,0,1};
    struct Node
    {
        int x,y,time;
        Node(int xx,int yy,int tt){x=xx;y=yy;time=tt;}
    };
    int m,n;
    bool bfs(vector<vector<int>> &arr,int tt){
        vector<vector<int>> vec=arr;
        queue<Node> q;
        // 0-->Safe                // 1-->Fire                    // 2-->Wall
        
        // Inserting Fire In Queue For First BFS
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vec[i][j]==1)
                    q.push(Node(i,j,tt));
            }   
        }
        //First Spread Of Fire In tt Seconds
        // Still Photo At t=tt sec
        //I Dont Care About Time In Which Fire Spreads. I Just Care Where Does The Fire Spread
        // So Marking That In vec
        while(!q.empty()){
            Node node=q.front();
            q.pop();
            int x=node.x;
            int y=node.y;
            int time=node.time;
            if(time==0)continue;
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX<0 || newY<0 || newX>=m || newY>=n || vec[newX][newY]==2 || vec[newX][newY]==1)
                    continue;
                vec[newX][newY]=1;
                q.push(Node(newX,newY,time-1));
            }
        }
        // IF Ending Cell Or Man's Cell Is Only Fire Then No Movement Possible
        if(vec[m-1][n-1]==1 || vec[0][0]==1)return 0;
        
        // After t=tt Seconds Starting With Zero   
        
        queue<Node> man;
        man.push(Node(0,0,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[0][0]=1;

        int lastNodeFireTime=-1;        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vec[i][j]==1){
                    q.push(Node(i,j,0));
                }
            }   
        }
        // -1-->No Fire 0->Fire At Zero Seconds Already

        while(!q.empty() || !man.empty()){
            // First Fire Spread Them Movement Of Man In Each Second
            //Simulation Of Each Second
            if(vec[m-1][n-1])return 0;
            int size=q.size();
            for(int k=0;k<size;k++){
                Node node=q.front();
                q.pop();
                int x=node.x;
                int y=node.y;
                int time=node.time;
                for(int i=0;i<4;i++){
                    int newX=x+dx[i];
                    int newY=y+dy[i];
                    if(newX<0 || newY<0 || newX>=m || newY>=n || vec[newX][newY]==2 || vec[newX][newY]==1)
                        continue;
                    vec[newX][newY]=1;
                    q.push(Node(newX,newY,time+1));
                    if(newX==m-1 && newY==n-1)lastNodeFireTime=time+1;
                }
                
            }
            // Man BFS Starts
            int len=man.size();
            for(int k=0;k<len;k++){
                Node now=man.front();
                man.pop();
                int x=now.x;
                int y=now.y;
                int time=now.time;
                for(int i=0;i<4;i++){
                    int newX=x+dx[i];
                    int newY=y+dy[i];
                    if(newX==m-1 && newY==n-1 && lastNodeFireTime==-1)return true;
                    if(newX==m-1 && newY==n-1 && time+1<=lastNodeFireTime)return true;
                    if(newX<0 || newY<0 || newX>=m || newY>=n || vec[newX][newY]==2 || vec[newX][newY]==1 || vis[newX][newY]==1)
                        continue;
                    vis[newX][newY]=1;
                    man.push(Node(newX,newY,time+1));
                }
                if(man.size()==0)return 0;
                // ..No Position There For Man
            }
            // End Of 1 Second
        }
        return 0;
    }
    int maximumMinutes(vector<vector<int>>& arr) {
        m=arr.size();
        n=arr[0].size();
        
        int low=0,high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(bfs(arr,mid)){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};