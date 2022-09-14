//
//  main.cpp
//  BJ_1937
//
//  Created by 권민혁 on 2022/06/21.
//

#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

int N; // 1 <= N <= 500
int maximum = 0;
int bamboo[500][500];
int dp[500][500];

int solve(int x, int y){
    if (dp[x][y] != 0) return dp[x][y];
    
    dp[x][y] = 1;
    
    if(x-1 >= 0 and bamboo[x-1][y] < bamboo[x][y]) dp[x][y] = max(dp[x][y], solve(x-1,y) + 1);
    if(x+1 <= N-1 and bamboo[x+1][y] < bamboo[x][y]) dp[x][y] = max(dp[x][y], solve(x+1,y) + 1);
    if(y-1 >= 0 and bamboo[x][y-1] < bamboo[x][y]) dp[x][y] = max(dp[x][y], solve(x,y-1) + 1);
    if(y+1 <= N-1 and bamboo[x][y+1] < bamboo[x][y]) dp[x][y] = max(dp[x][y], solve(x,y+1) + 1);
    
    return dp[x][y];
}

int main(){
    cin >> N;
    
    
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> bamboo[i][j];
        }
    }
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0; j < N ; ++j){
            solve(i,j);
        }
    }
    for(int i = 0; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            maximum = max(maximum, dp[i][j]);
        }
    }
    cout << maximum;
    
}

