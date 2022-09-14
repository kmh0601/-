//
//  main.cpp
//  BJ_17070
//
//  Created by 권민혁 on 2022/07/10.
//

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int inf = 1e9;
int map[16][16];
int dp[16][16][3];
int N;
int state[3] = { 0, 1, 2}; // 1 가로 / 2 세로 / 3 대각선

int solve(int x,int y,int position){
    if(dp[x][y][position] != -1) return dp[x][y][position];
    dp[x][y][position] = 0;
    
    if(position == 0){ // 가로인 경우
        if(y > 1 and map[x][y] != 1){
            dp[x][y][position] += solve(x, y-1, 0);
        }
        if(y > 1 and x > 0 and map[x][y] != 1){
            dp[x][y][position] += solve(x, y-1, 2);
        }
    }
    
    else if(position == 1){ // 세로인 경우
        if(x > 1 and map[x][y] != 1){
            dp[x][y][position] += solve(x-1,y,1);
        }
        if(x > 1 and y > 0 and map[x][y] != 1){
            dp[x][y][position] += solve(x-1,y,2);
        }
    }
    
    else if(position == 2){ // 대각선인 경우
        if(x > 0 and y > 1 and map[x][y] != 1 and map[x-1][y] != 1 and map[x][y-1] != 1){
            dp[x][y][position] += solve(x-1,y-1,0);
        }
        if(x > 1 and y > 0 and map[x][y] != 1 and map[x-1][y] != 1 and map[x][y-1] != 1){
            dp[x][y][position] += solve(x-1,y-1,1);
        }
        if(x > 1 and y > 1 and map[x][y] != 1 and map[x-1][y] != 1 and map[x][y-1] != 1 ){
            dp[x][y][position] += solve(x-1,y-1,2);
        }
    }
    
    return dp[x][y][position];
}


int main(){
    cin >> N;
    
    memset(dp, -1, sizeof(dp));
    
    dp[0][1][0] = 1;
    
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> map[i][j];
        }
    }
    
    int answer = solve(N-1,N-1,0) + solve(N-1, N-1, 1) + solve(N-1, N-1, 2);

    cout << answer << endl;
//
//    cout << "position : 1 => " << solve(N-1, N-1, 0) << endl;
//    cout << "position : 2 => " << solve(N-1, N-1, 1) << endl;
//    cout << "position : 3 => " << solve(N-1, N-1, 2) << endl;
//
//    cout << "<DP_MAP>" << endl;
//
//    for(int z = 0 ; z < 3 ; ++z ){
//        cout << "[" << z << "]" << endl;
//        for(int i = 0 ; i < N ; ++i){
//            for(int j = 0 ; j < N ; ++j){
//                cout << dp[i][j][z] << " ";
//            }
//            cout << endl;
//        }
//    }

    return 0;
}
