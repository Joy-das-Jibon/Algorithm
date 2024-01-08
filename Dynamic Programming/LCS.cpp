#include<bits/stdc++.h>
using namespace std;
int lcslength(string s1,string s2,int m,int n,vector<vector<int>>&dp)
{
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
void printlcs(string s1,string s2,int m,int n,vector<vector<int>>&dp)
{
    int i=m,j=n;
    string lcs=" ";
    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs=s1[i-1]+lcs;
            i--;j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<lcs<<endl;

}
int main()
{
    string a,b;
    cout<<"Enter first string\n";
    cin>>a;
    cout<<"Enter second string\n";
    cin>>b;
    int m,n;
    m=a.size();
    n=b.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    cout<<"The length of lcs="<<lcslength(a,b,m,n,dp)<<endl;
    cout<<"The lcs is=";
    printlcs(a,b,m,n,dp);
}
