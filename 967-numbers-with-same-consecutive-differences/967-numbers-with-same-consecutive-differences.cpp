class Solution {
public:
    void fun(long long num,int n,int k,vector<int> &ans){
        if(n==0) {
        ans.push_back(num);
        return;
        }
        int lower=((num==0)?1:0);
        for(int i=lower;i<10;i++){
            if(num and abs(i-num%10)!=k) continue;
            num*=10;num+=i;
            fun(num,n-1,k,ans);
            num/=10;
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        long long num=0;
        fun(num,n,k,ans);
        return ans;
    }
};