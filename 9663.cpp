//
//  9663.cpp
//  Session0412
//
//  Created by 최동진 on 2017. 4. 12..
//  Copyright © 2017년 최동진. All rights reserved.
//


#include <iostream>
#include <string.h>
using namespace std;

int N;
bool chk[16][16];
unsigned long long ans = 0;

void dfs(int x, int y) {
    bool possible = true;
    for(int i = 1; i < y; i++) {
        if(chk[i][x])
            possible = false;
    }
    if(!possible)
        return;
    
    for(int i = 1; i < y; i++) {
        if((y-i >= 1 && x-i >= 1))  {
            if(chk[y-i][x-i])
                possible = false;
        }
        if(y-i >= 1 && x+i <= N){
            if(chk[y-i][x+i])
                possible = false;
        }
    }
    
    if(!possible)
        return;
    
    if(y == N) {
        ans++;
        return;
    }
    
    y++;
    for(int i = 1; i <= N; i++) {
        chk[y][i] = true;
        dfs(i, y);
        chk[y][i] = false;
    }

}

int main () {
    cin >> N;
    memset(chk, false, sizeof(chk));
    dfs(0, 0);

    cout << ans <<"\n";
    
    return 0;
}

