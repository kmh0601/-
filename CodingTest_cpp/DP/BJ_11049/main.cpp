//
//  main.cpp
//  BJ_11049
//
//  Created by 권민혁 on 2022/09/17.
//

#include<iostream>
#include<algorithm>

using namespace std;

#define inf 1e9

int N;
int Matrix[500][500];
int dp[500][2];

int solve(int x,int y){
    for(int i = 1 ; i < N ; ++i){
        for(int j = 0 ; j < N - i ; ++j){
            dp[j][j+i] = inf;
            for(int t = j+1 ; t < j+i ; ++t){
                dp[j][j+i] = min(dp[i][j+i], dp[i][t] + dp[t+1][j]);
            }
        }
    }
    return 0;
}

int main( ){
    cin >> N;

    for(int i = 0 ; i < N ; ++i){
        cin >> Matrix[i][0] >> Matrix[i][1];
    }
    
    
    return 0;
}
