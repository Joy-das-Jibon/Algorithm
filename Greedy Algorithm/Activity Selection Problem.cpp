#include <bits/stdc++.h>
using namespace std;
struct activity
{
  int start, finish;
};

bool compare(activity a,activity b)
{
    return(a.finish<b.finish);
}

void activitySelection(activity arr[], int size)
{
    sort(arr,arr + size, compare);
    int i = 0;
    cout << "After Activity Selection Sort\n";
    cout <<"Start time   "<< arr[i].start<<" ";
    for (int j = 1; j < size; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout <<" "<< arr[j].start;
            i = j;
        }
    }
    cout<<endl;
    i=0;
     cout <<"Finishing time "<< arr[i].finish<<" ";
    for (int j = 1; j < size; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout <<" "<< arr[j].finish;
            i = j;
        }
    }
    cout<<endl;
}
void print(activity arr[],int n)
{
    int i,j;
    cout<<"This is selected activity number\n";
    i=0;
    cout<<" "<<i+1;
    for(j=i+1;j<n;j++)
    {
        if(arr[j].start>=arr[i].finish)
        {
            cout<<"\t"<<j+1;
            i=j;
        }
    }
    cout<<endl;
}

int main()
{
    int n;
    cout << "Enter the number of Activities :: ";
    cin >> n;
    cout << "Enter the Activities :: " << endl;
    activity arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].finish;

    activitySelection(arr, n);
    print(arr,n);

    return 0;
}
