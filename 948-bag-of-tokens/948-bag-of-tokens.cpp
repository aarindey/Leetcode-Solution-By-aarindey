class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int maxtok=0,currtok=0;
        int front=0;int back=n-1;
        while(front<=back)
        {
            if(tokens[front]>P and currtok==0)
                break;
            if(tokens[front]<=P)
            {
                P-=tokens[front++];
                currtok++;
            }
            else if(tokens[front]>P)
            {
                P+=tokens[back--];
                currtok--;
            }
            maxtok=max(maxtok,currtok);
        }
        return maxtok;
    }
};