//
//  main.cpp
//  BJ_13975
//
//  Created by 권민혁 on 2022/06/21.
//

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int T, K;
int min_f, min_s;
int answer = 0;
vector<int> file;

int main(){
    cin >> T;
    
    while(T--){
        cin >> K;
        int temp;
        // file에 입력되는 파일 정보 입력
        for(int i = 0 ; i < K ; ++i){
            cin >> temp;
            file.push_back(temp);
        }
        
        while(file.size() != 1){
            min_f = *min_element(file.begin(), file.end());
            file.erase(min_element(file.begin(), file.end()));
            
            min_s = *min_element(file.begin(), file.end());
            file.erase(min_element(file.begin(), file.end()));
            
            int sum = min_f + min_s;
            
            answer += sum;
            
            file.push_back(sum);
            
        }
        
        cout << answer << endl;
        answer = 0;
        file.pop_back();
    }
}

