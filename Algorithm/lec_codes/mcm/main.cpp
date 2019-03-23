#include <iostream>
#include<bits/stdc++.h>

using namespace std;
const int N = 5;
int arr[N] = {40,20,30,10,30};

int ret[N][N+1];
int D[N][N+1];

int mcm(int i, int j)
{
    int r = INT_MAX, k;

    if (~ret[i][j]) return ret[i][j];

    if (j == i+1)
        return 0;
    for(k = i+1; k < j; k++){
        int v = mcm(i,k) + mcm(k,j) + arr[i] * arr[k] *arr[j];
        if(r > v)
        {
            r = v;
            ret[i][j] = v;
            D[i][j] = k;
        }
    }
    return r;
}

void print_ans(int i, int j){
    if (j == i+1){
        cout<<"(M"<<i<<")";
        return;
    }
    int k = D[i][j];
    cout<<"(";
    print_ans(i,k);
    cout<<"*";
    print_ans(k,j);
    cout<<")";
}


int main()
{
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N + 1; c++)
            {
                ret[r][c] = -1;
                D[r][c] = -1;
            }
    cout<<mcm(0,4)<<"\n";
    print_ans(0,4);

    return 0;
}
