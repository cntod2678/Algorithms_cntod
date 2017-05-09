//
//  10971.cpp
//  Session0409
//
//  Created by 최동진 on 2017. 4. 10..
//  Copyright © 2017년 최동진. All rights reserved.
//


#include <iostream>
#include <string.h>
using namespace std;

#define INF 10000000

int N;
int W[20][20];
bool visited[20];
int ans = INF;

void tsp(int node, int costSum, int count) {
    if(N == count) {
        if(W[node][1] != 0)
            ans = min(costSum + W[node][1], ans);
    }
    
    visited[node] = true;
    for(int i = 1; i <= N; i++) {
        if(!visited[i] && W[node][i] != 0) {
            tsp(i, costSum+W[node][i], count + 1);
        }
    }
    visited[node] = false;
}

int main() {
    cin >> N;
    
    memset(W, 0, sizeof(W));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> W[i][j];
        }
    }
    
    tsp(1,0,1);
    
    cout << ans << "\n";
    
    return 0;
}

