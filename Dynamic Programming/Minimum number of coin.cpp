#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>coins, int m, int V)
{
    int table[V + 1];
    int coinUsed[V + 1];


    table[0] = 0;
    coinUsed[0] = -1;

    for (int i = 1; i <= V; i++)
    {
        table[i] = INT_MAX;
        coinUsed[i] = -1;
    }

    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                {
                    table[i] = sub_res + 1;
                    coinUsed[i] = j;
                }
            }
        }
    }

    if (table[V] == INT_MAX)
    {
        cout << "It is not possible to make the sum "<<V<<" with the given coins."<< endl;
        return -1;
    }

    cout << "Minimum coins required is=" << table[V]<<endl;
    cout<<"Coin used are=";

    int value = V;
    while (value > 0)
    {
        int coinIndex = coinUsed[value];
        cout << coins[coinIndex] << " ";
        value -= coins[coinIndex];
    }
    cout << endl;

    return table[V];
}

int main()
{

    int n,i,sum;
    cout<<"Enter the number of coin\n";
    cin>>n;
    vector<int>coins(n);
    cout<<"Enter coins\n";
    for(i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    cout<<"Enter the value of sum\n";
    cin>>sum;
    minCoins(coins,n,sum);
    return 0;
}
