//
//  main.cpp
//  BJ_11066
//
//  Created by 권민혁 on 2022/06/21.
//

#include<iostream>
#include<algorithm>
#include <vector>

#define INF 1e9

using namespace std;

int T,K;
int dp[501][501];
int file[500];
int sum[500];

int solve(int a , int b){
    if (dp[a][b] != 0) {
        return dp[a][b];
    }
    if (a == b){
        return 0;
    }
    dp[a][b] = INF;
    
    for(int i = a ; i < b ; ++i){
        dp[a][b] = min(dp[a][b], solve(a,i) + solve(i+1,b) + sum[b] - sum[a] + file[a]);
    }
    return dp[a][b];
}

int main(void){
    cin >> T;
    
    while(T--){
        cin >> K;
        
        for(int i = 0 ; i < K ; ++i){
            cin >> file[i];
            if(i==0) sum[i] = file[i];
            else sum[i] = sum[i-1] + file[i];
        }
        
        solve(0,K-1);
        cout << dp[0][K-1] << endl;
        
    
        for(int i = 0 ; i < K ; ++i){
            for(int j = i ; j < K ; ++j){
                dp[i][j] = 0;
            }
        }
    }
}
//  문제풀이
// 1) 어떤 구간의 최소 구간합은 그 구간을 다시 두 부분으로 나누었을 때, 그 두 부분이 각 구간에 대해 최소 구간합이어야 한다.
// 2) 구간합 - 구간합 = 부분합
