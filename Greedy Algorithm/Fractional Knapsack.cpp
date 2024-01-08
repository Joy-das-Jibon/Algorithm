#include<bits/stdc++.h>
using namespace std;
struct Item
{
    double profit,weight;
};
bool compare(Item a,Item b)
{
    double pw1,pw2;
    pw1=a.profit/a.weight;
    pw2=b.profit/b.weight;
    return (pw1>pw2);
}
double  fractional(Item a[],int s,double capacity)
{
    double totalprofit=0.0;
    int i;
    sort(a,a+s,compare);
    for(i=0;i<s;i++)
    {
        if(a[i].weight<=capacity)
        {
            totalprofit+=a[i].profit;
            capacity-=a[i].weight;
        }
        else
        {
            totalprofit+=capacity*a[i].profit/a[i].weight;
        }
    }
    return totalprofit;
}
int main()
{
    int n,i;
    cout<<"Enter total number of item\n";
    cin>>n;
    Item a[n];
    double capacity;
    cout<<"Enter profit and weight\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i].profit>>a[i].weight;
    }
    cout<<"Enter capacity\n";
    cin>>capacity;
    double c=fractional(a,n,capacity);
    cout<<"Maximum profit="<<c<<endl;
    return 0;
}
