class Solution {
public:
    bool check(int mid,vector<int> &tasks,vector<int> &workers,int pills,int strength) {        
        multiset<int> w;
        int m=workers.size();
        for(int i=m-1;i>=m-mid;i--)
        {
            w.insert(workers[i]);
        }
        for (int i = mid-1; i >= 0; i--) {
            auto it=w.lower_bound(tasks[i]);
            if (it == w.end()) {
                if (pills == 0)
                return false;
                it = w.lower_bound(tasks[i] - strength);
                if(it == w.end())
                return false;
                pills--;
            }
            w.erase(it);
        }
        return true;        
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n=tasks.size(),m=workers.size();
        int low=0;
        int high=min(n,m);
        int ans;
        while (low<=high) {
            int mid=low+(high-low)/2;
            if (check(mid,tasks,workers,pills,strength)) {
                ans=mid;
                low=mid+1;                
            }
            else
                high=mid-1;
        }
        return ans;
    }
};