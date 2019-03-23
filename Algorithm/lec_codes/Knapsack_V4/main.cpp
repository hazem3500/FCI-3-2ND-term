#include<bits/stdc++.h>

using namespace std;
/*
50

60
10
100
20
120
30

Ans = 220
*/
/**
    Bottom Up
**/
const int N = 3, MAXW = 50;
int v[N], w[N], W;

int dp[MAXW+1];

int Knapsack()
{
    int i,tw;

    for(i = 0; i < N; i++)
    {
        for(tw = W; tw > 0; tw--)
        {
            if(i == 0)
            {
                if (w[i] <= W)
                {
                    dp[tw] = v[i];
                }
                else
                {
                    dp[tw] = 0;
                }
            }
            else
            {
                dp[tw] = dp[tw];

                if(w[i] <= W)
                {
                    int c = dp[tw - w[i]]+ v[i];
                    if (c > dp[tw])
                    {
                        dp[tw] = c;
                    }
                }
            }
        }
    }
    return dp[W-1];
}

int main()
{
    memset(dp,-1,sizeof dp);

    cin>>W; // Max Weight
    for(int i = 0; i < N; i++)
    {
        cin>>v[i]>>w[i]; // The value and the weight of the item
    }
    cout<<Knapsack()<<endl;

    return 0;
}
