class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c=0,n2=flowerbed.size();
        if(n==0)
        return true;
        if(n2==1)
        {
            if(flowerbed[0]==0&&n==1)
            return true;
            else
            return false;
        }
            
        for(int i=0;i<n2-1;i++)
        {
            if(i==0&&flowerbed[i]==0&&flowerbed[i+1]==0)
            {
             c++;
             flowerbed[0]=1;
            }
            else if(i!=0&&flowerbed[i]==0)
            {
                if(flowerbed[i-1]==0&&flowerbed[i+1]==0)
                {
                    c++;
                    flowerbed[i]=1;
                    i++;
                    if(c==n)
                    break;
                }
                else
                continue;
            }
        }
        
        if(flowerbed[n2-1]==0&&flowerbed[n2-2]==0)
        {
        c++;
        flowerbed[n-1]=1;
        }
        return c>=n;
    }
};