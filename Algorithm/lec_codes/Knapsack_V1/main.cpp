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
    Top Down With Memoization
**/
const int N = 3, MAXW = 50;
int v[N], w[N],W;

int dp[N][MAXW+1],D[N][MAXW+1];

int Knapsack(int i, int W)
{
    if (~dp[i][W]) return dp[i][W];

    if (i == 0)
    {
        if(w[i] <= W)
        {
            return v[i];
            D[i][W] = 1;
        }
        return 0;
    }

    int res = Knapsack(i-1, W);
    D[i][W] = 0;

    if(w[i] <= W)
    {
        int c = Knapsack(i-1, W-w[i]) + v[i];
        if(c > res)
        {
            res = c;
            D[i][W] = 1;
        }
    }

    dp[i][W] = res;

    return res;
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

    cout<<Knapsack(N - 1, W)<<endl;
    print(N-1,W);

    return 0;
}
