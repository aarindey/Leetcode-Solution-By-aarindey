//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
     string caseSort(string s, int n)

    {

        // your code here

        vector<char>v1;

        vector<char>v2;

        for(int i=0;i<n;i++)

        {

            if(s[i]>='A' and s[i]<='Z')

            {

                v1.push_back(s[i]);

            }    

            else

            {

                v2.push_back(s[i]);

            }

        }

        

        sort(v1.begin(),v1.end());

        sort(v2.begin(),v2.end());

        int a=0,b=0;

        for(int i=0;i<n;i++)

        {

            if(s[i]>='A' and s[i]<='Z')

            {

                s[i]=v1[a];

                a++;

            }

            else

            {

                s[i]=v2[b];b++;

            }

        }

        

        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends