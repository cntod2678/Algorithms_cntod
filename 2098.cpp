//
//  2098.cpp
//  Session0409
//
//  Created by 최동진 on 2017. 4. 9..
//  Copyright © 2017년 최동진. All rights reserved.
//
//  외판원 순회
//


#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define INF 10000000;

int N;
int W[20][20];
int dp[20][1<<17];
int ans = INF;


int tsp(int node, int visited) {
    if(visited == ((1 << N) -1)) {
        if(W[node][1] != 0)
            return W[node][1];
    }
    
    int &ret = dp[node][visited];
    
    if(ret != 0)
        return ret;
    
    ret = INF;
    
    for(int i = 1; i <= N; i++) {
        if (!(visited & (1 << (i-1))) && W[node][i] != 0 ) {
            ret = min(ret, W[node][i] + tsp(i, visited | (1 << (i-1))));
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
    
    ans = tsp(1,1);
    cout << ans <<"\n";
    
    return 0;
}
