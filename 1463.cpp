//
//  1463.cpp
//  Session0409
//
//  Created by 최동진 on 2017. 4. 10..
//  Copyright © 2017년 최동진. All rights reserved.
//
//  1로 만들기
//


#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define INF 100000001

int N;
int dp[1000001];
queue<int> q;

int main() {
    cin >> N;
    if(N == 1) {
        cout << 0 << "\n";
        return 0;
    }
        
    
    q.push(N);
    
    memset(dp, INF, sizeof(dp));
    dp[N] = 0;
    
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        
        if(temp%3 == 0) {
            if(dp[temp/3] > dp[temp] + 1) {
                dp[temp/3] = dp[temp]+1;
                q.push(temp/3);
            }
        }
        
        if(temp%2 == 0) {
            if(dp[temp/2] > dp[temp] + 1) {
                dp[temp/2] = dp[temp] + 1;
                q.push(temp/2);
            }
        }
        
        if(temp-1 >= 1) {
            if (dp[temp-1] > dp[temp] + 1) {
                dp[temp-1] = dp[temp] + 1;
                q.push(temp-1);
            }
        }
    }
    
    cout << dp[1] << "\n";
    
    return 0;
}
