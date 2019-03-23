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

int dp[N][MAXW+1],D[N][MAXW+1];

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
                    D[i][tw] = 1;
                }
                else
                {
                    dp[i][tw] = 0;
                    D[i][tw] = 0;
                }
            }
            else
            {
                dp[i][tw] = dp[i-1][tw];
                D[i][tw] = 0;

                if(w[i] <= W)
                {
                    int c = dp[i-1][tw - w[i]]+ v[i];
                    if (c > dp[i][tw])
                    {
                        dp[i][tw] = c;
                        D[i][tw] = 1;
                    }
                }
            }
        }
    }
    return dp[N-1][W-1];
}

void print(int i, int W)
{
    while (i >= 0 && W > 0)
    {
        if (D[i][W] == 1)
        {
            cout<<v[i]<<" "<< w[i]<<endl;
            W -= w[i];
        }
        i--;
    }

}


int main()
{
    memset(dp,-1,sizeof dp);
    memset(D,-1,sizeof D);

    cin>>W; // Max Weight
    for(int i = 0; i < N; i++)
    {
        cin>>v[i]>>w[i]; // The value and the weight of the item
    }
    cout<<Knapsack()<<endl;
    print(N-1,W);

    return 0;
}
