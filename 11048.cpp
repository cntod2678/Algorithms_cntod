//
//  11048.cpp
//  Session0411
//
//  Created by 최동진 on 2017. 4. 11..
//  Copyright © 2017년 최동진. All rights reserved.
//
//  이동하기
//


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][1001];


int tripleMax(int a, int b, int c) {
    int tempMax = max(a, b);
    tempMax = max(tempMax, c);
    return tempMax;
}

int main() {
    cin >> N >> M;
    
    memset(dp,0, sizeof(dp));
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp[1][1] = arr[1][1];
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = tripleMax(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
        }
    }
    
    cout << dp[N][M] << "\n";
    
    return 0;
}
