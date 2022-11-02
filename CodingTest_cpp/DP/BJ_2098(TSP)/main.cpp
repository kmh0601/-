//
//  main.cpp
//  BJ_2098(TSP)
//
//  Created by 권민혁 on 2022/10/13.
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int inf = 1e9;
int W[16][16];
vector<vector<int>> dp_table;

int tsp(int last, int visited){
    if (visited == (1<<N)-1){
        if(W[last][0] == 0)  return dp_table[last][visited] = inf;
        else return dp_table[last][visited] = W[last][0];;
    } // 기저값
    if (dp_table[last][visited] != 0) return dp_table[last][visited]; // 이미 한 번 계산한 값이면 바로 반환(dynamic programming)
    
    int tmp = inf;
    for(int city = 0 ; city < N ; ++city){
        if((visited & 1<<city) == 0 and W[last][city] != 0){ //city를 아직 방문안했고, last에서city로 가는 경우의 수가 존재하면
            tmp = min(tmp, tsp(city,visited | (1<<city)) + W[last][city]);
        }
    }
    dp_table[last][visited] = tmp;
    return dp_table[last][visited];
}

int main(void){
    // input N
    cin >> N;
    // setting dp_table
    vector<int> tmp_vec(1<<N,0); // (1<<N)-1 안쓰는 이유는 인덱스를 1 ~ (1<<N)-1까지 쓰므로 인덱스 0 을 안쓰기 때문에 +1 해줘서 1<<N을 쓰는것이다.
    
    for(int i = 0 ; i < N ; ++i){
        dp_table.push_back(tmp_vec);
    }
    // input W(matrix)
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> W[i][j];
        }
    }
    
    cout << tsp(0,1<<0)<<endl;
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < 1<<N ; ++j){
            cout << dp_table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    
    for(int i = 0 ; i < N ; ++i){
        for (int j = 0 ; j < N; ++j) {
            cout << "W[" << i << "][" << j << "] :" << W[i][j] << " ";
        }
        cout << endl;
    }
    
}

/*
 4
 0 10 15 20
 5 0 9 10
 6 13 0 12
 8 8 9 0
 */
