//
//  main.cpp
//  BJ_14002
//
//  Created by 권민혁 on 2022/07/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int numbers[1001];
int dp[1001];
int nIndex[1001];
vector<int> output;

int main(int argc, const char * argv[]) {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> N;
    for(int i = 1 ; i < N+1 ; ++i){
        cin >> numbers[i];
    }
    
    for(int i = 1 ; i < N+1 ; ++i){
        for(int j = 1 ; j < i ; ++j){
            if(numbers[i] > numbers[j]){
                if(dp[i] < dp[j] + 1 ) {
                    nIndex[i] = j; dp[i] = dp[j]+1;
                }
            }
        }
    }
    int maximum = -1;
    int max_index = -1;
    for(int i = 1 ; i < N+1 ; ++i){
        if(maximum < dp[i]){
            maximum = dp[i];
            max_index = i;
        }
    }
    
    output.push_back(numbers[max_index]);
    int next = nIndex[max_index];
    
    while(next){
        output.push_back(numbers[next]);
        next = nIndex[next];
    }
    cout << size(output) << "\n";
    while(!output.empty()){
        cout << output.back() << " ";
        output.pop_back();
        
    }
   
    return 0;
}
