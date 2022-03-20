// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:

    string chooseandswap(string str){
        
        int n = str.size();
        
        set<char> s;
        
        for(int i = 0; i < n; i++)
        {
            s.insert(str[i]);
        }
        
        for(int i = 0; i < n; i++)
        {
            s.erase(str[i]);
            
            auto it = s.begin();
            
            if(it == s.end())
            break;
            
            char c = *it;
            
            if(c < str[i])
            {
                char c1 = str[i];
                
                for(int j = 0; j < n; j++)
                {
                    if(str[j] == c1)
                    {
                        str[j] = c;
                    }
                    else if(str[j] == c)
                    {
                        str[j] = c1;
                    }
                }
                
                break;
            }
            
        }
        
        return str;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends