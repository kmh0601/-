//
//  main.cpp
//  BJ_10942
//
//  Created by 권민혁 on 2022/07/05.
//

#include<iostream>
#include<algorithm>
#include<string.h>


using namespace std;

int N,M,S,E;
int numbers[2001];
short palindrome[2001][2001];

int checkPalindrome(int s, int e){
    
    // dp테이블 조회
    if (palindrome[s][e] != 0)
        return palindrome[s][e];
    
    // 애초에 회문이 될 수 있는가 없는가
    if (numbers[s] == numbers[e]){
        
        // 마지막에 도달하게 되는 경우의 수
        if (s == e)
            return palindrome[s][e] = 1;
        if ( s+1 == e){
            if(numbers[s] == numbers[e])
                return palindrome[s][e] = 1;
            else
                return palindrome[s][e] = 2;
        }
        
        // 아직 마지막에 도달하지 않은 경우의 수
        else
            return palindrome[s][e] = checkPalindrome(s+1, e-1);
    }
    
    else
        return palindrome[s][e] = 2;
    

}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> N;
    for(int i = 1 ; i < N+1 ;  ++i){
        cin >> numbers[i];
    }

    cin >> M;
    for(int i = 0 ; i < M ; ++i){
        cin >> S >> E;
        cout << (checkPalindrome(S, E) == 1) << "\n";
    }
    
    return 0;
}

