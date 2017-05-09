//
//  1526.cpp
//  Session0409
//
//  Created by 최동진 on 2017. 4. 10..
//  Copyright © 2017년 최동진. All rights reserved.
//

/* 비트연산자 이용해서 푼 코드 */

#include <iostream>
using namespace std;

#define MOD 1000000000

int N, ans;
int dp[105][10][1<<10];

int func (int idx, int val, int bit) {
    if(dp[idx][val][bit])
        return dp[idx][val][bit];
    
    if(idx == N)
        if(bit == (1 << 10) -1 ) {
            return 1;
        }
        else {
            return 0;
        }
    
    int res = 0;
    
    if(val + 1 < 10)
        res += func(idx+1, val+1, bit | 1 << (val+1));
    if(val - 1 >= 0)
        res += func(idx+1, val-1, bit | 1 << (val-1));
    
    res %= MOD;
    return dp[idx][val][bit] = res;
}

int main() {
    cin >> N;
    
    for(int i = 1; i <= 9; i++) {
        ans += func(1, i, 1 << i);
        ans %= MOD;
    }
    
    cout << ans << "\n";
    
    return 0;
}

/*
 내가 푼 코드
 
#include <iostream>
#include <string.h>
using namespace std;

int N;
int divisor = 1000000000;

unsigned long long dp[101];

int main() {
    cin >> N;
    
    memset(dp, 0, sizeof(dp));
    
    dp[10] = 1;
    dp[11] = 2;
    
    for(int i = 12; i <= N; i++) {
        if(i%2 == 0) {
            //temp = (i-10) * 9 + (i-10)/2*2;
            dp[i] = (dp[i-2]*(2*4+3*7))%divisor;
        }
        else {
            int temp = i - 10 - 1;
            dp[i] = (dp[i-2]*(2*1+3*10)) %divisor;
        }
    }
    unsigned long long sum = 0;
    for(int i = 1; i <= 40; i++) {
        sum += dp[i];
        sum %= divisor;
    }
    
    cout << sum%divisor << "\n";
    
    cout << dp[N]%divisor <<"\n";
    
    return 0;
}

*/




