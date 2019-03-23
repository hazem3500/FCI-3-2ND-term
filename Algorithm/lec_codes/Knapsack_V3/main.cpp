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

int dp[2][MAXW+1];

int Knapsack()
{
    int i,tw;

    for(i = 0; i < N; i++)
    {
        for(tw = 0; tw <= W; tw++)
        {
            if(i == 0)
            {
                if (w[i] <= W)
                {
                    dp[i][tw] = v[i];
                }
                else
                {
                    dp[i][tw] = 0;
                }
            }
            else
            {
                dp[i][tw] = dp[(i-1) % 2][tw];

                if(w[i] <= W)
                {
                    int c = dp[(i-1) % 2][tw - w[i]]+ v[i];
                    if (c > dp[i][tw])
                    {
                        dp[i][tw] = c;
                    }
                }
            }
        }
    }
    return dp[N-1][W-1];
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
