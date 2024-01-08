#include<bits/stdc++.h>
using namespace std;
void knapsack(int n,int c,int profit[],int weight[])
{

    int dp[n+1][c+1],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(weight[i-1]<=j)
            {
                dp[i][j]=max((profit[i-1]+dp[i-1][j-weight[i-1]]),dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int result=dp[n][c];
    int w=c;
    cout<<"Maximum profit="<<result<<endl;
    cout<<"Selected item "<<endl;
    for(i=n;i>0&&result>0;i--)
    {
        if(result!=dp[i-1][w])
        {
        cout<<i-1<<" ";
        result-=profit[i-1];
        w-=weight[i-1];
        }
    }
    cout<<endl;
}
int main()
{
    int n,capacity;
    cout<<"Enter number of item\n";
    cin>>n;
    cout<<"Enter capacity\n";
    cin>>capacity;
    int profit[n],weight[n],i;
    cout<<"Enter profit\n";
    for(i=0;i<n;i++)
    {
        cin>>profit[i];
    }
    cout<<"Enter weight\n";
    for(i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    knapsack(n,capacity,profit,weight);

}
