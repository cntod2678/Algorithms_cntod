//
//  2098_2.cpp
//  Session0409
//
//  Created by 최동진 on 2017. 4. 10..
//  Copyright © 2017년 최동진. All rights reserved.
//


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 10000000

int N;
int W[20][20];
int dp[20][1<<17];

int tsp(int node, int visit) {
    if(visit == (1 << N)-1) {
        if(W[node][1] != 0)
            return W[node][1];
    }

    int &ret = dp[node][visit];
    
    if(ret != 0)
        return ret;
    
    ret = INF;
    for(int i = 1; i <= N; i++) {
        if(!(visit & (1 << (i-1))) && W[node][i] != 0) {
            ret = min(ret, W[node][i] + tsp(i, visit | (1<<(i-1))));
        }
    }
    
    return ret;
}

int main() {
    cin >> N;
    
    memset(W, 0, sizeof(W));
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> W[i][j];
        }
    }
    int ans = 0;
    ans = tsp(1,1);
    
    cout << ans <<"\n";
    
    return 0;
}
