//
//  main.cpp
//  BJ_1562
//
//  Created by 권민혁 on 2022/10/23.
//
//  for문을 이용한 bfs 풀이

#include<iostream>
#include<algorithm>
#include<vector>

#define mod 1000000000

using namespace std;

int N, full, ans;
int dp_table[101][10][1<<10]; // 101 = 최대길이, 10 = 끝자리 숫자(0~9), 1<<10 = 각자리 숫자의 사용여부 1101100000 = 5689포함됨


void stair_num(){
    for(int i = 2 ; i < N+1 ; ++i){
        for(int j = 0 ; j < 10 ; ++j){
            for(int k = 0 ; k < full + 1 ; ++k){
                /*
                 모든 k 에 대해서 탐색하는 이유 -> 길이가 i 이고 끝자리가 j 일때 k의 경우의 수가 다양하기 때문이다.
                 이때 k가 변함에 따라 dp[][][k] 에 바로 값을 넣는게 아니라 끝자리가 j 라는 것은 j를 추가한다는 의미와 같으므로
                 dp[][][k|(1<<j)] 에 값을 넣어준다.
                 | 연산을 하는 이유는 이미 j가 사용되었든 아니든 예외없이 계산해주기 위해서이다.
                */
                
                if(j == 9){
                    dp_table[i][9][k|(1<<9)] = (dp_table[i][9][k|(1<<9)] + dp_table[i-1][8][k]) % mod;
                }
                else if(j == 0){
                    dp_table[i][0][k|(1<<0)] = (dp_table[i][0][k|(1<<0)] + dp_table[i-1][1][k]) % mod;
                }
                else{
                    dp_table[i][j][k|(1<<j)] = (dp_table[i][j][k|(1<<j)] + dp_table[i-1][j+1][k]) % mod;
                    dp_table[i][j][k|(1<<j)] = (dp_table[i][j][k|(1<<j)] + dp_table[i-1][j-1][k]) % mod;
                }
            }
        }
    }
}

int main(void){
    cin >> N;
    full = (1<<10)-1;
    
    for(int i = 1 ; i < 10 ; ++i){
        dp_table[1][i][1<<i] = 1;
    }
    
    stair_num();
    
    ans = 0;
    
    for(int i = 0 ; i < 10 ; ++i){
        ans = (ans + dp_table[N][i][full]) % mod;
    }
    
    cout << ans;
}
