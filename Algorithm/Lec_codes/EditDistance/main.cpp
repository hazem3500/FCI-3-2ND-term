#include <bits/stdc++.h>

using namespace std;

/*
saturday
sunday
1
1
1
Ans = 3
*/

const int N = 100, OO = INT_MAX;
int dp[N][N],D[N][N];

string str1,str2;
int del_cost,insert_cost,sub_cost;

/**
    TopDown
**/
int EditDistance(int i,int j)
{
    if(dp[i][j])
        return dp[i][j];

    if(i == 0)
        return j;
    if(j == 0)
        return i;


    int cost = 0;
    if(str1[i-1] != str2[j-1])
        cost = 1;

    return  dp[i][j] = min(min(EditDistance(i,j-1)+1,EditDistance(i-1,j)+1),EditDistance(i-1,j-1)+cost);
}

/**
    BottomUp
**/
int EditDistance2()
{
    for(int i = 0; i <= str1.length() ; i++)
    {
        for(int j = 0; j <= str2.length(); j++)
        {
            if (i==0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;

            int cost = 0;
            if(str1[i-1] != str2[j-1])
                cost = 1;

            int del = dp[i][j-1]+1;
            int ins = dp[i-1][j]+1;
            int sub = dp[i-1][j-1]+cost;

            if(del == min(min(del, ins), sub))
            {
                D[i][j] = 1;
            }
            else if (ins == min(min(del, ins), sub))
            {
                D[i][j] = 2;
            }
            else if ((sub == min(min(del, ins), sub)) && cost)
            {

                    D[i][j] = 3;
            }
            dp[i][j] = min(min(del, ins), sub);
        }
    }
    return dp[str1.length()][str2.length()];
}

void print_ans(int i, int j)
{
    while(i > 0 && j > 0)
    {
        if(D[i][j] == 1)
        {
            j--;
            cout<<"Delete ' "<<str2[j]<<" ' "<<endl;

        }
        else if (D[i][j] == 2)
        {
            i--;
            cout<<"Insert ' "<<str2[j]<<" ' "<<endl;
        }
        else if (D[i][j] == 3)
        {
            j--;
            i--;
            cout<<"SUB"<<" ' "<<str2[j]<<"' "<<" ' "<<str1[i]<<" ' "<<endl;

        }
        else
        {
            i--;
            j--;
        }
    }
    if (i > 0)
    {
        while (i > 0)
        {
            if (D[i][j] == 2)
            {
                i--;
                cout<<"Insert ' "<<str2[j]<<" ' "<<endl;
            }
            else
                i--;
        }
    }
    else if(j > 0)
    {
        if(D[i][j] == 1)
        {
            j--;
            cout<<"Delete ' "<<str2[j]<<" ' "<<endl;
        }
        else
            j--;
    }
}


int main()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            dp[i][j] = 0;
            D[i][j] = 0;
        }

    cin>>str1>>str2;
    cin>>del_cost>>insert_cost>>sub_cost;

    cout<<"TopDown: "<<EditDistance(str1.length(),str2.length())<<endl;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            dp[i][j] = 0;
        }

    cout<<"BottomUp: "<<EditDistance2()<<endl;
    print_ans(str1.length(),str2.length());
    return 0;
}
