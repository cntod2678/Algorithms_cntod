//
//  11276.cpp
//  Session0409
//
//  Created by 최동진 on 2017. 4. 10..
//  Copyright © 2017년 최동진. All rights reserved.
//
//  2xN 타일링
//

#include <iostream>
using namespace std;

int divi = 10007;
int dp[1001];
int N;

int main() {
    dp[1] = 1;
    dp[2] = 2;
    
    cin >> N;
    
    for(int i = 3; i <= N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    cout << dp[N]%divi << "\n";
    return 0;
}
