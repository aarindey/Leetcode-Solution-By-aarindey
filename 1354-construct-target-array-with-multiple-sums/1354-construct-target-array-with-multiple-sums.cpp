#define ll long long int
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<ll> pq;
        ll sum=0;
        for(auto &x:target)
        {
            pq.push(x);
            sum+=x;
        }
        while(!pq.empty()&&pq.top()!=1)
        {
            ll maxi=pq.top();
            pq.pop();
            ll left_sum=sum-maxi;
            if(left_sum>=maxi||left_sum<=0)
            return false;
            ll new_ele=maxi%left_sum;
            sum=left_sum+new_ele;
            if(new_ele>0)
            pq.push(new_ele);
            else
            pq.push(sum);
        }
        if(pq.empty())
        return false;
        return true;
    }
};